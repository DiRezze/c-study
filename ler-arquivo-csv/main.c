#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "dados.csv"

FILE *arq;

char buff[1024];
char *comma;
int i, j;

double num[10][10];


int main()
{
    arq = fopen(FILE_NAME, "rt");

    if(arq == NULL) return 1;

    i = 0;

    while(fgets(buff, sizeof(buff), arq)) {
        buff[strcspn(buff, "\n")] = '\0';
        buff[strcspn(buff, "\r")] = '\0';

        comma = strtok(buff, ",");

        j=0;

        while(comma){
            num[i][j] = atof(comma);
            comma = strtok(NULL, ",");
            j++;
        }
        i++;

    }

    fclose(arq);

    for(i=0; i < 10; i++) {
        for(j=0; j < 10; j++) {
            printf("%.2lf", num[i][j]);

            if (j < 10 - 1) {
                printf(" ");
            }

        }
        printf("\n");
    }



    return 0;

}
