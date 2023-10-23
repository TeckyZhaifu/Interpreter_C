#include <stdio.h>
#include "common.h"
#include "debug.h"
#include "vm.h"

VM vm;

static void resetStack() {
    vm.stackTop = vm.stack;
}

void initVM() {
    resetStack();
}

void freeVM() {

}

void push(Value value) {
    *vm.stackTop = value;
    vm.stackTop++;
}

Value pop() {
    vm.stackTop--; /*Ricorda che stackTop punta dopo l`ultimo elemento*/
    return *vm.stackTop;
} /*Non si trova necessita a rimuovere l`elemento, il puntatore puntandolo lo rende "vuoto"*/

static InterpretResult run() {
#define READ_BYTE() (*vm.ip++) 
/*ip indica sempre il prossimo byte utilizzabile e aumenta appena l`opcode viene letta
ricordando che il primo byte si tratta dell`opcode e fare il decoding o dispatch (decifrarlo)*/
/*L`efficienza si migliora solo con estensioni non-standard o con assembly (progetto futuro)*/

#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
/*Legge il prossimo byte del bytecode e compara il numero ottenuto con Value costante del chunk*/
    
    for (;;) {
#ifdef DEBUG_TRACE_EXECUTION
    printf("        ");
    for(Value* slot = vm.stack; slot < vm.stackTop; slot++) {
        printf("[ ");
        printValue(*slot);
        printf(" ]");
    }
    printf("\n");
    disassembleInstruction (vm.chunk, (int)(vm.ip - vm.chunk->code));
#endif
        uint8_t instruction;
        switch (instruction = READ_BYTE()) {
            case OP_CONSTANT: {
                Value constant = READ_CONSTANT();
                push(constant);
                break;
            }
            case OP_RETURN: {
                printValue(pop());
                printf("\n");
                return INTERPRET_OK;
            }
        }
    }

#undef READ_BYTE
#undef READ_CONSTANT
}

InterpretResult interpret(Chunk* chunk) {
    vm.chunk = chunk; /*Deposita informazioni*/
    vm.ip = vm.chunk->code; /*Locazione dell`istruzione*/
    return run(); /*Funzione per eseguire il bytecode*/
}