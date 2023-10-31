#include "tp.h"

int openFile(FILE** filePointer, const char* fileName, const char* mode)
{
    *filePointer = fopen(fileName, mode);

    if(!*filePointer)
    {
        perror("Oops! Something went wrong");
        return OPEN_FILE_ERR;
    }

    return OK;
}

void reverseRegisterField(void* reg, size_t fieldSize)
{
    void* startOfReg = reg;
    void* endOfReg = reg + fieldSize - 1;
    char aux;

    while (startOfReg < endOfReg)
    {
        aux = *(char*)startOfReg;
        *(char*)startOfReg = *(char*)endOfReg;
        *(char*)endOfReg = aux;

        startOfReg++;
        endOfReg--;
    }
}
int checkEndianness()
{
    unsigned int value = 0x12345678;
    unsigned char *ptr = (unsigned char *)&value;

    if (*ptr == 0x78)
        return LITTLE_ENDIAN;
    if (*ptr == 0x12)
        return BIG_ENDIAN;
    return UNKNOWN_FORMAT;
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

    fprintf(resultsFilePointer, "Voltage;Datetime\n");

    fread(dataRegister, REGISTER_SIZE, 1, dataFilePointer);
    while(          !feof(dataFilePointer)           )
    {
        if(         LITTLE_ENDIAN == endianness         )
        {
            reverseRegisterField(dataRegister + PCS + V_BAT_AVERAGE_OFFSET, sizeof(vBatAverage));
            memcpy(&vBatAverage, dataRegister + PCS + V_BAT_AVERAGE_OFFSET, sizeof(vBatAverage));
            reverseRegisterField(dataRegister + CDH + OBT_OFFSET, sizeof(dateTime));
            memcpy(&dateTime, dataRegister + CDH + OBT_OFFSET, sizeof(dateTime));

            if(         !(timeInfo = getDatetime(&dateTime))            )
            {
                perror("Error converting to time");
                return TIME_ERR;
            }
        }
        else
        {
            memcpy(&vBatAverage, dataRegister + PCS + V_BAT_AVERAGE_OFFSET, sizeof(vBatAverage));
            memcpy(&dateTime, dataRegister + CDH + OBT_OFFSET, sizeof(dateTime));
            if(         !(timeInfo = getDatetime(&dateTime))            )
            {
                perror("Error converting to time");
                return TIME_ERR;
            }
        }
        volts = FIX_RAW(vBatAverage);
        fprintf(resultsFilePointer, "%lf;%s", volts, asctime(timeInfo));//Asctime convierte un struct tm a una cadena con formato "Dom Mmm dd hh:mm:ss aaaa\n"
        fread(dataRegister, REGISTER_SIZE, 1, dataFilePointer);
    }

    free(dataRegister);

    return OK;
}

struct tm* getDatetime(const int32_t* dateTime)
{
    time_t time;

    time = (time_t)(*dateTime);
    return localtime(&time);//Convierte unixtimestamp a un struct tm
}
