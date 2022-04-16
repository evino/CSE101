/*
   Evin Odisho
   edodisho
   pa2
   FindPath.c
*/


#include "Graph.h"




int main(int argc, char *argv[]) {
    
    FILE *in, *out, *in2;
    int n;
    int u, v;
    Graph G = NULL;

    if( argc != 3 ) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    in = fopen(argv[1], "r");
    if( in==NULL ){
    fprintf(stderr, "Unable to open file %s for reading\n", argv[1]);
    exit(EXIT_FAILURE);
    }
    in2 = in;
    
    out = fopen(argv[2], "w");
    if( out==NULL ){
        fprintf(stderr, "Unable to open file %s for writing\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    
    int i = 0;
    u = 1;
    v = 1;
    //while (fscanf(in, "%[^\n]", 10) != EOF) {
    while ((u != 0 && v != 0)) {
        if (i == 0) {
            fscanf(in, "%d", &n);
            G = newGraph(n);
        } else {
            fscanf(in, "%d %d", &u, &v);
            if (u == 0 && v == 0) {
                break;
            }
            addEdge(G, u, v);
            //printf("U is %d, V is %d\n", u, v);
        }
        i++;
    }

    printGraph(stdout, G);

    //rewind(in);
    i = 0;
    u = 1;
    v = 1;
    int source;
    int dest;
    while ((u != 0 && v != 0)) {
        if (i == 0) {
            fscanf(in2, "%d", &n);
            printf("DB1\n");
        } else {
            fscanf(in2, "%d %d", &u, &v);
            printf("U is %d and v is %d\n", u, v);
            if (u == 0 && v == 0) {
                break;
            }
            dest = v;
            BFS(G, u);
            source = getSource(G);
            fprintf(stdout, "The distance from %d to %d is %d\n", source, dest, getDist(G, dest));
        }
        i++;
    }


    //make sure to freeList
    fclose(in);
    fclose(out);
    return 0;
}
