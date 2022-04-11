/*
   Evin Odisho
   edodisho
   pa2
   Graph.c
*/

#include "Graph.h"
#include <stdlib.h>

typedef struct GraphObj {
    List *listArr;
    char *colors;
    int *parArr;
    int *distArr;
    int *order;
    int *edgeCount;
    int *vertLabel;
} GraphObj;

Graph newGraph(int n) {
    Graph G;
    
    G = malloc(sizeof(GraphObj));
    G->listArr = malloc((n + 1) * sizeof(List));
    G->colors = malloc(n * sizeof(char));
    G->parArr = malloc(n * sizeof(int));
    G->distArr = malloc(n * sizeof(int));
    G->order = calloc(n, sizeof(int));
    //order = malloc(n * sizeof(int));
    //edgeCount = malloc(n * sizeof(int));
    G->edgeCount = calloc(n, sizeof(int));
    G->vertLabel = malloc(n * sizeof(int));

    G->listArr = NULL;
    G->colors = NULL;
    *(G->parArr) = NIL;
    *(G->distArr) = NIL;
    //order[] = 0;
    //edgeCount[] = 0;
    *(G->vertLabel) = NIL;
    return G;
}
