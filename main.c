#include <stdio.h>
#include <stdlib.h>

int main(int argv, char* arg[]){
    FILE *file = NULL;
    long handle = -1;
    unsigned char* buffer = NULL;

    if (argv < 2) {
        printf("Faltan argumentos\n");
        return 0;
    }

    file = fopen(arg[1], "rb");
    if (file == NULL){
        printf("Error al abrir el archivo\n");
        return 1;
    }    
    
    fseek(file, 0, SEEK_END);
    handle = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = calloc(sizeof(char), handle + 1);
    if (buffer == NULL){
        printf("Error al reservar memoria\n");
    }
    fread(buffer, handle, handle, file);

    printf("               ");
    for (int i = 0; i < 16; i++){
        printf("%02x ", i);
    }

    for (int i = 0; i < handle; i++){
        if (i%16 == 0){
            printf("\n");
            printf("%010x     ", i);
        }
        printf("%02x ", buffer[i]);
    }
    printf("\n");
    printf("Size: %ld\n", handle);
    fclose(file);
    free(buffer);
    return 0;
}
