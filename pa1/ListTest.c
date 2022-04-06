#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"

int main(int argc, char *argv[]) {
    List A = newList();
    List B = newList();
    for (int i = 1; i <= 20; i++) {
        append(A, i);
        prepend(B, i);
    }
    printf("List A: "); printList(stdout, A);
    printf("\nList B: "); printList(stdout, B);
    List C = newList();
    C = copyList(A);
    moveBack(C);
    movePrev(C);
    movePrev(C);
    delete(C);
    printf("Length of C: %d\n", length(C));
    printf("\nList C: "); printList(stdout, C);


    freeList(&A);
    freeList(&B);
    freeList(&C);
    return (EXIT_SUCCESS);
}

/*
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
    deleteFront(B);
    deleteBack(B);
    printf("DB1\n");
    moveFront(B);
    //moveBack(B);
    printf("List B:\n"); printList(stdout, B);
    insertBefore(B, 1);
    printf("Now called insertBefore on B...\n");
    printList(stdout, B);
    printf("Length of B is %d\n", length(B));
    //moveBack(B);
    printf("Inserting after index %d...\n", index(B));
    printf("Deleting front and back\n");
   // deleteBack(B);
    insertAfter(B, 69); printList(stdout, B);
    printf("Length of B now is %d\n", length(B));
    //printf("B curssor is: %d\n", get(B));
    printf("Length before clear: %d\n", length(A));
    clear(A);
    printf("Length after clear: %d\n", length(A));
    freeList(&A);
    printList(stdout, B);
    printList(stdout, A);
    freeList(&B);
    return (EXIT_SUCCESS);
}
*/
