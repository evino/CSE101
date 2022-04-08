/*
 * Evin Odisho
 * edodisho
 * pa1
 * Lex.c
*/



#include "List.h"
#include <string.h>

#define MAX_LEN 300

// File I/O example used as inspiration

int main(int argc, char *argv[]) {
    char line[MAX_LEN];
    int lineCount = 0;
    FILE *in, *out;
    
    if( argc != 3 ){
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    in = fopen(argv[1], "r");
        if( in==NULL ){
        fprintf(stderr, "Unable to open file %s for reading\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    out = fopen(argv[2], "w");
    if( out==NULL ){
        fprintf(stderr, "Unable to open file %s for writing\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LEN, in) != NULL) {
        lineCount++;
    }
    rewind(in);

    char **str = malloc(lineCount * sizeof(char *));
    for (int i = 0; i < lineCount; i++) {
        str[i] = malloc(lineCount * sizeof(char));
    }
    
    int strIndex = 0;
    while (fgets(line, MAX_LEN, in) != NULL) {
        strcpy(str[strIndex], line);
        strIndex++;
    }

    List myList = newList();
    
    int count = 0;
    append(myList, count);
    
    for (count = 1; count < lineCount; count++) {
        moveFront(myList);
        while ((index(myList) !=  -1) && (strcmp(str[count], str[get(myList)]) > 0)) {
            moveNext(myList);
        }

        if (index(myList) == -1) {
            moveBack(myList);
            insertAfter(myList, count);
        } else {
            insertBefore(myList, count);
        }
    }

    moveFront(myList);
    
    for (int j = 0; j < lineCount; j++) {
        fprintf(out, "%s", str[get(myList)]);
        moveNext(myList);
    }
    
    for (int i=0; i < lineCount; i++) {
        free(str[i]);
    }
    
    free(str);
    freeList(&myList);
    fclose(in);
    fclose(out);
    
    
    return (EXIT_SUCCESS);
}
