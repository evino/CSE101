/*
	Evin Odisho
	edodisho
	pa4
	Sparse.c
*/

#include "Matrix.h"


int main(int argc, char **argv) {

	FILE *in, *out;
    int n, a, b;

    if( argc != 3 ) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    in = fopen(argv[1], "r");
    if( in==NULL ){
    fprintf(stderr, "Unable to open file %s for reading\n", argv[1]);
    exit(EXIT_FAILURE);
    }
    
    out = fopen(argv[2], "w");
    if( out==NULL ){
        fprintf(stderr, "Unable to open file %s for writing\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    fscanf(in, "%d %d %d", &n, &a, &b);

    Matrix A = newMatrix(n);
    Matrix B = newMatrix(n);

    fscanf(in, "\n");

    int row, col;
    double val;
    for (int i = 1; i <= a; i++) {
    	fscanf(in, "%d %d %lf", &row, &col, &val);
    	changeEntry(A, row, col, val);
    }
    fprintf(out, "A has %d non-zero entries:\n", a);
    printMatrix(out, A);

    for (int i = 1; i <= b; i++) {
    	fscanf(in, "%d %d %lf", &row, &col, &val);
    	changeEntry(B, row, col, val);
    }
    fprintf(out, "\nB has %d non-zero entries:\n", b);
    printMatrix(out, B);

    Matrix SM = scalarMult(1.5, A);
    fprintf(out, "\n(1.5)*A =\n");
    printMatrix(out, SM);

    Matrix add1 = sum(A, B);
    fprintf(out, "\nA+B =\n");
    printMatrix(out, add1);

    Matrix add2 = sum(A, A);
    fprintf(out, "\nA+A =\n");
    printMatrix(out, add2);

    Matrix sub1 = diff(B, A);
    fprintf(out, "\nB-A =\n");
    printMatrix(out, sub1);


    Matrix sub2 = diff(A, A);
    fprintf(out, "\nA-A =\n");
    printMatrix(out, sub2);

    Matrix tran = transpose(A);
    fprintf(out, "\nTranspose(A) =\n");
    printMatrix(out, tran);

    Matrix prod1 = product(A, B);
    fprintf(out, "\nA*B =\n");
    printMatrix(out, prod1);

    Matrix prod2 = product(B, B);
    fprintf(out, "\nB*B =\n");
    printMatrix(out, prod2);



    // Memory deallocation
    freeMatrix(&A);
    A = NULL;

    freeMatrix(&B);
    B = NULL;

    freeMatrix(&SM);
    SM = NULL;

    freeMatrix(&add1);
    add1 = NULL;

    freeMatrix(&add2);
    add2 = NULL;

    freeMatrix(&sub1);
    sub1 = NULL;

    freeMatrix(&sub2);
    sub2 = NULL;

    freeMatrix(&tran);
    tran = NULL;

    freeMatrix(&prod1);
    prod1 = NULL;

    freeMatrix(&prod2);
    prod2 = NULL;

    fclose(in);
    fclose(out);


    return EXIT_SUCCESS;
}