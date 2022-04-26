/*
 * Evin Odisho
 * edodisho
 * pa4
 * Matrix.c
*/

#include "Matrix.h"

// Private, non-exported type
typedef struct EntryObj *Entry;

typedef struct EntryObj {
    int column;
    double value;
} EntryObj;

typedef struct MatrixObj {
    List *entryList;
    int size;
    int NNZ;
    void *Entry;
} MatrixObj;

// Entry constructor
Entry newEntry(void*) {
    Entry E = malloc(sizeof(void*));
    E->column = NULL;
    E->value = NULL;
    return E;
}

void freeEntry (Entry *pE) {
    if (pE != NULL && *pE != NULL) {
        free(*pE);
        *pE = NULL;
    }
    return;
}
