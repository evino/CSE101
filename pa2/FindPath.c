/*
   Evin Odisho
   edodisho
   pa2
   FindPath.c
*/


#include "Graph.h"
#define MAX_LEN 300


int main(int argc, char *argv[]) {
    
    FILE *in, *out;
    int vertNum;

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

    fscanf(in, "%d", &vertNum);
    printf("Num of vertex is: %d\n", vertNum);

    return 0;
}
