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
    //*(G->parArr) = NIL;
    //*(G->distArr) = INF;
    //*(G->vertLabel) = NIL;
    return G;
}

void freeGraph(Graph *pG) {
    List pL;
    if (pG == NULL || *pG == NULL) {
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
        printf("Graph Error: Calling getSize() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    
    return (G->size);
}

int getSource(Graph G) {
    // Check if BFS Called
    if (G->distArr[1] == INF) {
        G->source = NIL;
    }
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
    } else if (G->parArr[u] == NIL) {
        printf("%d is not reachable from %d\n", u, getSource(G));
    } else {
        getPath(L, G, G->parArr[u]);
        append(L, u);
    }
    
    return;
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
    (G->size)++;
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
        printf("DB: Doing first append\n");
        append(G->listArr[u], v);
    }
    //for (int i = 2; i <= getOrder(G); i++) {
    //printf("INDEX %d\n", i);
        moveFront(G->listArr[u]);
        //while (index(G->listArr[u]) != -1 && (i > get(G->listArr[u]))) {
        while (index(G->listArr[u]) != -1 && (u > get(G->listArr[u]))) {
            moveNext(G->listArr[u]);
        }
        if (index(G->listArr[u]) == -1) {
            moveBack(G->listArr[u]);
            printf("DB: Insert after\n");
            insertAfter(G->listArr[u], v);
        } else {
            printf("DB: Insert b4\n");
            insertBefore(G->listArr[u], v);
        }
    //}

    return;
}

void BFS(Graph G, int s) {
    int x;
    G->source = s;
    for (x = 1; x < (getOrder(G) - s); x++) {
        G->colors[x] = 'w';
        G->distArr[x] = INF;
        G->parArr[x] = NIL;
    }
    G->colors[s] = 'g';
    G->distArr[s] = 0;
    G->parArr[s] = NIL;
    List Q = newList();
    append(Q, s);
    while (!isEmpty(Q)) {
        moveFront(Q);
        x = get(Q);
        deleteFront(Q);
        for (int y = 1; y < getOrder(G); y++) {
            if (G->colors[y] == 'w') {
                G->colors[y] = 'g';
                G->distArr[y] = (G->distArr[x] + 1);
                G->parArr[y] = x;
                append(Q, y);
            }
        }
        G->colors[x] = 'b';
    }
    return;
}


// Prints out adjacency list
void printGraph(FILE *out, Graph G) {
    for (int i = 1; i <= getOrder(G); i++) {
        fprintf(out, "%d: ", i);
        printList(out, G->listArr[i]);
        fprintf(out, "\n");
    }
    return;
}
