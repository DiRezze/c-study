#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buffer[128];
int num, i, j;

char (*pLavras)[50];

int main()
{
    fgets(buffer, sizeof(buffer), stdin);
    num = atoi(buffer);

    pLavras =  (char (*)[50]) calloc(num, sizeof(char) * 50);
    for(i = 0; i < num; i++) {
        fgets(buffer, sizeof(buffer), stdin);

        for(j = 0; j < 50; j++) {
            if(buffer[j] < 32) buffer[j] = '\0';
        }

        strncpy(pLavras[i], buffer, 50);
    }

    for(i = num -1; i >= 0; i--) {
        int len = strlen(pLavras[i]);

        printf("%s\n", pLavras[i]);
        for(j = len - 1; j >=0; j--) {
            printf("%c", pLavras[i][j]);
        }
        printf("\n");
    }

    free(pLavras);

    return 0;
}
