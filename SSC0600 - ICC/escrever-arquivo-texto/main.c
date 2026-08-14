#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arq;
char buffer[105];

int main()
{
    arq = fopen("salvo.txt", "wt");

    if (arq) {
        while(1){
            fgets(buffer, 100, stdin);

            fputs(buffer, arq);
            if (strncmp(buffer,"FIM",3) == 0) break;
        }

        fclose(arq);
    }


    system("cat salvo.txt");

    return 0;
}
