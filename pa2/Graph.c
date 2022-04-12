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
    int source;
} GraphObj;

Graph newGraph(int n) {
    Graph G;
    G = malloc(sizeof(GraphObj));
    G->listArr = malloc((n + 1) * sizeof(List));
    G->colors = malloc((n + 1) * sizeof(char));
    G->parArr = malloc((n + 1) * sizeof(int));
    G->distArr = malloc((n + 1) * sizeof(int));

    G->order = n;
    G->size = 0;
    G->source = NIL;
    for (int i = 1; i < n + 1; i++) {
        G->listArr[i] = newList();
        G->parArr[i] = NIL;
        printf("DB1\n");
        G->distArr[i] = INF;
        printf("DB2\n");
    }
    //*(G->parArr) = NIL;
    //*(G->distArr) = INF;
    //*(G->vertLabel) = NIL;
    return G;
}

void freeGraph(Graph *pG) {
    List pL;
    if (pG != NULL || *pG != NULL) {
        printf("Graph Error: Calling freeGraph() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    if (pG != NULL && *pG != NULL) {
        free(*pG);
        *pG = NULL;
    }
    int n = getOrder(*pG);
    free((*pG)->parArr);
    free((*pG)->distArr);
    for (int i = 1; i < n + 1; i++) {
        pL = (*pG)->listArr[i];
        freeList(&pL);
    }
    free((*pG)->listArr);

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
/*
int getSource(Graph G) {
    if (G == NULL) {
        printf("Graph Error: Calling getSource() on NULL Graph Reference\n");
        exit(EXIT_FAILURE);
    }
    int sourceRet;
    if (G->listArr[1] == NIL) {
        sourceRet = G->source;
    } else if(G->listArr[1] != NIL) {
        sourceRet = NIL;
    }
    return sourceRet;
    
}
*/



/*** Manipulation procedures ***/

void makeNull(Graph G) {
    if (G == NULL) {
        printf("Graph Error: Calling makeNull() on NULL Graph reference\n");
    }
    G->size = 0;
    return;
}

void addEdge(Graph G, int u, int v) {
}

void addArc(Graph G, int u, int v) {
    if (u < 1 || u > getOrder(G)) {
        printf("Graph Error: Calling addArc with out of range u arguement.\n");
        exit(EXIT_FAILURE);
    }
    if (v < 1 || v > getOrder(G)) {
        printf("Graph Error: Calling addArc with out of range v arguement.\n");
        exit(EXIT_FAILURE);
    }
    // Do insertion sort here
    if (G->listArr[1] == NULL) {
        append(G->listArr[1], v);
    }
    return;
}

