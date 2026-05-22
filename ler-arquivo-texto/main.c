#include <stdio.h>
#include <stdlib.h>

FILE *arq;
char buffer[256];
int i, j;

double nros[3];
double media;

int main()
{
    arq = fopen("nros.txt", "rt");

    media = 0;

    for(i=0; i < 3; i++){
        fgets(buffer, sizeof(buffer), arq);
        for(j=0; j < sizeof(buffer); j++){
            if(buffer[j] < 32) buffer[j] = '\0';
        }
        printf("%s\n", buffer);
        nros[i] = atof(buffer);
        media += nros[i];
    }

    media = media/3;

    printf("%.2f\n", media);

    fclose(arq);

    return 0;
}
