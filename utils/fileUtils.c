#include "fileUtils.h"

FILE * openInputFile()
{
    FILE * fin = NULL;
    char fName[100];
    do {
        printf("Enter a file name: ");
        fgets(fName, 100, stdin);
        int x = 0;
        while (fName[x] != '\0' && x < strlen(fName))
        {
            if(fName[x] == '\r')
                fName[x] = '\0';

            else if(fName[x] == '\n')
                fName[x] = '\0';

            x++;

        }
        fin = fopen(fName, "r");
    } while (fin == NULL);

    return fin;

}

