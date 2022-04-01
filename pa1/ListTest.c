#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"

int main(int argc, char *argv[]) {
    List A = newList();
    //List B = newList();
    //List C = NULL;

    int i;
    for(i=1; i<=20; i++) {
        append(A, i);
    }
   
    printList(stdout, A);

    return (EXIT_SUCCESS);
}
