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
Entry newEntry(int col, double val) {
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

void freeEntry(Entry *pE) {
    if (pE != NULL && *pE != NULL) {
        free(*pE);
        *pE = NULL;
    }
    return;
}


// Access functions

int size(Matrix M) {
    if (M == NULL) {
        printf("Matrix Error: Calling size() on NULL Matrix reference\n");
        exit(EXIT_FAILURE);
    }
    return (M->size);
}

int NNZ(Matrix M) {
    if (M == NULL) {
        printf("Matrix Error: Calling NN() on NULL Matrix reference\n");
        exit(EXIT_FAILURE);
    }
    return (M->NNZ);
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
        (M->NNZ)++;
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


Matrix scalarMult(double x, Matrix A) {
    Matrix M;
    M = copy(A);
    if (A == NULL) {
        printf("Matrix Error: Calling scalarMult() on NULL Matrix reference\n");
        exit(EXIT_FAILURE);
    }
    if (x == 0.0) {
        makeZero(M);
    } else {
        Entry E;
        for (int i = 1; i <= M->size; i++) {
            moveFront(M->listArr[i]);
            while (index(M->listArr[i]) != -1) {
                E = get(M->listArr[i]);
                E->value = (E->value * x);
                moveNext(M->listArr[i]);
            }
        }
    }

    return M;
}


double vectorDot(List P, List Q) {
    if (P == NULL || Q == NULL) {
        printf("Matrix Error: Calling vectorDot() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    double val = 0.0;
        
    if (isEmpty(P) || isEmpty(Q)) {
        return val;
    }
    
    moveFront(P);
    moveFront(Q);
    Entry getP;
    Entry getQ;

    while (index(P) != -1 && index(Q) != -1) {
        getP = get(P);
        getQ = get(Q);
        
        
        if (getP->column == getQ->column) {
            val += getP->value * getQ->value;
            moveNext(Q);
            moveNext(P);
        } else if (getP->column < getQ->column) {
            moveNext(P);
        } else if (getP->column > getQ->column) {
            moveNext(Q);
        }
        printf("DB\n");
    }

    return val;
}        

/*
        if (getP->value == 0 && getQ->value) {
            moveNext(P);
            moveNext(Q);
        } else if (getP->column < getQ->column) {
            moveNext(P);
        } else if (getP->column > getQ->column) {
            moveNext(Q);
        } else {
            val += getP->value * getQ->value;
            moveNext(Q);
            moveNext(P);
        }
        */




Matrix product(Matrix A, Matrix B) {
    if (A == NULL || B == NULL) {
        printf("Matrix Error: Calling product() on NULL Matrix reference\n");
        exit(EXIT_FAILURE);
    }

    Matrix M = newMatrix(size(A));
    Matrix T;
    T = transpose(B);
    double val = 0.0;
    
    for (int i = 1; i <= size(A); i++) {
        for (int j = 1; j <= size(T); j++) {
            
            val = vectorDot(A->listArr[i], T->listArr[j]);
            if (val != 0) {
                append(M->listArr[i], newEntry(j, val));
            }
        }
    }
    
    return M;
}


    /*
    double val = 0.0;
    for (int i = 1; i <= M->size; i++) {
        moveFront(M->listArr[i]);
        if (isEmpty(A->listArr[i]) || isEmpty(T->listArr[i])) {
            i++;
            continue;
        }
        while (index(M->listArr[i])) {
            getA = get(A->listArr[i]);
            getT = get(T->listArr[i]);
            if (getA->column < getT->column) {
                moveNext(A->listArr[i]);
            } else if (getA->column > getT->column) {
                moveNext(T->listArr[i]);
            } else {
                val += (getA->value) * (getT->value);

                moveNext(A->listArr[i]);
                moveNext(T->listArr[i]);
                moveNext(M->listArr[i]);
            }
        }
        if (val != 0) {
            printf("Should be doing an append here\n");
            append(M->listArr[i],newEntry(i, val));
            (M->NNZ)++;
        }
    }
    */

    // Rememver to free
 //   return M;

Matrix sum(Matrix A, Matrix B) {
    return A;
}

Matrix diff(Matrix A, Matrix B) {
    return A;
}

int equals(Matrix A, Matrix B) {
    return 1;
}
