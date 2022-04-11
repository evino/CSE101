#include "Graph.h"


int main(int argc, char *argv[]) {
    int n = 5;
    Graph G = newGraph(n);
    printf("Order is %d\n", getOrder(G));
    freeGraph(&G);
    printf("Success\n");
    return 0;
}
