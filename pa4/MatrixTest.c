//simplified test to figure out segfault from changeEntry_getNNZ

#include "Matrix.h"

int main(int argc, char **argv) {
    Matrix A = newMatrix(10);
    Matrix B = newMatrix(10);

    changeEntry(A, 1, 1, -4);
    changeEntry(A, 1, 2, -2);
    changeEntry(A, 1, 3, 0);
    changeEntry(A, 2, 5, 4);
    changeEntry(A, 2, 1, -2);
    changeEntry(A, 3, 1, 2);
    changeEntry(A, 2, 2, -2);
    changeEntry(A, 3, 3, 0);
    
    printf("A's NNZ is %d\n", NNZ(A));

    Matrix d = diff(A, A);

    printf("D's NNZ now is %d\n", NNZ(d));


    changeEntry(B, 1, 1, -4);
    changeEntry(B, 1, 2, 0);
    changeEntry(B, 2, 1, 0);
    changeEntry(B, 2, 2, -2);
    changeEntry(B, 2, 4, 2);
    changeEntry(B, 3, 1, 2);
    changeEntry(B, 3, 2, 2);
    changeEntry(B, 7, 8, 5);

    Matrix z = diff(A, B);

    printf("Z's nnz is %d\n", NNZ(z));

    return 0;
  }