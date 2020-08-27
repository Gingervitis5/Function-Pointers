#ifndef LAB12_H
#define LAB12_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare your structure here

struct Stock{
    char symbol[10];
    char companyName[100];
    double currentPrice;
};

typedef struct Stock stock;


/**
 * Reads from the file and creates a structure and places it into the array.  Look at the file
 * to understand what the contents of the file are
 */
int fillArray(struct Stock array[], FILE * fin);
int menu();
void printArray(struct Stock array[], int total);

int compareSymbols(const void *one, const void *two);
int compareNames(const void *one, const void *two);
int comparePrices(const void *one, const void *two);

void switchValues(struct Stock *array, int start, int min);





#endif
