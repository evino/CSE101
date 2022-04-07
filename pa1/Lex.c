#include "List.h"
#include <string.h>

#define MAX_LEN 300

/*
void lexSort(char *str[], List L, int size) {
   
    int i = 0;
    append(L, i);
    moveFront(L);
    for (i = 1; i < size; i++) {
        while ((index(L) !=  -1) && (strcmp(str[size], str[i]) < 0)) {
            movePrev(L);
        }
        if (index(L) == -1) {
            prepend(L, i);
        }
        else {
            insertAfter(L, i);
        }
    }
}
*/

int main(int argc, char *argv[]) {
    char line[MAX_LEN];
    int lineCount = 0;
    FILE *in, *out;
    char **str;
    char temp[MAX_LEN];
    // check command line for correct number of arguments
    if( argc != 3 ){
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

   // open files for reading and writing
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

    printf("DB1\n");
    
    while (fgets(line, MAX_LEN, in) != NULL) {
        lineCount++;
    }
    rewind(in);
    printf("DB2\n");
    str = malloc(lineCount * sizeof(char*));
    for (int i = 0; i < lineCount; i++) {
        str[i] = malloc((MAX_LEN) * sizeof(char));
    }
    printf("DB3\n");
    /*
    while (fgets(line, MAX_LEN, in) != NULL) {
        printf("DB2\n");
        lineCount++;
        printf("DB3\n");
        str[lineCount] = malloc((MAX_LEN + 1) * sizeof(char));
        *(str + lineCount) = line;
        str[lineCount] = line;
    }
    */
    printf("DB4\n");

    List myList = newList();
    printf("DB5\n");
    //lexSort(str, myList, lineCount);
    int count = 0;
    append(myList, count);
    moveFront(myList);
    for (count = 0; count < lineCount; count++) {
        moveBack(myList);
        while ((index(myList) !=  -1) && (strcmp(str[get(myList)], str[count]) < 0)) {
            movePrev(myList);
            if (index(myList) == 0 && (strcmp(str[get(myList)], str[count]) < 0)) {
                prepend(myList, count);
                break;
            }
            else if (strcmp(str[get(myList)], str[count]) >= 0) {
                append(myList, count);
                //insertAfter(myList, count);
                break;
            }
        }
    }
    printList(out, myList);


    /*
    while (fgets(line, MAX_LEN, in) != NULL) {
        lineCount++;
        //str = (char *) realloc(str, sizeof(lineCount));
        str[lineCount] = malloc((MAX_LEN + 1) * sizeof(char));
        *(str + lineCount) = line;
        str[lineCount] = line;
        //fprintf(out, "%s\n", str[lineCount]);
    }
    
    List myList = newList();
    // ind is index of str array
    for (int ind = 0; ind < lineCount; ind++) {
        for (int j = ind + 1; j < lineCount+1; j++) {
            
           //segfaults here
            if (strcmp(str[ind], str[j+1]) > 0) {
                strcpy(temp, str[ind]);
                printf("DB2\n");
                strcpy(str[ind], str[j]);
                strcpy(str[j], temp);
                append(myList, ind);
            }
            //printf("DB1\n");
        
        }
        fprintf(out, "%s\n", str[ind]);
    }
            
            if (ind == 0) {
            append(myList, ind);
            moveFront(myList);
        }
        if (ind >= 1 && (strcmp(str[ind], str[ind-1]) < 0)) {
            insertBefore(myList, ind);
            movePrev(myList);
        }
        else if (ind >= 1 && (strcmp(str[ind], str[ind-1]) > 0)) {
            insertAfter(myList, ind);
            moveNext(myList);
        }
        fprintf(out, "%s\n", str[ind]);
        
        
        
*/    
    
    for (int i=0; i<lineCount; i++) {
        free(str[i]);
    }
    free(str);
    freeList(&myList);
    fclose(in);
    fclose(out);
    return (EXIT_SUCCESS);
}
