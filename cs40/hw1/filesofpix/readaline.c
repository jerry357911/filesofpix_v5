/*
readaline.c

*/

#include <stdio.h>
#include <stdlib.h>
#include "readaline.h"

size_t readaline(FILE *inputfd, char **datapp) {

    if (inputfd == NULL || datapp == NULL) {
        // checked runtime error
    }
    

    size_t capacity = 16;
    *datapp = malloc(capacity * sizeof(char));
    if (*datapp == NULL) {
        // checked runtime error
    }
    

    int c;
    size_t curr = 0;


    while ((c = fgetc(inputfd)) != '\n' && c != EOF) {

        if (curr + 2 == capacity) {
            capacity *= 2;

            char *temp = realloc(*datapp, capacity * sizeof(char));
            if (temp == NULL) {
                // checked runtime error
                free(*datapp);
                exit(1);
            }
            *datapp = temp;
        }
        (*datapp)[curr++] = (char) c;
    } 
    if (c == '\n') {
        (*datapp)[curr++] = '\n';
    }
    
    (*datapp)[curr] = '\0';
    
    if (c == EOF && curr == 0) {
        // free(*datapp);
        *datapp = NULL;  // if this is actually null
    }
    // printf("line: %li\n", curr);
    //printf("line: %s\n", *datapp);
    
    // // Free the memory allocated for *datapp before exiting
    // free(*datapp);
    // *datapp = NULL;
    


    return curr;


}

