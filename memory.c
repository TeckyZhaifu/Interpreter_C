#include <stdlib.h>

#include "memory.h"

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
    if (newSize == 0) {
        free(pointer);
        return NULL;
    } /* Libera memoria se si passa da non 0 a 0*/

    void* result = realloc(pointer, newSize); /* Lasciamo gestire a C stdlib*/
    /* Cerca spazio disp. in mem. dopo, se non c`e alloca un nuovo blocco e copia i contenuti*/
    if (result == NULL) exit(1); /* Se non trova mem. disp.*/
    /* Ferma il processo che e` meglio di dare un puntatore NULL */
    return result;
}