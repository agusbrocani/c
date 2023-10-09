#ifndef TP_H_INCLUDED
#define TP_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_REGISTRO 4000

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
                                                            ///FULL RANGE                   ///EXPECTED RANGE       -> SI NO ESTA EN ESE RANGO, INFORMAR ERROR
#define OFFSET_V_BAT_AVERAGE 750            ///0x000 a 0x FFF = 0 a 4095 SIN SIGNO          -> 3165 >= VALUE <= 4093        ///2BYTES DE DATO
#define OFFSET_OBT  92          ///RANGO: UNSIGNED, 4 BYTES DE DATO


#define CORRIGE_RAW(RAW) (RAW*0.01873128+(-38.682956))

#define LI_V 31.5
#define LS_V 32

int abrirArchivo(FILE** pf,const char* nombreArchivo,const char* modo);
int checkEndianness();
void swapRegister(void* registro, size_t tam);


#endif // TP_H_INCLUDED
