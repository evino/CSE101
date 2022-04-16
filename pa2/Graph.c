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
        G->distArr[i] = INF;
    }
    return G;
}

void freeGraph(Graph *pG) {
    List pL;
    if (pG == NULL || *pG == NULL) {
        printf("Graph Error: Calling freeGraph() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    if (pG != NULL && *pG != NULL) {
    int n = getOrder(*pG);
    for (int i = 1; i < n + 1; i++) {
        pL = (*pG)->listArr[i];
        freeList(&pL);
    }
    free((*pG)->listArr);
    free((*pG)->colors);
    free((*pG)->parArr);
    free((*pG)->distArr);
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
        printf("Graph Error: Calling getSize() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    
    return (G->size);
}

int getSource(Graph G) {
    // Check if BFS Called
    /*
    if (G->distArr[1] == INF) {
        G->source = NIL;
    }
    */
    return (G->source);
}

int getParent(Graph G, int u) {
    if (1 > u && u > getOrder(G)) {
        printf("Graph Error: Calling getParent() with out of bounds arguements\n");
        exit(EXIT_FAILURE);
    }
    if (G->distArr[u] == INF) {
        return NIL;
    }
    return (G->parArr[u]);
}


int getDist(Graph G, int u) {
    if (1 > u && u > getOrder(G)) {
        printf("Graph Error: Calling getDist() with out of bounds arguements\n");
        exit(EXIT_FAILURE);
    }
    return (G->distArr[u]);
}

void getPath(List L, Graph G, int u) {
    if (L == NULL) {
        printf("Calling getPath() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    if (G == NULL) {
        printf("Calling getPath() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    if (1 > u && u > getOrder(G)) {
        printf("Graph Error: Calling getPath() with out of bounds arguements\n");
        exit(EXIT_FAILURE);
    }
    if (getSource(G) == NIL) {
        printf("Graph Error: Calling getPath() before BFS()\n");
        exit(EXIT_FAILURE);
    }
    if (u == getSource(G)) {
        append(L, getSource(G));
        //printf("%d ", getSource(G));
    } else if (G->parArr[u] == NIL) {
        append(L, NIL);
        return;
    } else {
        getPath(L, G, G->parArr[u]);
        append(L, u);
        //printf("%d ", G->parArr[u]);
    }
    
    //printList(stdout, L);
    return;
}


/*** Manipulation procedures ***/


// Need help on this one. Will I delete each node in listArr[]?
void makeNull(Graph G) {
    if (G == NULL) {
        printf("Graph Error: Calling makeNull() on NULL Graph reference\n");
    }
    G->size = 0;
    return;
}

void addEdge(Graph G, int u, int v) {
    //Can use addArc here, just in two different directions.
    addArc(G, u, v);
    addArc(G, v, u);
    //G->size += 1;
    G->size--;
    return;
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
    
    if (isEmpty(G->listArr[u])) {
        append(G->listArr[u], v);
    }
    G->size++;

    moveFront(G->listArr[u]);
    if (v == (get(G->listArr[u]))) {
        return;
    }
    while (index(G->listArr[u]) != -1 && (v > get(G->listArr[u]))) {
        moveNext(G->listArr[u]);
    }
    
    
    if (index(G->listArr[u]) == -1) {
            moveBack(G->listArr[u]);
            insertAfter(G->listArr[u], v);
    } else {
        insertBefore(G->listArr[u], v);
    }

    //maybe needed?
    
    
    return;
}

void BFS(Graph G, int s) {
    if (G == NULL) {
        printf("Graph Error: Calling BFS() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    int x;
    G->source = s;
    for (x = 1; x < (getOrder(G) + 1); x++) {
        if (x != s) {
            G->colors[x] = 'w';
            G->distArr[x] = INF;
            G->parArr[x] = NIL;
        }
    }
    G->colors[s] = 'g';
    G->distArr[s] = 0;
    G->parArr[s] = NIL;
    List Q = newList();
    //append(Q, s);
    prepend(Q, s);
    while (!isEmpty(Q)) {
        moveBack(Q);
        //moveFront(Q);
        x = get(Q);
        //printf("%s\n","debug 3");
        //printf("%d\n",x);
        deleteBack(Q);
        if (G->listArr[x] != NULL) {
        moveFront(G->listArr[x]);
        //deleteFront(Q);
            int y;
            //for (int i = 1; i < length(G->listArr[x]); i++) {
            while (index(G->listArr[x]) != -1) {
                y = get(G->listArr[x]);
                if (G->colors[y] == 'w') {
                    G->colors[y] = 'g';
                    G->distArr[y] = (G->distArr[x] + 1);
                    G->parArr[y] = x;
                    prepend(Q, y);
                }
                moveNext(G->listArr[x]);
            }
            G->colors[x] = 'b';
        }
    }
    freeList(&Q);
    return;
}


// Prints out adjacency list
void printGraph(FILE *out, Graph G) {
    for (int i = 1; i <= getOrder(G); i++) {
        fprintf(out, "%d: ", i);
        printList(out, G->listArr[i]);
        //fprintf(out, "\n");
    }
    return;
}
