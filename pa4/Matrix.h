/*
 * Evin Odisho
 * edodisho
 * pa4
 * Matrix.h
*/

#include "List.h"

// Exported type
typedef struct MatrixObj* Matrix;

// newMatrix()
// // Returns a reference to a new nXn Matrix object in the zero state.
Matrix newMatrix(int n);

// freeMatrix()
// Frees heap memory associated with *pM, sets *pM to NULL.
void freeMatrix(Matrix* pM);


// Access functions
// size()
// Return the size of square Matrix M.
int size(Matrix M);

// NNZ()
// Return the number of non-zero elements in M.
int NNZ(Matrix M);

// equals()
// Return true (1) if matrices A and B are equal, false (0) otherwise.
int equals(Matrix A, Matrix B);
