#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ABO.h"

#define DEBUG 0
#define ARQUSPT "us-pt.txt"
#define ARQPTUS "pt-us.txt"

void traduzir(ArvBin* dict);

int main(void){
    
    ArvBin* usDict = cria_ArvBin();
    ArvBin* ptDict = cria_ArvBin();
    
    int readUs = carrega_arquivo(ARQUSPT, usDict);
    int readPt = carrega_arquivo(ARQPTUS,ptDict);
    
    if(readPt < 0 || readUs < 0) {
        if(DEBUG)printf("[ERRO] Leitura de arquivo falhou\n");
        return 0;
    }
    
    printf("US %d\n", readUs);
    printf("PT %d\n", readPt);
    
    char buffer[16];
    while(fgets(buffer, sizeof(buffer), stdin) != NULL) {
        char* token = strtok(buffer, " \n\r\t");
        if(strcmp(token, "LD") == 0) {
            printf("US\n");
            emOrdem_Simplificado(usDict);
            printf("PT\n");
            emOrdem_Simplificado(ptDict);
            break;
        }
        else if(strcmp(token, "TUSPT") == 0) {
            traduzir(usDict);
            break;
        }
        else if(strcmp(token, "TPTUS") == 0) {
            traduzir(ptDict);
            break;
        }
    }
    
    if(DEBUG) printf("Estruturas liberadas\n");
    libera_ArvBin(usDict);
    libera_ArvBin(ptDict);
    
    return 0;
}

// void traduzir(ArvBin* dict) {
//     char buffer[126];
//
//     char* out = "";
//
//     while(fgets(buffer, sizeof(buffer), stdin) != NULL) {
//         char* token = strtok(buffer, " \n\r\t");
//         if(token[0] == '#') break;
//         strcat(out, consulta_traducao(dict, token));
//     }
//
//     printf("%s\n", out);
//
// }

void traduzir(ArvBin* dict) {
    char buffer[126];

    size_t cap = 2048;
    size_t len = 0; // Guarda o tamanho atual de 'out'
    char* out = malloc(cap);
    if (out == NULL) return;
    out[0] = '\0';

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        char* token = strtok(buffer, " \n\r\t");

        while (token != NULL) {
            if (token[0] == '#') {
                printf("%s", out);
                free(out);
                return;
            }

            char* res = consulta_traducao(dict, token);

            // Formata a linha da palavra atual em um buffer temporário
            char linha[256];
            int n_bytes;
            if (res != NULL) {
                n_bytes = snprintf(linha, sizeof(linha), "%s\n", res);
                free(res);
            } else {
                n_bytes = snprintf(linha, sizeof(linha), "%s -1\n", token);
            }

            // Garante que o buffer 'out' tem espaço suficiente antes de concatenar
            if (len + n_bytes + 1 > cap) {
                while (len + n_bytes + 1 > cap) {
                    cap *= 2; // Dobra a capacidade até caber
                }
                char* novo = realloc(out, cap);
                if (novo == NULL) {
                    free(out);
                    return;
                }
                out = novo;
            }

            // Copia a nova linha para o final de 'out'
            memcpy(out + len, linha, n_bytes + 1);
            len += n_bytes;

            token = strtok(NULL, " \n\r\t");
        }
    }

    printf("%s", out);
    free(out);
}