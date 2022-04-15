/*
   Evin Odisho
   edodisho
   pa2
   FindPath.c
*/


#include "Graph.h"
#define MAX_LEN 10
#define BUFF 2
/*
void extract(char *line[]) {
    //int lineInt = atoi(*line);
    char x1[2];
    x1[0] = *line[0];
    if (*line[1] != " ") {
        x1[1] = *line[1];
    }
    printf("%d\n", atoi(x1));

    return;
}
*/


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

    rewind(in);
    int tempCount = 0;

    while(!feof (in) && (u != 0 && v != 0)) {
        if (tempCount > 0) {
            fscanf(in, "%d %d", &u, &v);
            printf("u is %d and v is %d\n", u, v);
        }
        tempCount++;
    }
    
    
    /*
    while (fgets(line, MAX_LEN, in) != NULL || fgets(line, MAX_LEN, in) != "0 0") {
        if (lineCount > 0) {
            //fscanf(in, "%d %d", &u, &v);
            //fgets(x1, BUFF, in);
            //addEdge(G, u, v);
            //printf("%s\n", x1);
            printf("Line is %s\n", line);
            extract(&line);
        }
    }

*/

    printf("Line count is %d\n", lineCount);

    /*rewind(in);
    while (u != 0 && v != 0) {
        fscanf(in, "%d %d", &u, &v);
        addEdge(G, u, v);
    }
 */
    printGraph(stdout, G);


    //make sure to freeList
    fclose(in);
    fclose(out);
    return 0;
}
