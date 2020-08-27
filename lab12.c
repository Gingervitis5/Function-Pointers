#include "lab12.h"
#include "./utils/utils.h"


int menu()
{
   int num;
   do {
       printf("Please choose from the following\n");
       printf("1) Sort by Symbol\n");
       printf("2) Sort by Company Name\n");
       printf("3) Sort by Price\n");
       printf("4) Quit\n");
       printf("Choice --> ");
       scanf("%d", &num);
   } while (num < 1 || num > 4);

   return num;
}// end menu

int fillArray(struct Stock array[], FILE * fin){
    int x = 0;
    for (x; x < 10 && !feof(fin); x++){
        fgets(array[x].symbol, 15, fin);
        strip(array[x].symbol);
        fgets(array[x].companyName, 100, fin);
        strip(array[x].companyName);
        fscanf(fin, "%lf", &(array[x].currentPrice));
        fgetc(fin);
    }

    if (array == NULL){
        return 0;
    }
    return x-1;
}

void printArray(struct Stock array[], int total){
    int x = 0, y = 0;
    for (x; x < total; x++){

        for(y; y < (strlen(array[x].companyName)); y++){
            printf("%c", array[x].companyName[y]);
        }
        y = 0;
        printf(" - ");
        for(y; y < (strlen(array[x].symbol)); y++){
            printf("%c", array[x].symbol[y]);
        }
        y = 0;
        printf(" - ");
        printf("%.2lf\n", array[x].currentPrice);
    }

    printf("\n");
}

int compareSymbols(const void *one, const void *two){
    stock *s1 = (stock *)one;
    stock *s2 = (stock *)two;
    return strcmp(s1->symbol,s2->symbol);
}

int compareNames(const void *one, const void *two){
    stock *s1 = (stock *)one;
    stock *s2 = (stock *)two;
    return strcmp(s1->companyName,s2->companyName);
}

int comparePrices(const void *one, const void *two){
    stock *s1 = (stock *)one;
    stock *s2 = (stock *)two;
    return ( ((s1->currentPrice)*100) - ((s2->currentPrice)*100) );
}

void switchValues(struct Stock *array, int start, int min) {
    char temp[100], temp2[100]; double temp3;

    strcpy(temp, array[start].symbol);
    strcpy(temp2, array[start].companyName);
    temp3 = array[start].currentPrice;

    strcpy(array[start].symbol, array[min].symbol);
    strcpy(array[start].companyName, array[min].companyName);
    array[start].currentPrice = array[min].currentPrice;

    strcpy(array[min].symbol, temp);
    strcpy(array[min].companyName, temp2);
    array[min].currentPrice = temp3;
}
