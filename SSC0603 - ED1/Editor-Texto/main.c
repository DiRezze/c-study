#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "LDED.h"

#define ARQ_SAIDA "texto-ed.txt"
#define ARQ_ENTRADA "texto.txt"

#define DEBUG 0

int main(void) {

    Lista* texto = cria_lista();

    if (!carrega_arquivo(texto, ARQ_ENTRADA)) {
        if (DEBUG) printf("ERRO AO CARREGAR!\n");
    };

    int exit_cmd = 0;

    do {

        char buffer[126], param[32], cmd;

        if (!fgets(buffer, sizeof(buffer), stdin)) break;

        param[0] = '\0';

        int lidos = sscanf(buffer, " %c %31s", &cmd, param);

        if (lidos < 1) continue;

        if (DEBUG) printf("[DEBUG] Comando '%c' | Parametro '%s'\n", cmd, param);

        switch (cmd) {
            case 'I':
                if (lidos == 2) insere_lista_inicio(texto, param);
                break;
            case 'F':
                if (lidos == 2) insere_lista_final(texto, param);
                break;
            case 'A':
                if (lidos == 2) insere_antes_cursor(texto, param);
                break;
            case 'D':
                if (lidos == 2) insere_prox_cursor(texto, param);
                break;
            case 'P':
                if (lidos == 2) {
                    procura_palavra(texto, param);
                }
                break;
            case 'T':
                if (lidos == 2) {
                    troca_palavra(texto, param);
                }
                break;
            case 'R':
                if (lidos == 2 && strcmp(param, "atual") == 0) {
                    remove_atual(texto);
                }
                break;
            case 'G':
                if (lidos==2) {
                    if (strcmp(param, "inicio") == 0) move_cursor_inicio(texto);
                    if (strcmp(param, "fim") == 0) move_cursor_final(texto);
                    if (strcmp(param, "prox") == 0) move_cursor_prox(texto);
                    if (strcmp(param, "ant") == 0) move_cursor_ant(texto);

                }
                break;
            case 'L':
                if (lidos == 2) {
                    if (strcmp(param, "texto") == 0) {
                        imprime_texto(texto);
                        break;
                    }
                    if (strcmp(param, "cursor") == 0) {
                        imprime_adjacente(texto);
                        break;
                    }
                    if (strcmp(param, "palavra") == 0) {
                        imprime_palavra(texto);
                        break;
                    }
                }
                break;
            case 'S':
                if (lidos == 2) {
                    if (strcmp(param, "texto") == 0) exibe_estatistica(texto);
                }
                break;
            case 'W':
                if (lidos == 2 && strcmp(param, "texto") == 0) {
                escrita_continua(texto);
                }
                break;
            case 'X':
                if (lidos == 2 && strcmp(param, "editor") == 0) {
                    salva_arquivo(texto, ARQ_SAIDA);
                    exit_cmd = 1;
                }
                break;
            default:
                if (DEBUG) printf("Comando não encontrado\n");
                break;
        }

    } while (!exit_cmd);

    if (DEBUG) printf("Loop encerrado\n");

    libera_lista(texto);

    return 0;
}
