/*
   Evin Odisho
   edodisho
   pa3
   FindComponents.c
*/


#include "Graph.h"




int main(int argc, char *argv[]) {
    
    FILE *in, *out;
    int n;
    int u, v;
    Graph G = NULL;
    List L = newList();

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
            addArc(G, u, v);
            append(L, u);
            //printf("U is %d, V is %d\n", u, v);
        }
        i++;
    }

    printGraph(out, G);

    //rewind(in);

    Graph T = transpose(G);

    DFS(G, L);
    DFS(T, L);

    fprintf(out, "List of Strongly connected components are: ");
    printList(out, L);

    freeList(&L);
    freeGraph(&G);
    freeGraph(&T);
    fclose(in);
    fclose(out);
    return 0;
}
