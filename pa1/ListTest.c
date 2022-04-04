#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"

int main(int argc, char *argv[]) {
    List A = newList();
    List B = newList();
    //List C = NULL;
    for(int i=23; i<=44; i++) {
        printf("Appending: %d\n", i);
        append(A, i);
    }
    moveFront(A);
    moveNext(A);
    printf("Cursor element at index %d is: %d\n", index(A), get(A));
    moveNext(A);
    printf("Cursor element now: %d\n", get(A));
    moveBack(A);
    printf("Index @ %d\n", index(A));
    printList(stdout, A);
    printf("Length before delete(): %d\n", length(A));
    delete(A);
    printf("After delete\n");
    //printf("After index called: Cursor now at %d", index(A));
    printList(stdout, A);
    B = copyList(A);
    printf("About to print B\n");
    printList(stdout, B);
    //printf("B curssor is: %d\n", get(B));
    printf("Length before clear: %d\n", length(A));
    clear(A);
    printf("Length after clear: %d\n", length(A));
    freeList(&A);
    printList(stdout, B);
    printList(stdout, A);
    return (EXIT_SUCCESS);
}
