#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSequencial.h"

Lista* cria_lista(int max, char* nome){
    Lista *li = (Lista *) malloc(sizeof(Lista));
    if(li != NULL) {
        li->qtd = 0;
        li->dados = (tipo_dado*) calloc(max, sizeof(tipo_dado));
        li->max = max;
        strcpy(li->nome, nome);
        if (li->dados == NULL) {
            free(li);
            return NULL;
        }
    }

    return li;
}

void libera_lista(Lista* li){
    if (li != NULL) {
        if (li->dados)free(li->dados);
        free(li);
    }
}

int consulta_lista_pos(Lista* li, int pos, tipo_dado *dado){
    if(li == NULL || pos <= 0 ||  pos > li->qtd)
        return 0;
    *dado = li->dados[pos-1];
    return 1;
}

int insere_lista_final(Lista* li, tipo_dado dado)
{
    if(li == NULL)
        return 0;
    if(li->qtd == li->max)//lista cheia
        return 0;
    li->dados[li->qtd] = dado;
    li->qtd++;
    return 1;
}

int insere_lista_inicio(Lista* li, tipo_dado dado)
{
    if(li == NULL)
        return 0;
    if(li->qtd == li->max)//lista cheia
        return 0;
    int i;
    for(i=li->qtd-1; i>=0; i--)
        li->dados[i+1] = li->dados[i];
    li->dados[0] = dado;
    li->qtd++;
    return 1;
}

// Insere ordenado: acha a posi��o, abre um espaco, e insere
int insere_lista_ordenada(Lista* li, tipo_dado dado)
{
    if(li == NULL)
        return 0;
    if(li->qtd == li->max)//lista cheia
        return 0;
    int k,i = 0;
    while(i<li->qtd && li->dados[i].valor < dado.valor)
        i++;

    for(k=li->qtd-1; k >= i; k--)
        li->dados[k+1] = li->dados[k];

    li->dados[i] = dado;
    li->qtd++;
    return 1;
}

// Remove e desloca todos elementos depois do removido para uma posi��o mais para baixo
int remove_lista(Lista* li, tipo_dado dado)
{
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k,i = 0;
    while(i<li->qtd && li->dados[i].valor != dado.valor)
        i++;
    if(i == li->qtd)//elemento nao encontrado
        return 0;

    for(k=i; k< li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

//  Remove do final do vetor colocando no lugar do removido
int remove_lista_otimizado(Lista* li, tipo_dado dado)
{
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int i = 0;
    while(i<li->qtd && li->dados[i].valor != dado.valor)
        i++;
    if(i == li->qtd)//elemento nao encontrado
        return 0;

    li->qtd--;
    li->dados[i] = li->dados[li->qtd];
    return 1;
}

int remove_lista_inicio(Lista* li)
{
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k = 0;
    for(k=0; k< li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

int remove_lista_final(Lista* li)
{
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    li->qtd--;
    return 1;
}

int tamanho_lista(Lista* li)
{
    if(li == NULL)
        return -1;
    else
        return li->qtd;
}

int lista_cheia(Lista* li)
{
    if(li == NULL)
        return -1;
    return (li->qtd == li->max);
}

int lista_vazia(Lista* li)
{
    if(li == NULL)
        return -1;
    return (li->qtd == 0);
}

void imprime_lista(Lista* li)
{
    if(li == NULL)
        return;
    int i;
    printf("%s\n", li->nome);
    for(i=0; i< li->qtd; i++) {
        printf("%.2f\n",li->dados[i].valor);
    }
}
