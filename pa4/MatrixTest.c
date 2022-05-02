//-----------------------------------------------------------------------------
//  Evin Odisho
//  edodisho
//  pa4
// MatrixTest.c 
//  A test client for the Matrix ADT built off MatrixClient.c
//-----------------------------------------------------------------------------
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"Matrix.h"

int main(){
    int n = 5000;
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
    printf("Printing Matrix A (%d NNZ's)\n", NNZ(A));
    printMatrix(stdout, A);
    printf("Matrix B:\n");
    printMatrix(stdout, B);
    printf("Matrix C:\n");
    printMatrix(stdout, C);

    if (equals(A, C) == 1) {
        printf("A and C are equal\n");
    } else {
        printf("A and C are NOT equal\n");
    }


    Matrix T;
    T = transpose(A);
    printf("Transpose of A:\n");
    printMatrix(stdout, T);

    Matrix Z;
    Z = copy(B);
    printf("Matrix Z is\n");
    printMatrix(stdout, Z);

    printf("Calling makeZero on B\n");
    //makeZero(B);
    printMatrix(stdout, B);

    Matrix S;
    
    S = scalarMult(3, A);
    printf("Scalar S:\n");
    printMatrix(stdout, S);

    printf("Going to multiply A and B\n");
    printf("Matrix A:\n");
    printMatrix(stdout, A);
    printf("Matrix C:\n");
    printMatrix(stdout, C);

    printf("Product of A & C:\n");
    Matrix P = product(A,C);
    printMatrix(stdout, P);
    printf("Matrix P should have been printed\n");

    
    printf("Adding A & Z\n");
    printf("A:\n");
    printMatrix(stdout, A);
    printf("Z:\n");
    printMatrix(stdout, Z);
    Matrix sumTest;
    sumTest = sum(A, Z);
    printf("Sum is:\n");
    printMatrix(stdout, sumTest);


    printf("Subtraction is:\n");
    Matrix subTest;
    subTest = diff(A, Z);
    printf("Sub is:\n");
    printMatrix(stdout, subTest);
    
    
    printf("About to call free");

    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&C);
    freeMatrix(&T);
    freeMatrix(&S);

    printf("Matrices A & B freed\n");


    // Debug stuff


    changeEntry(A, 1, 1, -4);
    changeEntry(A, 1, 2, -2);
    changeEntry(A, 1, 3, 0);
    changeEntry(A, 2, 5, 4);
    changeEntry(A, 2, 1, -2);
    changeEntry(A, 3, 1, 2);
    changeEntry(A, 2, 2, -2);
    changeEntry(A, 3, 3, 0);
    
    printf("A's NNZ is %d\n", NNZ(A));
    printMatrix(stdout, A);
    
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

    Matrix a1 = newMatrix(15);
    Matrix a2 = newMatrix(15);

    freeMatrix(&a1);
    freeMatrix(&a2);

    printMatrix(stdout, A);
    a1 = scalarMult(-2, A);
    printf("A1 scalarMult:\n");
    printMatrix(stdout, a1);
    Matrix As1 = diff(A, A);
    Matrix As2 = diff(As1, A);
    printf("As1:\n");
    printMatrix(stdout, As1);
    printf("A:\n");
    printMatrix(stdout, A);
    printf("As2:\n");
    printMatrix(stdout, As2);
    a2 = diff(As2, A);
    printf("A2:\n");
    printMatrix(stdout, a2);
    printf("A:\n");
    printMatrix(stdout, A);
    printf("\n\n");
    printMatrix(stdout, As2);
    freeMatrix(&As1);
    freeMatrix(&As2);
    printf("A1 nnz %d\n", NNZ(a1));
    printMatrix(stdout, a1);
    printf("A2 nnz %d\n", NNZ(a2));
    printMatrix(stdout, a2);
    if(equals(a1, a2) == 1) {
        printf("A & B equal\n");
    } else {
        printf("Not equal\n");
    }





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


