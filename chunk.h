#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

typedef enum {
    OP_RETURN, /* Ritorna dal sottoprogramma */
} OpCode; /* Variabile codice di controllo delle istruzioni*/

typedef struct {
    int count;
    int capacity;
    uint8_t* code; /* 8 bits */
} Chunk; /* Array dinamico che contiene le istruzioni*/

void initChunk (Chunk* chunk);

void writeChunk(Chunk* chunk, uint8_t byte);

#endif