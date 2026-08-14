#include <stdlib.h>
#include <math.h>
#include "Ponto.h"

struct ponto {
    double x;
    double y;
};

Ponto* Ponto_cria(double x, double y){
    Ponto* p = (Ponto*) malloc(sizeof(struct ponto));
    if(p != NULL){
        p->x = x;
        p->y = y;
    }
    return p;
}

void Ponto_libera(Ponto* p){
    if(p != NULL) free(p);
}

double Ponto_distancia(Ponto* p1, Ponto* p2) {
    if(p1 != NULL && p2 != NULL){
        double dx = p2->x - p1->x;
        double dy = p2->y - p1->y;
        double d = sqrt((dx*dx) + (dy* dy));
        return d;
    }
    return -1;
}

int Ponto_acessa(Ponto* p, double* x, double* y){
    if(p != NULL) {
        *x = p->x;
        *y = p->y;
        return 1;
    }
    return 0;
}

int Ponto_atribui(Ponto* p, double x, double y) {
    if(p != NULL) {
        p->x = x;
        p->y = y;
        return 1;
    }
    return 0;
}
