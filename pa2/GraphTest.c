#include "Graph.h"


int main(int argc, char *argv[]) {
    int i, s, d, n = 35;
    printf("Making new graph\n");
    Graph G = newGraph(n);
    /*
    for(i=1; i<n; i++){
        if( i%7!=0 ) addEdge(G, i, i+1);
        if( i<=28  ) addEdge(G, i, i+7);
    }
    */
    addEdge(G, 9, 31);
    addEdge(G, 17, 13);
    addEdge(G, 14, 33);
    addArc(G, 15, 12);
    addArc(G, 12, 15);
    printf("Size of G is %d\n", getSize(G));
    freeGraph(&G);
    return 0;
}
