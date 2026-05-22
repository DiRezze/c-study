#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXERROR 0.001

char temp[32];

int i;

double n, x, y;

double error;

int main()
{
    fflush(stdin);

    fgets(temp, sizeof(temp), stdin);

    for(i=0; i < sizeof(temp); i++)
    if(temp[i] < 32){
        temp[i] = '\0';
        break;
    }

    n = atoi(temp);

    if(n==0){
        printf("0\n");
        return 0;
    }

    x = n;
    y = 1.0;

    i = 1;
    error = fabs(n - (x*x));

    while (error > MAXERROR) {
        x = (x + y) / 2.0;
        y = n/x;
        error = fabs(n - (x*x));
        printf("Iteration %d \n Estimado: %f \n[Erro: %f]\n", i, x, error);
        i++;
    }

    printf("Valor estimado: %f\n", x);

    printf("ERRO: %f\n", error);

    return 0;

}
