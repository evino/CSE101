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
    int order;
    int edgeCount;
    int *vertLabel;
} GraphObj;

Graph newGraph(int n) {
    Graph G;
    
    G = malloc(sizeof(GraphObj));
    G->listArr = malloc((n + 1) * sizeof(List));
    G->colors = malloc(n * sizeof(char));
    G->parArr = malloc(n * sizeof(int));
    G->distArr = malloc(n * sizeof(int));
    G->vertLabel = malloc(n * sizeof(int));

    G->listArr = NULL;
    G->colors = NULL;
    G->order = n;
    G->edgeCount = 0;
    *(G->parArr) = NIL;
    *(G->distArr) = NIL;
    *(G->vertLabel) = NIL;
    return G;
}

void freeGraph(Graph *pG) {
    if (pG != NULL || *pG != NULL) {
        printf("Graph Error: Calling freeGraph() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    if (pG != NULL && *pG != NULL) {
        free(*pG);
        *pG = NULL;
    }
}
