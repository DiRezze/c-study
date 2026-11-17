#include <stdio.h>
#include <stdlib.h>

#define INICIO 0
#define FIM    9

void exibe_vetor(v, i, f)
int *v;
int i,f;
{
    int aux;

    printf("\nVETOR: ");
    for (aux=i; aux <= f; aux++)
        printf("%d, ",v[aux]);
    printf("\n");
}

void ordena_recursiva(v, i, f)
int *v;
int i,f;
{
    int aux;
    int menor=v[i];
    int indm=i;

    exibe_vetor(v,INICIO,FIM);

    if (i==f) return;

    // Procura o menor valor
    for (aux=i; aux <= f; aux++)
         if (v[aux] < menor)
         {
            indm=aux;
            menor=v[indm];
         }

    // Troca o menor com o primeiro valor
    v[indm]=v[i];
    v[i]=menor;

    ordena_recursiva(v,i+1,f);
}

int main()
{
    int Vetor[10] = { 3,9,4,10,1,5,7,8,2,6 };

    exibe_vetor(Vetor,INICIO,FIM);
    ordena_recursiva(Vetor,INICIO,FIM);
    exibe_vetor(Vetor,INICIO,FIM);

    system("pause");
    return 0;
}
