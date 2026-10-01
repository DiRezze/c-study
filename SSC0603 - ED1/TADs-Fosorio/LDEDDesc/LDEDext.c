#include <stdio.h>
#include <stdlib.h>

#include "LDEDext.h" //inclui os Prot�tipos

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

int consulta_lista_dado(LDED* lista, Tipo_Dado dt, Elem **el)
{
    if (lista == NULL)
        return 0;
    Elem *no = (*lista).Lini;
    while (no != NULL)
    {
        if (no->dado == dt) break;
        no = no->prox;
    }
    if (no == NULL)
        return ERRO;
    else
	{
        *el = no;
        (*lista).Lcursor=no;
        return OK;
    }
}

int insere_lista_inicio(LDED* lista, Tipo_Dado dt)
{
    if (lista == NULL)
        return ERRO;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;

    no->dado = dt;
    no->prox = (*lista).Lini;
    no->ant = NULL;

	if ( ((*lista).Lini) != NULL ) //lista n�o vazia: apontar para o anterior!
    {
        ((*lista).Lini)->ant = no;
        (*lista).Lini = no;
        // Cursor permanece onde esta
        // Fim permanece onde esta
    }
    else  // Primeiro nodo: todos Lini,Lfim,Lcursor apontam para ele
    {
        (*lista).Lini = no;
        (*lista).Lfim = no;
        (*lista).Lcursor = no;
    }

    return OK;
}

int insere_lista_final(LDED* lista, Tipo_Dado dt)
{
    Elem *no;

    if (lista == NULL) return ERRO;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)  return ERRO;

    no->dado = dt;
    no->prox = NULL;

	if ((*lista).Lini == NULL)
	{   //lista vazia: insere in�cio
        no->ant = NULL;
        (*lista).Lini = no;
        (*lista).Lfim = no;
        (*lista).Lcursor = no;
    }
    else
	{
	    // Procura... NAO OTIMIZADO!!! OPS!
	    // Depois da insercao: cursor � o inserido

        Elem *aux;
        aux = (*lista).Lini;
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
        (*lista).Lfim = no;
        (*lista).Lcursor = no;
    }
    return OK;
}


/*
int insere_lista_ordenada(Lista* li, Tipo_Dado dt)
{
    if (li == NULL)
        return ERRO;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;
    no->dado = dt;
    if ((*li) == NULL)
	{  //lista vazia: insere in�cio
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return OK;
    }
    else{
        Elem *ante, *atual = *li;
        while (atual != NULL && atual->dado < dt)
		{
            ante = atual;
            atual = atual->prox;
        }
        if (atual == *li)
		{   //insere in�cio
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        } else
		{
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if (atual != NULL)
                atual->ant = no;
        }
        return OK;
    }
}

int remove_lista(Lista* li, Tipo_Dado dt)
{   //TERMINAR
    if (li == NULL)
        return ERRO;
    if ((*li) == NULL)//lista vazia
        return ERRO;
    Elem *no = *li;
    while (no != NULL && no->dado != dt){
        no = no->prox;
    }
    if (no == NULL)//n�o encontrado
        return ERRO;

    if (no->ant == NULL)//remover o primeiro?
        *li = no->prox;
    else
        no->ant->prox = no->prox;

    if (no->prox != NULL)//n�o � o �ltimo?
        no->prox->ant = no->ant;

    free(no);
    return OK;
}


int remove_lista_inicio(Lista* li)
{
    if (li == NULL)
        return ERRO;
    if ((*li) == NULL)//lista vazia
        return ERRO;

    Elem *no = *li;
    *li = no->prox;
    if (no->prox != NULL)
        no->prox->ant = NULL;

    free(no);
    return OK;
}

int remove_lista_final(Lista* li)
{
    if (li == NULL)
        return ERRO;
    if ((*li) == NULL) //lista vazia
        return ERRO;

    Elem *no = *li;
    while (no->prox != NULL)
        no = no->prox;

    if (no->ant == NULL) //remover o primeiro e �nico
        *li = no->prox;
    else
        no->ant->prox = NULL;

    free(no);
    return OK;
}
*/

int tamanho_lista(LDED* lista)
{
    if (lista == NULL)
        return 0;
    int cont = 0;
    Elem* no = (*lista).Lini;
    while (no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(LDED* lista)
{
    return FALSO;
}

int lista_vazia(LDED* lista)
{
    if (lista == NULL)
        return OK;
    if ((*lista).Lini == NULL)
        return OK;
    return FALSO;
}

void imprime_lista(LDED* li)
{
    Elem* no = (*li).Lini;

    if (li == NULL)
        return;

    printf("Lista LDED: \n");
    printf(" Lini: %p \n Lfim: %p \n Lcursor: %p \n",(void *)((*li).Lini),(void *)((*li).Lfim),(void *)((*li).Lcursor));


    while (no != NULL)
    {
        printf("Dado: %5d # Ant: %p - Dado: %p - Prox: %p\n",no->dado,(void *)(no->ant),(void *)no,(void *)(no->prox));
        no = no->prox;
    }
    printf("-------------- FIM LISTA -----------------\n");
}

