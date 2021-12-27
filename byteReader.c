#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "byteReader.h"

#define LINE 84
#define ADDRESS "               00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"
#define TOP 127
#define BOTTOM 31
#define HEX 16

 
struct _byteFile {
  unsigned char* buffer;
  long length;
  long size;
};

ByteFile* initByteFile(FILE* file){
    long handle = -1;
    int aux = 0;
    unsigned char* buffer = NULL;
    ByteFile* newByteFile = NULL;

    if (file == NULL){
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    handle = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (handle%HEX != 0){
        aux = HEX - handle%HEX;
    }

    buffer = calloc(sizeof(char), handle + aux);
    if (buffer == NULL){
        printf("Error al reservar memoria\n");
        return NULL;
    }
    fread(buffer, 1, handle, file);

    newByteFile = malloc(sizeof(ByteFile));

    newByteFile->buffer=buffer;
    newByteFile->length=handle + aux;
    newByteFile->size=handle;

    return newByteFile;
}

void printByteFile(ByteFile* file){
    char* line = NULL, byte[4];
    int aux = -1, compLin = -1, i, j;

    if (file == NULL){
        return;
    }

    printf(ADDRESS);
    line = malloc(sizeof(char)*LINE);
    for (i = 0; i < file->length; i+=HEX){
        line[0] = '\0';
        sprintf(line, "%010x     ", i);
        for(j = 0; j < HEX; j++){
            sprintf(byte, "%02x ", file->buffer[i+j]);
            strcat(line, byte);
        }
        
        strcat(line, "    ");
        for(j = 0; j < HEX; j++){
            aux = file->buffer[i+j];
            if (aux > BOTTOM && aux < TOP){
                sprintf(byte, "%c", aux);
            } else {
                sprintf(byte, ".");
            }
            strcat(line, byte);
        }

        printf("%s\n", line);
    }
    free(line);
    printf("Size %ld Bytes\n", file->size);
}


void freeByteFile(ByteFile* file){
    if (file == NULL){
        return;
    }
    free(file->buffer);
    free(file);
}
