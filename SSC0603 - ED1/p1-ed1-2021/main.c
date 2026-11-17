#include <stdio.h>
#include <stdlib.h>

#include "LDED.h"

#define DEBUG 0
#define ARQUIVO "arq.txt"

int main()
{
    LDED* li = cria_lista();

    int lidos = le_arquivo(li, ARQUIVO);

    printf("LIDOS %d\n", lidos);

    char buffer[126];

    if(DEBUG)printf("CONTROLE\n");

    fgets(buffer, sizeof(buffer), stdin);

    consulta_lista_dado(li, buffer);

    libera_lista(li);

    return 0;
}
