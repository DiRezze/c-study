#include <stdio.h>
#include <stdlib.h>

#include "ListaSequencial.h"

int main(void) {

    char buffer[32];

    fgets(buffer,sizeof(buffer),stdin);

    int capacidade = atoi(buffer);

    Lista* lInicio = cria_lista(capacidade, "inicio");
    Lista* lFinal = cria_lista(capacidade, "final");
    Lista* lOrdenada = cria_lista(capacidade, "ordenada");

    fgets(buffer,sizeof(buffer),stdin);

    int numEntradas =  atoi(buffer);

    if (numEntradas >= 0 && numEntradas <= capacidade) {
        tipo_dado entrada;
        for (int i = 0; i < numEntradas; i++) {
            fgets(buffer,sizeof(buffer),stdin);

            entrada.valor = atof(buffer);

            if (!insere_lista_inicio(lInicio, entrada)) printf("ERRO\n");
            if (!insere_lista_final(lFinal, entrada)) printf("ERRO\n");
            if (!insere_lista_ordenada(lOrdenada, entrada)) printf("ERRO\n");

        }


        imprime_lista(lInicio);
        imprime_lista(lFinal);
        imprime_lista(lOrdenada);

        if (!remove_lista_inicio(lInicio)) printf("ERRO\n");
        if (!remove_lista_final(lFinal)) printf("ERRO\n");
        if (!remove_lista(lOrdenada, entrada)) printf("ERRO\n");

        imprime_lista(lInicio);
        imprime_lista(lFinal);
        imprime_lista(lOrdenada);



        libera_lista(lOrdenada);
        libera_lista(lInicio);
        libera_lista(lFinal);

    } else printf("ERRO\n");

    return 0;
}
