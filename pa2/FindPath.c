/*
   Evin Odisho
   edodisho
   pa2
   FindPath.c
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
            addEdge(G, u, v);
            //printf("U is %d, V is %d\n", u, v);
        }
        i++;
    }

    printGraph(out, G);

    //rewind(in);
    

    int j = 0;
    int source = 1;
    int dest = 1;
    while ((source != 0 && dest != 0)) {
        if (j > 0) {
            fscanf(in, "%d %d", &source, &dest);
            if (source == 0 && dest == 0) {
                break;
            }
            BFS(G, source);
            //source = getSource(G);
            fprintf(out, "\n");
            if (getDist(G, dest) == -999) {
                fprintf(out, "The distance from %d to %d is infinity\n", source, dest);
            } else {
                fprintf(out, "The distance from %d to %d is %d\n", source, dest, getDist(G, dest));
            }
            if (!isEmpty(L)) {
                clear(L);
            }

            
            getPath(L, G, dest);
            moveBack(L);
            if (get(L) == -1) {
                fprintf(out, "No %d-%d path exists\n", source, dest);
            } else {
                fprintf(out, "A shortest %d-%d path is: ", source, dest); printList(out, L);
            }
            //fprintf(stdout, "A shortest %d-%d path is: "; getPath(L, G, dest));

        }
        j++;
    }

    freeList(&L);
    freeGraph(&G);
    fclose(in);
    fclose(out);
    return 0;
}
