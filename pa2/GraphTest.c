#include "Graph.h"


int main(int argc, char *argv[]) {
    int n = 5;
    printf("Making new graph\n");
    Graph G = newGraph(n);
    printf("Order is %d\n", getOrder(G));
    freeGraph(&G);
    printf("Success\n");
    return 0;
}
