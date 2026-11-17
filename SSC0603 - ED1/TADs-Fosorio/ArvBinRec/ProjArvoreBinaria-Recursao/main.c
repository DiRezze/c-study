#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int FlagAchou=0;
extern ArvBin* Nodo_atual;

int main()
{
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};
    int Achou;
    int Dado;

    ArvBin* raiz = cria_ArvBin();

    int i;
    for(i=0; i < N; i++)
        insere_ArvBin(raiz,dados[i]);

    printf("Dados Ordenados:\n");
    emOrdem_ArvBin(raiz);

    printf("\n");
    printf("Percurso SEM Corte Ordenados:\n");
    Exibe_emOrdem_ArvBin(raiz);

    printf("\n");
    Dado=40;
    FlagAchou=0;
    printf("Percurso COM Corte (pre-ordem): nodo %d\n",Dado);
    if (Exibe_preOrdem_Com_Corte_ArvBin(raiz, Dado, &FlagAchou))
        printf("ACHOU %d!\n",Dado);
    else
        printf("NAO ACHOU %d!\n",Dado);

    printf("\n");
    Dado=30;
    FlagAchou=0;
    printf("Procura COM Corte (pre-ordem): nodo %d\n",Dado);
    Achou = Procura_preOrdem_Com_Corte_ArvBin(raiz, Dado, &FlagAchou);
    if (Achou)
    {
           printf("ACHOU %d!\n",Dado);
           if (*Nodo_atual != NULL)
               printf("  Nodo: Info = %d\n",(*Nodo_atual)->info);
           if ((*Nodo_atual)->esq != NULL)
               printf("  Nodo: InfoEsq = %d\n",(*Nodo_atual)->esq->info);
           if ((*Nodo_atual)->esq != NULL)
               printf("  Nodo: InfoDir= %d\n",(*Nodo_atual)->dir->info);
    }
    else
        printf("NAO ACHOU %d!\n",Dado);


    libera_ArvBin(raiz);

    return 0;
}
