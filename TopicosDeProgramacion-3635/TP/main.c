#include "tpNuevo.h"
///32398 REGISTROS

int main()
{
    FILE* dataFilePointer;
    FILE* resultsFilePointer;
    int endianness;
    int errorType;

    endianness = checkEndianness();


    if(         UNKNOWN_FORMAT == endianness            )
    {
        return UNKNOWN_FORMAT_ERR;
    }

    if(         !openFile(&dataFilePointer, "HKTMST.bin", "rb")         )
    {
        return OPEN_FILE_ERR;
    }

    if(         !openFile(&resultsFilePointer, "results.txt", "wt")         )
    {
        fclose(resultsFilePointer);
        return OPEN_FILE_ERR;
    }

    if(         !checkSizeOfFile(dataFilePointer)           )
    {
        fclose(dataFilePointer);
        fclose(resultsFilePointer);
        return FILE_FORMAT_ERR;
    }

    if(         OK != (errorType = traverseFileAndRecordResults(dataFilePointer, resultsFilePointer, endianness))          )
    {
        fclose(dataFilePointer);
        fclose(resultsFilePointer);
        return errorType;
    }

    fclose(dataFilePointer);
    fclose(resultsFilePointer);
    return 0;
}
