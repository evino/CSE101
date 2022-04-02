#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"

int main(int argc, char *argv[]) {
    List A = newList();
    //List B = newList();
    //List C = NULL;
    for(int i=1; i<=20; i++) {
        printf("Appending: %d\n", i);
        append(A, i);
    }
    moveFront(A);
    int myIndex = index(A);
    printf("Index @: %d\n", myIndex);
    moveNext(A);
    printf("Index now at: %d\n", index(A));
    moveNext(A);
    printf("Index now at: %d\n", index(A));
    moveBack(A);
    myIndex = index(A);
    printf("Index @ %d\n", myIndex);
    printList(stdout, A);

    return (EXIT_SUCCESS);
}
