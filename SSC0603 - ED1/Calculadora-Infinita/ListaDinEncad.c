#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

Lista* cria_lista()
{
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li)
{
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_final(Lista* li, Tipo_Dado dt)
{
    if(li == NULL)
        return ERRO;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return ERRO;
    no->dado = dt;
    no->prox = NULL;
    if((*li) == NULL){ //lista vazia: insere in�cio
        *li = no;
    }else{
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return OK;
}

int insere_lista_inicio(Lista* li, Tipo_Dado dt)
{
    if(li == NULL)
        return ERRO;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return ERRO;
    no->dado = dt;
    no->prox = (*li);
    *li = no;
    return OK;
}

int insere_lista_ordenada(Lista* li, Tipo_Dado dt)
{
    if(li == NULL)
        return ERRO;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return ERRO;
    no->dado = dt;
    if((*li) == NULL){ //lista vazia: insere in�cio
        no->prox = NULL;
        *li = no;
        return OK;
    }
    else{
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dado < dt){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){ //insere in�cio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return OK;
    }
}

int remove_lista(Lista* li, Tipo_Dado dt)
{
    if(li == NULL)
        return ERRO;
    if((*li) == NULL)//lista vazia
        return ERRO;
    Elem *ant, *no = *li;
    while(no != NULL && no->dado != dt){
        ant = no;
        no = no->prox;
    }
    if(no == NULL) //n�o encontrado
        return ERRO;

    if(no == *li) //remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return OK;
}

int remove_lista_inicio(Lista* li)
{
    int dado;

    if(li == NULL)
        return ERRO;
    if((*li) == NULL) //lista vazia
        return ERRO;

    Elem *no = *li;
    dado= no->dado;
    *li = no->prox;
    free(no);
    return dado;
}

int remove_lista_final(Lista* li)
{
    int dado;

    if(li == NULL)
        return ERRO;
    if((*li) == NULL) //lista vazia
        return ERRO;

    Elem *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li)) //remover o primeiro?
    {
        dado = no->dado;
        *li  = no->prox;
    }
    else
    {
        dado = no->dado;
        ant->prox = no->prox;
    }
    free(no);

    return dado;
}

int tamanho_lista(Lista* li)
{
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li)
{
    if (li == NULL) return 1;
    return 0;
}

int lista_vazia(Lista* li)
{
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista* li)
{
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        printf("%d",no->dado);
        no = no->prox;
    }
    printf("\n");
}

int soma_numeros(Lista* n1, Lista* n2, Lista* resultado) {
    if (n1 == NULL || n2 == NULL) return ERRO;

    int len1 = tamanho_lista(n1);
    int len2 = tamanho_lista(n2);
    int maxLen = len1 > len2 ? len1 : len2;

    if(len1 != len2) {
        if (len1 > len2) normaliza_numero(n2, maxLen - len2);
        else normaliza_numero(n1, maxLen - len1);
    }

    int vai_um = 0;
    for (int i = 0; i < maxLen; i++) {
        int d1, d2, d3;
        d1 = remove_lista_inicio(n1);
        d2 = remove_lista_inicio(n2);

        if (d1 < 0 || d2 < 0) return ERRO;

        d3 = d1 + d2 + vai_um;

        if (d3 >= 10) {
            d3 = d3 % 10;
            vai_um = 1;
        } else {
            vai_um = 0;
        }

        insere_lista_inicio(resultado, d3);

    }
    if (vai_um != 0) insere_lista_inicio(resultado, vai_um);

    return OK;
}

int normaliza_numero(Lista* li, int qtd_zeros) {
    if (li == NULL || qtd_zeros<= 0) return ERRO;

    Lista* aux = cria_lista();

    if (aux == NULL) return ERRO;

    while (!lista_vazia(li)) {
        int dado = remove_lista_inicio(li);
        insere_lista_inicio(aux, dado);
    }

    for (int i = 0; i < qtd_zeros; i++) {
        insere_lista_inicio(li, 0);
    }

    while (!lista_vazia(aux)) {
        int dado = remove_lista_inicio(aux);
        insere_lista_inicio(li, dado);
    }

    libera_lista(aux);

    return OK;

}