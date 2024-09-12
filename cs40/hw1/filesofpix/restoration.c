/*
restoration.c

*/

#include "restoration.h"
#include <stdlib.h> 
#include <stdio.h>
#include "list.h"


int main(int argc, char *argv[]) {
    // reading from standard input
    FILE *inputfd;

    if (argc == 1){
        // take file name input from user
        char *filename = malloc(100 * sizeof(char));

        (void) inputfd;
        printf("Enter the file name: ");
        scanf("%s", filename);

        printf("filename: %s\n", filename);

        inputfd = openOrDie(filename);


    } else if (argc == 2){
        inputfd = openOrDie(argv[1]);
    } else {
        printf("Usage: %s [filename]\n", argv[0]); // double check
        exit(1);
    }

    processInput(inputfd);




    
    // if (inputfd != ){
    //     fclose(inputfd);
    // }

    // free(inputfd);

    fclose(inputfd);
    return EXIT_SUCCESS;

    // free(inputfd);
    
}

void processInput(FILE *inputfd){
    char *pt1 = "";
    char **datapp = &pt1;
    size_t counter = 0; // for testing purposes
    size_t temp = 0;
    size_t numOfLines = 0;

    Table_T map = Table_new(0, NULL, NULL);
        
    do {
        temp = readaline(inputfd, datapp);
        counter += temp;
        numOfLines++;

        char *nonDigit = malloc(temp * sizeof(char)); // temp maybe too big
        char *digit = malloc(temp * sizeof(char)); // temp maybe too big
        int nIndex = 0;
        for (size_t dIndex = 0; dIndex < temp; dIndex++){
            if(!(isdigit(((*datapp)[dIndex]))))
            {

                nonDigit[nIndex] = (*datapp)[dIndex];
                // add space to digit
                digit[dIndex] = (int) ' ';
                nIndex++;

            }
            else
            {
                digit[dIndex] = (*datapp)[dIndex];
            }
        }

        const char *key = Atom_new(nonDigit, nIndex);
        
        // check if key exists in table
        void* keyExists = Table_get(map, key); 
        if(keyExists == NULL)
        {
            Value *value = malloc(sizeof(Value));
            if(value == NULL)
            {
                // checked runtime error
                exit(1);
            }
            // value->frequency = malloc(sizeof(int));
            value->frequency = (int )1;
            value->list = List_list((void *)digit);
            Table_put(map, key, (void *) value);
        }

        char *ptTest = "";
        char **test = &ptTest;


        void *return_value = Table_get(map, key);
        Value *value = (Value *)return_value;
        printf("value: %d\n", value->frequency);

        List_pop(value->list, (void*) test);
        printf("List: %d\n", (*test)[0]);

        



        // printf("nonDigit: %d\n", nonDigit[0]);
        // char *key = Atom_string(nonDigit);
        // free(*datapp); // need to remember to free datapp, tho currently there is still mem leak after freeing it
    }
    while ((temp && (**datapp != EOF)));

    printf("%li\n", counter);
    printf("%li\n", numOfLines);


}

FILE* openOrDie(char *filename){
    FILE* file = fopen(filename, "rb");

    if (filename == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(4); // double check if this is the correct exit code
    } 

    return file;
}

