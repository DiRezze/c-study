#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float input[10];

char temp[100];

int i, j;

float max, min;


int main()
{
    fflush(stdin);

    for(i = 0; i < 10; i++) {

        fgets(temp, sizeof(temp), stdin);

        for(j=0; j < sizeof(temp); j++)
        if(temp[j] < 32){
            temp[j] = '\0';
            break;
        }

        input[i] = atof(temp);
    }

    max = min = input[0];

    for(i=0; i<10; i++) {
            if(input[i] > max) max = input[i];
            if(input[i] < min) min = input[i];
    }

    printf("%.2f\n%.2f\n", min, max);

    return 0;
}

