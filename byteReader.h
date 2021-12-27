#ifndef BYTEREADER
#define BYTEREADER

#include <stdio.h>
typedef struct _byteFile ByteFile;

ByteFile* initByteFile(FILE* file);

void printByteFile(ByteFile* file);

void freeByteFile(ByteFile* file);

#endif