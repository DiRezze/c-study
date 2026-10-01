#include <stdio.h>
#include <stdlib.h>

#include "LDEDext.h"

int main()
{

    Tipo_Dado dado;
    Elem  *el;
    LDED *lista;

    lista = cria_lista();

    insere_lista_inicio(lista,1);
    insere_lista_inicio(lista,2);
    insere_lista_inicio(lista,3);

    imprime_lista(lista);

    printf("Procura dado: ");
    scanf("%d",&dado);

    if (consulta_lista_dado(lista,dado,&el))
        printf("Achou (%d) => Ant: %p - Dado: %p Prox: %p \n",dado,(void *)(el->ant),(void *)el,(void *)(el->prox));
    else
        printf("Nao Achou! \n");

    imprime_lista(lista);

    libera_lista(lista);
    return 0;
}

