#include "tpNuevo.h"

int openFile(FILE** filePointer, const char* fileName, const char* mode)
{
    *filePointer = fopen(fileName, mode);

    if(!*filePointer)
    {
        perror("Oops! Something wrong occurred.");
        return OPEN_FILE_ERR;
    }

    return OK;
}

void reverseRegister(void* reg, size_t regSize)
{
    void* startOfReg = reg;
    void* endOfReg = reg + regSize - 1;
    char aux;

    while (startOfReg < endOfReg)
    {
        aux = *(char*)startOfReg;
        *(char*)startOfReg = *(char*)endOfReg;
        *(char*)endOfReg = aux;

        startOfReg = (char*)startOfReg + 1;
        endOfReg = (char*)endOfReg - 1;
    }
}
int checkEndianness()
{
    unsigned int value = 0x12345678; // Valor conocido
    unsigned char *ptr = (unsigned char *)&value;   ///char* para leer 1 byte

    // Si el primer byte es igual al byte más significativo, es little-endian.
    if (*ptr == 0x78)
    {
        return 1; // Little-endian
    }
    // Si el primer byte es igual al byte menos significativo, es big-endian.
    else if (*ptr == 0x12)
        {
            return 0; // Big-endian
        }
        // Si no es ninguno de los dos, el hardware utiliza un formato inusual.
        else
        {
            return -1; // Formato desconocido
        }
}

size_t checkSizeOfFile(FILE* filePointer)
{
    size_t fileSize;

    fseek(filePointer, 0, SEEK_END);
    fileSize = ftell(filePointer);
    rewind(filePointer);

    return (0 !=  (fileSize % REGISTER_SIZE)? false : true);
}

int traverseFileAndRecordResults(FILE* dataFilePointer, FILE* resultsFilePointer, int endianness)
{
    void* dataRegister;
    int16_t vBatAverage;
    double volts;
    int32_t dateTime;
    struct tm* timeInfo;

    dataRegister = malloc( REGISTER_SIZE );

    if(         !dataRegister           )
    {
        perror("There is no memory available");
        return MEM_ERR;
    }

    fprintf(resultsFilePointer,"Voltage;Datetime\n");

    fread(dataRegister, REGISTER_SIZE, 1, dataFilePointer);
    while(          !feof(dataFilePointer)           )
    {
        if(         LITTLE_ENDIAN == endianness         )
        {
            reverseRegister(dataRegister, REGISTER_SIZE);
            memcpy(&vBatAverage, dataRegister + REGISTER_SIZE - PCS - V_BAT_AVERAGE_OFFSET - sizeof(int16_t), 2);
            memcpy(&dateTime, dataRegister + REGISTER_SIZE - CDH - OBT_OFFSET - sizeof(int32_t), 4);///incrementa cada 8 segundos


            if(         !(timeInfo = getDatetime(&dateTime))            )
            {
                perror("Error converting to time");
                return TIME_ERR;
            }
        }
        else
        {
            memcpy(&vBatAverage, dataRegister + PCS + V_BAT_AVERAGE_OFFSET, 2);
            memcpy(&dateTime, dataRegister + CDH + OBT_OFFSET, 4);
        }
        volts = FIX_RAW(vBatAverage);
        fprintf(resultsFilePointer,"%lf;%s", volts, asctime(timeInfo));///DEBE LEER EN HEXA: 0E F5 == 3829 en decimal
        fread(dataRegister, REGISTER_SIZE, 1, dataFilePointer);
    }

    free(dataRegister);

    return OK;
}

struct tm* getDatetime(const int32_t* dateTime)
{
    time_t time;

    time = (time_t)(*dateTime);
    return localtime(&time);
}

/**
YO DI VUELTA TODO EL ARCHIVO, POR LO TANTO, EL OFFSET QUE DEBO HACER ES UTILIZANDO EL COMPLEMENTO DEL OFFSET DEL EJERCICIO
FEDE: COMO TIENE EL ARCHIVO EN BIG, USA EL OFFSET DEL BIG, SOLAMENTE DA VUELTA EL DATO PARA PODER LEERLO
*/
