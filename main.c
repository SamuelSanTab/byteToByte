#include <stdio.h>
#include "byteReader.h"

int main(int argv, char* arg[]){
    FILE *file = NULL;
    ByteFile *byteFile = NULL;

    if (argv < 2) {
        printf("Faltan argumentos\n");
        return 0;
    }

    file = fopen(arg[1], "rb");
    if (file == NULL){
        printf("Error al abrir el archivo\n");
        return 1;
    }    


    byteFile = initByteFile(file);
    fclose(file);
    if (byteFile == NULL){
        printf("Error al reservar memoria\n");
    }

    printByteFile(byteFile);
    freeByteFile(byteFile);
    return 0;
}
