#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"

int main(int argc, char *argv[]) {
    List A = newList();
    //List B = newList();
    //List C = NULL;
    for(int i=23; i<=44; i++) {
        printf("Appending: %d\n", i);
        append(A, i);
    }
    moveFront(A);
    int myIndex = index(A);
    moveNext(A);
    printf("Cursor element at index %d is: %d\n", index(A), get(A));
    moveNext(A);
    printf("Cursor element now: %d\n", get(A));
    moveNext(A);
    moveNext(A);
    printf("Cursor ndex now at: %d\n", index(A));
    //moveBack(A);
    myIndex = index(A);
    printf("Index @ %d\n", myIndex);
    printList(stdout, A);
    delete(A);
    //printf("Cursor now at %d and equals %d\n", index(A), get(A));
    printList(stdout, A);
    printf("Segfaults at clear()\n");
    clear(A);
    printf("Freeing list now\n");
    freeList(&A);
    printList(stdout, A);
    return (EXIT_SUCCESS);
}
