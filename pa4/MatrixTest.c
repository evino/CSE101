//-----------------------------------------------------------------------------
//  MatrixTest.c 
//  A test client for the Matrix ADT built off MatrixClient.c
//-----------------------------------------------------------------------------
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"Matrix.h"

int main(){
    int n = 50;
    //int n=100000;
    Matrix A = newMatrix(n);
    Matrix B = newMatrix(n);
    //Matrix C, D, E, F, G, H;
    printf("Matrices made\n");

    changeEntry(A, 1,1,1); changeEntry(B, 1,1,1);
    changeEntry(A, 1,2,2); changeEntry(B, 1,2,0);
    changeEntry(A, 1,3,3); changeEntry(B, 1,3,1);
    changeEntry(A, 2,1,4); changeEntry(B, 2,1,0);
    changeEntry(A, 2,2,5); changeEntry(B, 2,2,1);
    changeEntry(A, 2,3,6); changeEntry(B, 2,3,0);
    changeEntry(A, 3,1,7); changeEntry(B, 3,1,1);
    changeEntry(A, 3,2,8); changeEntry(B, 3,2,1);
    changeEntry(A, 3,3,9); changeEntry(B, 3,3,1);
    
    printf("Changed entries\n");
    /*

    printf("%d\n", NNZ(A));
    printMatrix(stdout, A);
    printf("\n");

    printf("%d\n", NNZ(B));
    printMatrix(stdout, B);
    printf("\n");

    C = scalarMult(1.5, A);
    printf("%d\n", NNZ(C));
    printMatrix(stdout, C);
    printf("\n");

    D = sum(A, B);
    printf("%d\n", NNZ(D));
    printMatrix(stdout, D);
    printf("\n");

    E = diff(A, A);
    printf("%d\n", NNZ(E));
    printMatrix(stdout, E);
    printf("\n");

    F = transpose(B);
    printf("%d\n", NNZ(F));
    printMatrix(stdout, F);
    printf("\n");

    G = product(B, B);
    printf("%d\n", NNZ(G));
    printMatrix(stdout, G);
    printf("\n");

    H = copy(A);
    printf("%d\n", NNZ(H));
    printMatrix(stdout, H);
    printf("\n");

    printf("%s\n", equals(A, H)?"true":"false" );
    printf("%s\n", equals(A, B)?"true":"false" );
    printf("%s\n", equals(A, A)?"true":"false" );

    makeZero(A);
    printf("%d\n", NNZ(A));
    printMatrix(stdout, A);
    */

    Matrix C;
    C = copy(A);
    printf("Printing Matrix A\n");
    printMatrix(stdout, A);
    printMatrix(stdout, B);
    printMatrix(stdout, C);

    Matrix T;
    T = transpose(A);
    printf("Transpose of A:\n");
    printMatrix(stdout, T);

    printf("Calling makeZero on B\n");
    makeZero(B);
    printMatrix(stdout, B);

    Matrix S;
    
    S = scalarMult(3, A);
    printf("Scalar S:\n");
    printMatrix(stdout, S);

    printf("Going to multiply A and B\n");
    Matrix P = product(A,C);
    printMatrix(stdout, P);
    printf("Matrix P should have been printed\n");

    printf("About to call free");

    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&C);
    freeMatrix(&T);
    freeMatrix(&S);

    printf("Matrices A & B freed\n");

    /*
    freeMatrix(&C);
    freeMatrix(&D);
    freeMatrix(&E);
    freeMatrix(&F);
    freeMatrix(&G);
    freeMatrix(&H);
    */

    return EXIT_SUCCESS;
    }

    /*
    Output of this program:
    9
    1: (1, 1.0) (2, 2.0) (3, 3.0)
    2: (1, 4.0) (2, 5.0) (3, 6.0)
    3: (1, 7.0) (2, 8.0) (3, 9.0)

    6
    1: (1, 1.0) (3, 1.0)
    2: (2, 1.0)
    3: (1, 1.0) (2, 1.0) (3, 1.0)

    9
    1: (1, 1.5) (2, 3.0) (3, 4.5)
    2: (1, 6.0) (2, 7.5) (3, 9.0)
    3: (1, 10.5) (2, 12.0) (3, 13.5)

    9
    1: (1, 2.0) (2, 2.0) (3, 4.0)
    2: (1, 4.0) (2, 6.0) (3, 6.0)
    3: (1, 8.0) (2, 9.0) (3, 10.0)

    0

    6
    1: (1, 1.0) (3, 1.0)
    2: (2, 1.0) (3, 1.0)
    3: (1, 1.0) (3, 1.0)

    7
    1: (1, 2.0) (2, 1.0) (3, 2.0)
    2: (2, 1.0)
    3: (1, 2.0) (2, 2.0) (3, 2.0)

    9
    1: (1, 1.0) (2, 2.0) (3, 3.0)
    2: (1, 4.0) (2, 5.0) (3, 6.0)
    3: (1, 7.0) (2, 8.0) (3, 9.0)

    true
    false
    true
    0
    */
