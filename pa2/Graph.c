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
    listArr = malloc(n * sizeof(List));
    colors = malloc(n * sizeof(char));
    parArr = malloc(n * sizeof(int));
    distArr = malloc(n * sizeof(int));
    order = calloc(n, sizeof(int));
    //order = malloc(n * sizeof(int));
    //edgeCount = malloc(n * sizeof(int));
    edgeCount = calloc(n, sizeof(int));
    vertLabel = malloc(n * sizeof(int));

    listArr = NULL;
    colors = NULL;
    parArr = NIL;
    distArr = NIL;
    //order[] = 0;
    //edgeCount[] = 0;
    vertLabe = NIL;
    return G;
}
