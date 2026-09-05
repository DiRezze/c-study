#include <stdio.h>
#include <stdlib.h>

#include "ListaDinEncad.h"

#define FILENAME_1 "arq-nro1.txt"
#define FILENAME_2 "arq-nro2.txt"

char buffer[50];
FILE* f;

int main(void) {


    Lista* num1 = cria_lista();

    f = fopen(FILENAME_1, "rt");

    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        if (buffer[0] == '#') break;
        Tipo_Dado input = atoi(buffer);
        insere_lista_inicio(num1, input);
    }
    fclose(f);

    Lista* num2 = cria_lista();

    f = fopen(FILENAME_2, "rt");

    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        if (buffer[0] == '#') break;
        Tipo_Dado input = atoi(buffer);
        insere_lista_inicio(num2, input);
    }
    fclose(f);

    Lista* resultado = cria_lista();

    soma_numeros(num1, num2, resultado);

    imprime_lista(resultado);

    libera_lista(num1);
    libera_lista(num2);
    libera_lista(resultado);

    return 0;
}
