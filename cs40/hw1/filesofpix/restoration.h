/*
restoration.h
*/

#include "readaline.h"
#include "list.h" 
#include "table.h" 
#include <stdlib.h> 
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "atom.h"

// Returns pointer to the opened file
FILE* openOrDie(char *filename);

void processInput(FILE *inputfd);

typedef struct {
    int frequency;
    List_T list;
} Value;
