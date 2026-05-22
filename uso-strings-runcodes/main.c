#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 80

char input[MAXLEN];
char testIn[MAXLEN];

char test[10]="TESTE";

int i, absLen, visibleLen;

int main()
{
    fflush(stdin);

    fgets(input, MAXLEN, stdin);

    absLen = 0;
    visibleLen = 0;

    for(i = 0; i < MAXLEN; i++) {

        if(input[i] >= 32) visibleLen++;
        absLen++;
        if(input[i] == '\0') break;
    }

    strcpy(testIn, input);

    for(i=0; i < MAXLEN; i++) {
        if(testIn[i] < 32) {
            testIn[i] = '\0';
            break;
        }
    }

    printf("%d\n", visibleLen);

    printf("%d\n", absLen);

    if(!strcmp(test, testIn)){
        printf("OK\n");
    } else {
        printf("NOT\n");
    }

    for(i = 0; i < absLen; i++) {
        if(input[i] >= 32){
                printf("%c (%d)\n", input[i], (int) input[i]);
        } else {
            printf("? (%d)\n", input[i], (int) input[i]);
        }
    }

    return 0;
}
