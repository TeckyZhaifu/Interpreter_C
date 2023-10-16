#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

#define GROW_CAPACITY(capacity) \ 
    ((capacity) < 8 ? 8 : (capacity) * 2)
/* Ci serve sapere la nuova capacita` per far crescere l`array per i nuovi elementi*/
/* Raddoppia capacita`, se e` piccola inizia con 8 bits*/
/* Non capisco questa sintassi, vedere se funziona */

#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), \
    sizeof(type) * (newCount))
    /* Fai l`array di dim. corrette in base al tipo con la capacita` calcolata prima*/
    /* reallocate sara` importante per la gestione della memoria*/

#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0) /*Newsize a 0*/

void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif