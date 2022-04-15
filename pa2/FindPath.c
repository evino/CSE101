/*
   Evin Odisho
   edodisho
   pa2
   FindPath.c
*/


#include "Graph.h"
#define MAX_LEN 10
#define BUFF 2

int extract(int line[]) {
    




int main(int argc, char *argv[]) {
    
    FILE *in, *out;
    int n = 0;
    Graph G = NULL;
    int u, v;
    char line[MAX_LEN];
    char x1[2];
    char y1[2];

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

    fscanf(in, "%d", &n);
    printf("Num of vertex is: %d\n", n);
    
    int lineCount = 0;
    G = newGraph(n);

    while (fgets(line, BUFF, in) != NULL) {
        lineCount++;
    }
    lineCount--;
    
    while (fgets(line, MAX_LEN, in) != NULL) {
        if (lineCount > 0) {
            //fscanf(in, "%d %d", &u, &v);
            //fgets(x1, BUFF, in);
            //addEdge(G, u, v);
            //printf("%s\n", x1);
            printf("Line is %d\n", atoi(line));
        }
    }

    for (int i = 1; i < lineCount; i++) {


    printf("Line count is %d\n", lineCount);

    /*rewind(in);
    while (u != 0 && v != 0) {
        fscanf(in, "%d %d", &u, &v);
        addEdge(G, u, v);
    }
 */
    printGraph(stdout, G);

    return 0;
}
}
