/*
 * Evin Odisho
 * edodisho
 * ListTest.c
 * pa1
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"

int main(int argc, char *argv[]) {
    List A = newList();
    List B = newList();
    List C = NULL;
    for (int i = 1; i <= 20; i++) {
        append(A, i);
        prepend(B, i);
    }
    printf("List A: "); printList(stdout, A);
    printf("List B: "); printList(stdout, B);
    printf("Copying List A into C.\n");
    C = copyList(A);
    printf("List C: "); printList(stdout, C);
    printf("Is List C equal to List A? ");
    printf("%s\n", equals(C,A)?"true":"false");
    moveBack(C);
    printf("Calling moveBack(). List C cursor now at index %d and it's data is: %d\n", index(C), get(C));
    movePrev(C);
    printf("Moving cursor to its previous one.\n");
    printf("List C cursor now at index %d and it's data is: %d\n", index(C), get(C));
    delete(C);
    printf("Deleting C's cursor.\n");
    deleteFront(C);
    printf("Deleting C's front node.\n");
    printf("List C now is: "); printList(stdout, C);
    printf("C's length is: %d\n", length(C));
    moveFront(C);
    moveNext(C);
    printf("Moving C's cursor to front, then moving it to next node.\n");
    printf("List C cursor now at index %d and it's data is: %d\n", index(C), get(C));
    printf("Now overwriting C's cursor data with 101, and inserting 100 and 102 before and after cursor...\n");
    set(C, 101);
    insertBefore(C, 100);
    insertAfter(C, 102);
    printf("List C now is: "); printList(stdout, C);
    printf("Is List C still equal to List A? ");
    printf("%s\n", equals(C,A)?"true":"false");
    printf("CLearing List A now...\n");
    clear(A);
    printf("Length of C: %d\n", length(C));
    printf("List C now is: "); printList(stdout, C);
    printf("Now clearing Lists B & C.\n");
    clear(B);
    clear(C);

    freeList(&A);
    freeList(&B);
    freeList(&C);
    return (EXIT_SUCCESS);
}

