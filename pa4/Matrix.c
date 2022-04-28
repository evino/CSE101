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
    List *listArr;
    int size;
    int NNZ;
  //  void *Entry;
} MatrixObj;

// Entry constructor
Entry newEntry(int col, int val) {
    Entry E = malloc(sizeof(EntryObj));
    E->column = col;
    E->value = val;
    return E;
}

Matrix newMatrix(int n) {
    if (n <= 0) {
        printf("Matrix Error: Invalid Matrix size\n");
        exit(EXIT_FAILURE);
    }
    Matrix M;
    M = malloc(sizeof(MatrixObj));
    M->listArr = malloc((n + 1) * sizeof(List));
    M->size = n;
    M->NNZ = 0;

    for (int i = 1; i < n + 1; i++) {
        M->listArr[i] = newList();
    }
    return M;
}

void freeMatrix(Matrix *pM) {
    List pL;
    if (pM != NULL && *pM != NULL) {
        //int s = size(*pM);
        int s = (*pM)->size;
        for (int i = 1; i <= s; i++) {
            pL = (*pM)->listArr[i];
            freeList(&pL);
        }
        free((*pM)->listArr);
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


// Manipulation procedures

void changeEntry(Matrix M, int i, int j, double x) {
    if (M == NULL) {
        printf("Matrix Error: Calling changeEntry() on NULL Matrix reference\n");
        exit(EXIT_FAILURE);
    }
    if (!(1 <= i && i<= M->size)) {
        printf("Matrix Error: Calling changeEntry() on out of bounds row\n");
        exit(EXIT_FAILURE);
    }
    if (!(1 <= j && j <= M->size)) {
        printf("Matrix Error: Calling changEntry() on out of bounds column\n");
        exit(EXIT_FAILURE);
    }

    moveFront(M->listArr[i]);
    printf("DB1\n");
    while (index(M->listArr[i]) != -1) {
        printf("DB1.5\n");

        Entry *current = (Entry*) get(M->listArr[i]);
        printf("After making curent!!!!!!!\n");
        printf("Current column is %d\n", (*current)->column);
        if ((*current)->column == j) {
            if (x == 0) {
                delete(M->listArr[i]);
                (M->NNZ)--;
            } else {
                printf("About to set current val\n");
                (*current)->value = x;
                printf("Current value is %lf\n", (*current)->value);
            }
            printf("DB2\n");
            return;
        } else if ((*current)->column > j) {
            printf("about to insert before\n");
            insertBefore(M->listArr[i], newEntry(j, x));
            (M->NNZ)++;
            printf("DB3\n");
            return;
        }
        printf("DB4\n");
        moveNext(M->listArr[i]);
    }
    if (x != 0) {
        append(M->listArr[i], newEntry(j, x));
    }

    return;
}

void printMatrix(FILE *out, Matrix M) {
    if (M == NULL) {
        printf("Matrix Error: Calling printMatrix() on NULL Matrix reference\n");
        exit(EXIT_FAILURE);
    }
    Entry E;
    for (int i = 1; i <= M->size; i++) {
        moveFront(M->listArr[i]);

        if (length(M->listArr[i]) > 0) {
            fprintf(out, "%d: ", i);
        }
        while (index(M->listArr[i]) != -1) {
            E = get(M->listArr[i]);
            fprintf(out, "(%d, %lf)\n", E->column, E->value);
            moveNext(M->listArr[i]);
        }
    }
    return;
}
