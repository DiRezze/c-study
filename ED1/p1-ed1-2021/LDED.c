
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LDED.h"

LDED* cria_lista()
{
    LDED *lista;

    lista = (LDED*) malloc(sizeof(LDED));
    if (lista != NULL)
    {
        (*lista).Lfim = NULL;
        (*lista).Lini = NULL;
        (*lista).Lcursor = NULL;
    }
    return lista;
}

void libera_lista(LDED* lista)
{
    if (lista != NULL)
	{
        Elem* no;
        (*lista).Lfim=NULL;
        (*lista).Lcursor=NULL;
        while ((*lista).Lini != NULL)
		{
            no = (*lista).Lini;
            (*lista).Lini = ((*lista).Lini)->prox;
            free(no);
        }
        free(lista);
    }
}

int insere_lista_ordenado(LDED* li, Tipo_Dados* dt){
    if(li == NULL) return ERRO;

    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL) return ERRO;

    strcpy(no->dado.prefixo, dt->prefixo);
    strcpy(no->dado.palavra, dt->palavra);
    no->dado.usos = dt->usos;

    if(li->Lini == NULL){
        no->ant = NULL;
        no->prox = NULL;
        li->Lini = no;
        li->Lfim = no;
        li->Lcursor = no;
        return OK;
    }

    Elem* atual = li->Lini;
    Elem* anterior = NULL;

    while (atual != NULL) {
        int comp = strcmp(dt->prefixo, atual->dado.prefixo);

        if (comp < 0) {
            break;
        }

        else if (comp == 0) {
            if (dt->usos > atual->dado.usos) {
                break;
            }
        }

        anterior = atual;
        atual = atual->prox;

    }

    if (anterior == NULL) {
        no->ant = NULL;
        no->prox = li->Lini;
        li->Lini->ant = no;
        li->Lini = no;
    }
    else if (atual == NULL) {
        no->prox = NULL;
        no->ant = li->Lfim;
        li->Lfim->prox = no;
        li->Lfim = no;
    }
    else {
        no->prox = atual;
        no->ant = anterior;
        anterior->prox = no;
        atual->ant = no;
    }

    return OK;

}


int consulta_lista_dado(LDED* li, char* prefixo)
{
    if (li == NULL)
        return 0;

    int printed = 0;

    Elem *no = li->Lini;

    for(int i = 0; prefixo[i] != '\0'; i++) {
        if(prefixo[i] < 32) {
            prefixo[i] = '\0';
            break;
        }
    }
    while (no != NULL && printed < 3){
        int comp = strcmp(no->dado.prefixo, prefixo);

        if (comp == 0) {
            printf("%s %d\n", no->dado.palavra, no->dado.usos);
            printed++;
        } else if(comp > 0) break;

        no = no->prox;
    }

    return OK;

}



void imprime_lista(LDED* li)
{
    Elem* no = (*li).Lini;

    if (li == NULL)
        return;

    // printf("Lista LDED: \n");
    // printf(" Lini: %p \n Lfim: %p \n Lcursor: %p \n",(void *)((*li).Lini),(void *)((*li).Lfim),(void *)((*li).Lcursor));


    while (no != NULL)
    {
        printf("Dado: %s %s %d\n",no->dado.prefixo, no->dado.palavra, no->dado.usos);
        no = no->prox;
    }
    // printf("-------------- FIM LISTA -----------------\n");
}

void imprime_n_lista(LDED* li, int num) {
    if(li == NULL || li->Lcursor == NULL) return;

    Elem* no = li->Lcursor;

    int printed = 0;

    while(no!= NULL && printed < num ) {

        printf("%s %d\n", no->dado.palavra, no->dado.usos);

        no = no->prox;
        printed++;
    }
}

int le_arquivo(LDED* li, char* path) {
    if(li == NULL) return ERRO;

    FILE* f = fopen(path, "rt");

    if (f == NULL) return ERRO;

    char line[256];
    Tipo_Dados dt;
    int eof = 0;
    int lidos =0;


    while (fgets(line, sizeof(line), f) != NULL) {

        char *token = strtok(line, " \t\n\r");
        if (token == NULL) continue;

        if (strcmp(token, "#") == 0) {
            break;
        }
        strcpy(dt.prefixo, token);

        token = strtok(NULL, " \t\n\r");
        if (token == NULL) continue;
        strcpy(dt.palavra, token);

        token = strtok(NULL, " \t\n\r");
        if (token == NULL) continue;
        dt.usos = atoi(token);

        insere_lista_ordenado(li, &dt);
        lidos++;
    }

    fclose(f);

    return lidos;
}

