#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
    OP_CONSTANT, /*Produci costante da un,byte operando, nel momento giusto*/
    OP_RETURN, /* Comando ritorna dal sottoprogramma, utilizzato dalla macch. virt. */
} OpCode; /* Variabile codice di controllo delle istruzioni*/

typedef struct {
    int count; /*Contatore*/
    int capacity; /*Capacita memoria*/
    uint8_t* code; /* Un instruzione da 8 bits */
    int* lines; /*Useremo per capire la linea problematica in caso di errori del processo*/
    ValueArray constants; /*Per i valori costanti*/
} Chunk; /* Array dinamico che contiene le istruzioni*/

void initChunk (Chunk* chunk);
void freeChunk (Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);

#endif