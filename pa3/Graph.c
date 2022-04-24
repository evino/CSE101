/*
   Evin Odisho
   edodisho
   pa3
   Graph.c
*/

#include "Graph.h"
#include <stdlib.h>

typedef struct GraphObj {
    List *listArr;
    char *colors;
    int *parArr;
    int *discArr;
    int *finishArr;
    int order;
    int size;
} GraphObj;

Graph newGraph(int n) {
    Graph G;
    G = malloc(sizeof(GraphObj));
    G->listArr = malloc((n + 1) * sizeof(List));
    G->colors = malloc((n + 1) * sizeof(char));
    G->parArr = malloc((n + 1) * sizeof(int));
    G->discArr = malloc((n + 1) * sizeof(int));
    G->finishArr = malloc((n + 1) * sizeof(int));

    G->order = n;
    G->size = 0;
    for (int i = 1; i < n + 1; i++) {
        G->listArr[i] = newList();
        G->parArr[i] = NIL;
        G->discArr[i] = UNDEF;
        G->finishArr[i] = UNDEF;
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
    free((*pG)->discArr);
    free((*pG)->finishArr);
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


int getParent(Graph G, int u) {  /* Pre: 1<=u<=n=getOrder(G) */
    //if (1 > u && u > getOrder(G)) {
    if (!(1 <= u && u <= getOrder(G))) {
        printf("Graph Error: Calling getParent() with out of bounds arguements\n");
        exit(EXIT_FAILURE);
    }
    if (G->discArr[u] == UNDEF) {
        return NIL;
    }
    return (G->parArr[u]);
}

int getDiscover(Graph G, int u) { /* Pre: 1<=u<=n=getOrder(G) */
    //if (1 > u && u > getOrder(G)) {
    if (!(1 <= u && u <= getOrder(G))) {
        printf("Graph Error: Calling getDiscover() with out of bounds vertex arguement.\n");
        exit(EXIT_FAILURE);
    }

    return (G->discArr[u]);
}

int getFinish(Graph G, int u) {
    if (G == NULL) {
        printf("Graph Error: Calling getFinish() with NULL Graph Reference\n");
        exit(EXIT_FAILURE);
    }
    if (!(1 <= u && u <= getOrder(G))) {
        printf("Graph Error: Calling getFinish() with out of bounds vertex arguement.\n");
        exit(EXIT_FAILURE);
    }

    return (G->finishArr[u]);
}



/*** Manipulation procedures ***/


void addEdge(Graph G, int u, int v) {
    //Can use addArc here, just in two different directions.
    addArc(G, u, v);
    addArc(G, v, u);
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

    if (isEmpty(G->listArr[u])) {
        append(G->listArr[u], v);
        G->size++;
        return;
    }

    moveFront(G->listArr[u]);
    while (index(G->listArr[u]) != -1) {
        if (v == get(G->listArr[u])) {
            //set(G->listArr[u], v);
            return;
        }
        moveNext(G->listArr[u]);
    }
    
    
    moveFront(G->listArr[u]);
    while (index(G->listArr[u]) != -1 && (v > get(G->listArr[u]))) {
        moveNext(G->listArr[u]);
    }
    if (index(G->listArr[u]) == -1) {
            moveBack(G->listArr[u]);
            insertAfter(G->listArr[u], v);
    } else {
        //if (length(G->listArr[u]) > 1)
            insertBefore(G->listArr[u], v);
    }
    G->size++;

    return;
}


void Visit(Graph G, List s, int x, int *time) {
    if (G == NULL) {
        printf("Graph Error: Calling Visit() on NUll Graph reference\n");
        exit(EXIT_FAILURE);
    }
    printf("X is %d\n", x);
    G->discArr[x] = ++(*time);
    G->colors[x] = 'g';
    printf("Db2\n");

    printf("Cursor at %d\n", index(G->listArr[x]));
    if (!isEmpty(G->listArr[x])) {
        printf("DB list\n");
        moveFront(G->listArr[x]);
        printf("Right before moveFront of value %d\n", x);
        while (index(G->listArr[x]) != -1) {
            printf("Calling get on: %d\n", get(G->listArr[x]));
            if (G->colors[get(G->listArr[x])] == 'w') {
                G->parArr[get(G->listArr[x])] = x;
                printf("XX is %d\n", x);
                if (x != 5) 
                Visit(G, s, get(G->listArr[x]), time);
            }
            printf("!!!!!!!!!calling moveNext()\n");
            moveNext(G->listArr[x]);
            printf("After moveNext()!!!!!!!!!\n");
            //prepend(s, x);
        }
    }
    else {
        printf("Bottom hit, x is %d\n", x);
        return;
    }
    printf("DB3\n");
    printf("get() DB!!!!!!\n");
    G->colors[get(G->listArr[x])] = 'b';
    //moveBack(s);
    ++(*time);
    //printf("was able to push to stack\n");
    G->finishArr[x] = *time;
    return;
}

void DFS(Graph G, List s) {
    if (G == NULL) {
        printf("Graph Error: Calling DFS() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    if (s == NULL) {
        printf("Graph Error: Calling DFS() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    List stackCopy = copyList(s);
    moveFront(s);
    //for (int i = index(s); i != -1; i++) {
        //G->colors[get(s)] = 'w';
        //G->parArr[get(s)] = NIL;
    //}
    int x;
    for (x = 1; x < (getOrder(G) + 1); x++) {
        G->colors[x] = 'w';
        G->parArr[x] = NIL;
    }
    int time = 0;
    clear(s);
    moveFront(stackCopy);
    int i = 1;
    printf("stackCopy is"); printList(stdout, stackCopy);
    while (index(stackCopy) != -1) {
        printf("Current colors is %c and index is %d\n", G->colors[get(stackCopy)], index(stackCopy));
        if (G->colors[get(stackCopy)] == 'w') {
            printf("Iteration %d\n", i);
            printf("DB1\n");
            i++;
            Visit(G, s, get(stackCopy), &time);
        }
        printf("stackCopy cursor at: %d\n", get(stackCopy));
        moveNext(stackCopy);
    }

    /*
     for (int x = 1; x < (getOrder(G) + 1); x++) {
        if (G->colors[x] == 'w') {
            //printf("About to call Visit() inside DFS\n");

            // can only keep s and x as call by val and use get() for x
            Visit(G, &s, &x, &time);
            //printf("After calling Visit() inside DFS function\n");
        }
    }
    */
    freeList(&stackCopy);
    return;
}

// Other functions

Graph transpose(Graph G) {
    //Graph T = NULL;
    if (G == NULL) {
        printf("Graph Error: Calling transpose() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    Graph T = newGraph(getOrder(G));
    for (int i = 1; i <= getOrder(G); i++) {
        moveFront(G->listArr[i]);
        while(index(G->listArr[i]) != -1) {
            addArc(T, get(G->listArr[i]), i);
            moveNext(G->listArr[i]);
        }
    }
    return T;
}

Graph copyGraph(Graph G) {
    if (G == NULL) {
        printf("Graph Error: Calling copyGraph() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    Graph N = newGraph(getOrder(G));
    for (int i = 1; i <= getOrder(G); i++) {
        moveFront(G->listArr[i]);
        while (index(G->listArr[i]) != -1) {
            addEdge(N, i, get(G->listArr[i]));
            moveNext(G->listArr[i]);
        }
    }
    return N;
}


/*
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
    prepend(Q, s);
    while (!isEmpty(Q)) {
        moveBack(Q);
        x = get(Q);
        deleteBack(Q);
        if (G->listArr[x] != NULL) {
        moveFront(G->listArr[x]);
            int y;
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

*/

void printGraph(FILE *out, Graph G) {
    if (G == NULL) {
        printf("Graph Error: Calling printGraph() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i <= getOrder(G); i++) {
        fprintf(out, "%d: ", i);
        if (!isEmpty(G->listArr[i])) {
            printList(out, G->listArr[i]);
        } else {
            fprintf(out, "\n");
        }
    }
    return;
}
