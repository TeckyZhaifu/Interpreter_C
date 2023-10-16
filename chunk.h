#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
    OP_CONSTANT, /*Produci costante da un,byte operando, nel momento giusto*/
    OP_RETURN, /* Ritorna dal sottoprogramma */
} OpCode; /* Variabile codice di controllo delle istruzioni*/

typedef struct {
    int count;
    int capacity;
    uint8_t* code; /* 8 bits */
    int* lines; /*Useremo per capire la linea problematica in caso di errori del processo*/
    ValueArray constants; /*Per i valori costanti*/
} Chunk; /* Array dinamico che contiene le istruzioni*/

void initChunk (Chunk* chunk);
void freeChunk (Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);

#endif