#ifndef PONTO
#define PONTO

typedef struct ponto Ponto;

Ponto* Ponto_cria(double x, double y);

void Ponto_libera(Ponto* p);

double Ponto_distancia(Ponto* p1, Ponto* p2);

int Ponto_acessa(Ponto* p, double* x, double* y);

int Ponto_atribui(Ponto* p, double x, double y);

#endif // ponto
