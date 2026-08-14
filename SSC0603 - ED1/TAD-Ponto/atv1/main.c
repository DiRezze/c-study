#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Ponto.h"

char buffer[32];
double x, y, d;

int main(){

    fgets(buffer, sizeof(buffer), stdin);
    x = atof(buffer);
    fgets(buffer, sizeof(buffer), stdin);
    y = atof(buffer);

    Ponto* p1 = Ponto_cria(x, y);

    fgets(buffer, sizeof(buffer), stdin);
    x = atof(buffer);
    fgets(buffer, sizeof(buffer), stdin);
    y = atof(buffer);

    Ponto* p2 = Ponto_cria(x, y);

    d = Ponto_distancia(p1, p2);

    printf("%.2f\n", d);

    Ponto_libera(p1);
    Ponto_libera(p2);

    return 0;
}
