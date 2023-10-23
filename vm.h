#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "value.h"

#define STACK_MAX 256 /*Rimanda a possibili stack overflow*/

/*La VM si basera` sullo stack che non e` veloce come il "just-in-time compilation"*/

typedef struct {
    Chunk* chunk;
    uint8_t* ip; /*Locazione dell`istruzione, ip sta per instruction pointer, equivalente del program counter*/
    Value stack[STACK_MAX];
    Value* stackTop; /*Puntantore che punta all`elemento dell`array che e` dopo l`elemento col valore piu` alto d`indice*/
    /*La implementiamo cosicche l`indice 0 indichera array vuoto*/
} VM;

typedef enum { /*enum rappresenta un gruppo di costanti*/
    INTERPRET_OK, /*Utilizzare maiuscolo sempre per le costanti*/
    INTERPRET_COMPILE_ERROR,
    INTERPREST_RUNTIME_ERROR /*Nota: nessuna virgola per l`ultimo elemento*/
} InterpretResult;

void initVm();
void freeVM();
InterpretResult interpret(Chunk* chunk);
void push (Value value); /*Nuovo valore nella stack*/
Value pop(); /*Rimuovi valore nella stack*/

#endif