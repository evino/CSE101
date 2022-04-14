#include "Graph.h"


int main(int argc, char *argv[]) {
    int n = 5;
    int u = 3;
    int v = 2;
    printf("Making new graph\n");
    Graph G = newGraph(n);
    printf("Order is %d\n", getOrder(G));
    addEdge(G, u, v);
    printGraph(stdout, G);
    freeGraph(&G);
    printf("Success\n");
    return 0;
}
