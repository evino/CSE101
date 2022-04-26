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
  //  void *Entry;
} MatrixObj;

// Entry constructor
Entry newEntry(void*) {
    Entry E = malloc(sizeof(void*));
    E->column = NULL;
    E->value = NULL;
    return E;
}

Matrix newMatrix(int n) {
    Matrix M;
    M->entryList = malloc((n + 1) * sizeof(List));
    M->size = n;
    M->NNZ = 0;
    return M;
}

void freeMatrix(Matrix *pM) {
    List pL;
    if (pM != NULL && *pM != NULL) {
        int s = size(*pM);
        for (int i = 1; i <= s; i++) {
            pL = (*pM)->entryList[i];
            freeList(&pL);
        }
        free(*pM);
        *pM = NULL;
    }
    return;
}

void freeEntry (Entry *pE) {
    if (pE != NULL && *pE != NULL) {
        free(*pE);
        *pE = NULL;
    }
    return;
}
