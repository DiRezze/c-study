#include <stdio.h>
#include <stdlib.h>

#include "ListaDinEncad.h"

int main(void) {

    Lista* lInicio = cria_lista();
    Lista* lFim = cria_lista();
    Lista* lOrdenada = cria_lista();

    if (lInicio == NULL || lFim == NULL || lOrdenada == NULL) {
        printf("ERRO\n");
        return 0;
    }

    Tipo_Dado input = 0;
    int inserted = 0;

    while (1) {
        char buffer[32];
        fgets(buffer, sizeof(buffer), stdin);
        if (buffer[0] == '#') break;
        input = atof(buffer);
        inserted++;
        insere_lista_inicio(lInicio, input );
        insere_lista_final(lFim, input);
        insere_lista_ordenada(lOrdenada, input);
    }

    printf("inicio\n");
    imprime_lista(lInicio);
    printf("final\n");
    imprime_lista(lFim);
    printf("ordenada\n");
    imprime_lista(lOrdenada);

    if (inserted > 0) {
        remove_lista(lInicio, input);
        remove_lista(lFim, input);
        remove_lista(lOrdenada, input);
    } else {
        printf("ERRO\n");
    }

    printf("inicio\n");
    imprime_lista(lInicio);
    printf("final\n");
    imprime_lista(lFim);
    printf("ordenada\n");
    imprime_lista(lOrdenada);

    return 0;
}
