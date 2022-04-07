#include "List.h"
#include <string.h>

#define MAX_LEN 300

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
    
    str = malloc(MAX_LEN * sizeof(char*));
    while (fgets(line, MAX_LEN, in) != NULL) {
        lineCount++;
        //str = (char *) realloc(str, sizeof(lineCount));
        str[lineCount] = malloc((MAX_LEN + 1) * sizeof(char));
        //*(str + lineCount) = line;
        str[lineCount] = line;
        //fprintf(out, "%s\n", str[lineCount]);
    }
    
    List myList = newList();
    // ind is index of str array
    for (int ind = 0; ind < lineCount; ind++) {
        for (int j = ind + 1; j < lineCount+1; j++) {
            
           //segfaults here
            if (strcmp(str[ind], str[j]) > 0) {
                strcpy(temp, str[ind]);
                strcpy(str[ind], str[j]);
                strcpy(str[j], temp);
                append(myList, ind);
            }
            //printf("DB1\n");
        
        }
        fprintf(out, "%s\n", str[ind]);
    }
            /*
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
        
        
    
    
    freeList(&myList);
    fclose(in);
    fclose(out);
    return (EXIT_SUCCESS);
}
