#ifndef TP_H_INCLUDED
#define TP_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

#define REGISTER_SIZE 4000

#define LITTLE_ENDIAN 1
#define BIG_ENDIAN 0
#define UNKNOWN_FORMAT -1

#define OK 1
//FILE ERRORS:
#define OPEN_FILE_ERR -1
#define FILE_FORMAT_ERR -2
//MEMORY ERRORS:
#define MEM_ERR -3
//SYSTEM FORMAT ERRORS:
#define UNKNOWN_FORMAT_ERR -4
//TIME ERRORS:
#define TIME_ERR -5

#define CDH 8
#define CDH_SIZE 272

#define MM1 280             /// 8 + 272
#define MM1_SIZE 150

#define MM2 430             ///280+150
#define MM2_SIZE 150

#define ACS 580             ///430+150
#define ACS_SIZE 1024

#define PCS 1604            ///580+1024
#define PCS_SIZE 1024
                            ///1604+1024 = 2628

#define V_BAT_AVERAGE_OFFSET 750
#define OBT_OFFSET  92


#define FIX_RAW(RAW) (RAW * 0.01873128 + (-38.682956))


int openFile(FILE** filePointer, const char* fileName, const char* mode);
int checkEndianness();
void reverseRegisterField(void* reg, size_t regField);
size_t checkSizeOfFile(FILE* filePointer);
int traverseFileAndRecordResults(FILE* dataFilePointer, FILE* resultsFilePointer, int endianness);
struct tm* getDatetime(const int32_t* dateTime);
#endif // TP_H_INCLUDED
