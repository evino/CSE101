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
    while (index(M->listArr[i]) != -1) {
        Entry E = get(M->listArr[i]);
        if (E->column == j) {
            if (x == 0) {
                delete(M->listArr[i]);
                (M->NNZ)--;
            } else {
                E->value = x;
            }
            return;
        } else if (E->column > j) {
            insertBefore(M->listArr[i], newEntry(j, x));
            (M->NNZ)++;
            return;
        }
        moveNext(M->listArr[i]);
    }
    if (x != 0) {
        append(M->listArr[i], newEntry(j, x));
    }

    return;
}


void makeZero(Matrix M) {
    Entry E;
    for (int i =1 ; i <= M->size; i++) {
        moveFront(M->listArr[i]);
        while (index(M->listArr[i]) != -1) {
            E = get(M->listArr[i]);
            freeEntry(&E);
            moveNext(M->listArr[i]);
        }

        // clear to remove garbage in list??
        clear(M->listArr[i]);
    }
    M->NNZ = 0;
    return;
}



// Matrix Arithmetic operations
// copy()
// Returns a reference to a new Matrix object having the same entries as A.
Matrix copy(Matrix A) {
    Matrix M = newMatrix(A->size);
    for (int i = 1; i <= A->size; i++) {
        moveFront(A->listArr[i]);
        while (index(A->listArr[i]) != -1) {
            append(M->listArr[i], get(A->listArr[i]));
            moveNext(A->listArr[i]);
        }
    }

    return M;
}

Matrix transpose(Matrix A) {
    Matrix M = newMatrix(A->size);
    Entry E;
    int j;
    for (int i = 1; i <= A->size; i++) {
        moveFront(A->listArr[i]);
        while (index(A->listArr[i]) != -1) {
            E = get(A->listArr[i]);
            j = E->column;
            changeEntry(M, j, i, E->value);
            moveNext(A->listArr[i]);
        }
    }

    return M;
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
            fprintf(out, "(%d, %lf) ", E->column, E->value);
            moveNext(M->listArr[i]);
        }
        if (length(M->listArr[i]) > 0)
            fprintf(out, "\n");
    }
    return;
}
