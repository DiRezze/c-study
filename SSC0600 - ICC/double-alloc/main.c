#include <stdio.h>
#include <stdlib.h>

char buffer[128];
int num, i;

double *pValues;

int main()
{
    fgets(buffer, sizeof(buffer), stdin);
    num = atoi(buffer);

    pValues =  (double *) calloc(num, sizeof(double));
    for(i = 0; i < num; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        pValues[i] = atof(buffer);
    }

    for(i = num -1; i >= 0; i--) {
        printf("%.2f\n", pValues[i]);
    }

    free(pValues);

    return 0;
}
