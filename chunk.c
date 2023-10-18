#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void initChunk(Chunk* chunk) {
  chunk->count = 0;
  chunk->capacity = 0;
  chunk->code = NULL;
  chunk->lines = NULL;
  initValueArray(&chunk->constants);
} /* Array chunk inizializzato a vuoto */

void freeChunk(Chunk* chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity); /* Gestito da memory.h*/
    FREE_ARRAY(int, chunk->lines, chunk->capacity);
    freeValueArray(&chunk->constants);
    initChunk(chunk); /* Metti tutto a zero*/
}

void writeChunk(Chunk* chunk, uint8_t byte, int line) {
    if (chunk->capacity < chunk->count + 1) { /*Se la capacity non e` abbastanza*/
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity); /*Cresci la nuova capacity*/
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity); /*Copia in un nuovo array e aggiungi il nuovo elemento*/
        chunk->lines = GROW_ARRAY(int, chunk->lines, oldCapacity, chunk->capacity);
    }

    chunk->code[chunk->count] = byte; /*array[index "n"], funziona anche con i puntatori. "Voglio l`elemento n"*/
    chunk->lines[chunk->count] = line;
    chunk->count++; 
} /* Fai crescere il chunk quando pieno*/

int addConstant(Chunk* chunk, Value value) {
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1;
}