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
    int size;
    int *vertLabel;
} GraphObj;

Graph newGraph(int n) {
    Graph G;
    
    G = malloc(sizeof(GraphObj));
    G->listArr = malloc((n + 1) * sizeof(ListObj));
    G->colors = malloc((n + 1) * sizeof(char));
    G->parArr = malloc((n + 1) * sizeof(int));
    G->distArr = malloc((n + 1) * sizeof(int));
    G->vertLabel = malloc((n + 1) * sizeof(int));

    G->listArr = NULL;
    G->colors = NULL;
    G->order = n;
    G->size = 0;
    *(G->parArr) = NIL;
    *(G->distArr) = INF;
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


int getOrder(Graph G) {
    if (G == NULL) {
        printf("Graph Error: Calling getOrder() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    return (G->order);
}

int getSize(Graph G) {
    if (G == NULL) {
        printf("Graph Error: Calling getOrder() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    
    return (G->size);
}
