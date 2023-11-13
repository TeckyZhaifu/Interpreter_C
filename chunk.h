#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

/*
OpCode controlla il tipo di comando, cioe' l'operazione, l'equivalente dell'opcode in Assembly
Sara' cruciale per la VM (Macchina Virtuale) siccome dettera' l'ordine dei comandi.
OP_CONSTANT produrra' una costante quando necessario.
OP_RETURN sara' usato per ritonare da una determinate funzione
*/
typedef enum {
    OP_CONSTANT,
    OP_RETURN,
} OpCode;

/* 
Capitolo 14, Challenge 1: ottimizza lo spazio utilizzato dal debug per ottenere il byte e la linea di comando
Modifichiamo il codice a tal modo che il contatore delle linee di comando per la memoria non e' uguale a quello che conta i chunks.
La compressione avverra' quando s'incontrano operazioni nella stessa linea:
mentre chunk aumenta ad ogni istruzione, LineStart terra' il suo valore finche' non incontra un accapo.
A quel punto incrementera' ed indichera' una nuova linea. 
*/
typedef struct {
    int offset;
    int line;
} LineStart;

/*
Definiamo il Chunk che sara' il nostro contenitore delle istruzioni.
Dentro di essa saranno contenuti anche i dati necessari al debug.
*/
typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    ValueArray constants;
    /*Dati debug*/
    int lineCount;
    int lineCapacity;
    LineStart* lines;
} Chunk;

void initChunk (Chunk* chunk);
void freeChunk (Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);

#endif