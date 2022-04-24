//-----------------------------------------------------------------------------
// Evin Odish
// edodisho
// pa3
// GraphTest.c
// My test client for the Graph ADT
//-----------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include"List.h"
#include"Graph.h"


int main(int argc, char* argv[]){
    int i, n=8;
    List S = newList();
    Graph G = newGraph(n);
    Graph T=NULL, C=NULL;

    for(i=1; i<=n; i++) append(S, i);

    addArc(G, 1,2);
    addArc(G, 1,5);
    addArc(G, 2,5);
    addArc(G, 2,6);
    addArc(G, 3,2);
    addArc(G, 3,4);
    addArc(G, 3,6);
    addArc(G, 3,7);
    addArc(G, 3,8);
    addArc(G, 6,5);
    addArc(G, 6,7);
    addArc(G, 8,4);
    addArc(G, 8,7);
    printGraph(stdout, G);

    DFS(G, S);
    fprintf(stdout, "\n");
    fprintf(stdout, "x:  d  f  p\n");
    for(i=1; i<=n; i++){
        fprintf(stdout, "%d: %2d %2d %2d\n", i, getDiscover(G, i), getFinish(G, i), getParent(G, i));
    }

    fprintf(stdout, "\n");
    printList(stdout, S);
    printf("DB seg\n");
    fprintf(stdout, "\n");
    

    T = transpose(G);
    C = copyGraph(G);
    fprintf(stdout, "\n");
    printGraph(stdout, C);
    fprintf(stdout, "\n");
    printGraph(stdout, T);
    fprintf(stdout, "\n");

    printf("Before DFS()\n");

    DFS(T, S);

    printf("After DFS()\n");

    fprintf(stdout, "\n");
    fprintf(stdout, "x:  d  f  p\n");
    for(i=1; i<=n; i++){
        fprintf(stdout, "%d: %2d %2d %2d\n", i, getDiscover(T, i), getFinish(T, i), getParent(T, i));
    }
    fprintf(stdout, "\n");
    printList(stdout, S);
    fprintf(stdout, "\n");

    
    // Debug for DB_getSize in ModelGraphTest.c from pa3.sh
    // Failing test 2, think it has to do with doing addArc with
    // same vertices. Need to add case to handle this issue.
    // The correct size for this test graph is 5
    Graph testGraph = newGraph(60);
    printf("Size of test right now is %d\n", getSize(testGraph));
    addArc(testGraph, 54, 1);
    addArc(testGraph, 54, 2);
    addArc(testGraph, 54, 2);
    addArc(testGraph, 54, 3);
    addArc(testGraph, 1, 54);
    addArc(testGraph, 1, 54);
    addArc(testGraph, 1, 54);
    printf("After adding arcs, size of test graph is %d\n", getSize(testGraph));

    //Dealloc
    freeList(&S);
    freeGraph(&G);
    freeGraph(&T);
    freeGraph(&C);
    return(0);
}
