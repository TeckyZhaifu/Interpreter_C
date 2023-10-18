#ifndef clox_value_h
#define clox_value_h

#include "common.h"

typedef double Value; /*Valori con virgola*/

typedef struct {
    int capacity;
    int count;
    Value* values; /*Costanti*/
} ValueArray; /*Un`array dinamico per immagazzinare i valori*/

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);

#endif