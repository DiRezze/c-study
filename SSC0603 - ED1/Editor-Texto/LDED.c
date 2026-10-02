#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LDED.h"

Lista* cria_lista()
{
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL) {
        li->inicio = NULL;
        li->fim = NULL;
        li->cursor = NULL;
        li->qtd = 0;
    }

    return li;
}

void libera_lista(Lista* li)
{
    if (li != NULL)
	{
        Elem* no;
        while ((li->inicio) != NULL)
		{
            no = li->inicio;
            li->inicio = li->inicio->prox;
            free(no);
        }
        free(li);
    }
}

int consulta_lista_pos(Lista* li, int pos, Palavra *dt)
{
    if (li == NULL || pos <= 0 || li->inicio == NULL)
        return ERRO;
    Elem *no = li->inicio;
    int i = 1;
    while (no != NULL && i < pos)
	{
        no = no->prox;
        i++;
    }
    if (no == NULL)
        return ERRO;
    else
	{
        strcpy(*dt, no->dado);
        return OK;
    }
}

int consulta_lista_dado(Lista* li, Palavra dt, Elem **el)
{
    if (li == NULL)
        return 0;
    Elem *no = li->inicio;
    while (no != NULL && strcmp(no->dado, dt) !=0 ){
        no = no->prox;
    }
    if (no == NULL)
        return ERRO;
    else
	{
        *el = no;
        return OK;
    }
}

int insere_lista_final(Lista* li, Palavra dt)
{
    if (li == NULL) return ERRO;

    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return ERRO;

    strcpy(no->dado, dt);
    no->prox = NULL;

    if (li->inicio == NULL) {
        no->ant = NULL;
        li->inicio = no;
        li->cursor = no;
    } else {
        no->ant = li->fim;
        li->fim->prox = no;
    }

    li->fim = no;
    li->cursor = no;

    li->qtd++;

    return OK;
}

int insere_lista_inicio(Lista* li, Palavra dt)
{
    if (li == NULL)
        return ERRO;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;

    strcpy(no->dado, dt);
    no->prox = (li->inicio);
    no->ant = NULL;

	if (li->inicio != NULL) {
	    li->inicio->ant = no;
	} else {
	    li->fim = no;
	}
    li->inicio = no;
    li->cursor = no;
    li->qtd++;
    return OK;
}

int remove_lista(Lista* li, Palavra dt)
{
    if (li == NULL||li->inicio == NULL)
        return ERRO;
    if (li->inicio == NULL)
        return ERRO;
    Elem *no = li->inicio;
    while (no != NULL && strcmp(no->dado, dt) != 0 ){
        no = no->prox;
    }
    if (no == NULL)
        return ERRO;

    if (no->ant == NULL)
        li->inicio = no->prox;
    else
        no->ant->prox = no->prox;

    if (no->prox != NULL) {
        no->prox->ant = no->ant;
    } else {
        li->fim = no->ant;
    }

    if (li->cursor == no) {
        li->cursor = (no->ant !=NULL) ? no->ant : no->prox;
    }


    li->qtd--;

    free(no);
    return OK;
}


int remove_lista_inicio(Lista* li)
{
    if (li == NULL)
        return ERRO;
    if (li->inicio == NULL)
        return ERRO;

    Elem *no = li->inicio;
    li->inicio = no->prox;
    if (no->prox != NULL)
        no->prox->ant = NULL;
    else
        li->fim = NULL;

    if (li->cursor == no)
        li->cursor = li->inicio;

    li->qtd--;

    free(no);
    return OK;
}

int remove_lista_final(Lista* li)
{
    if (li == NULL || li->inicio == NULL)
        return ERRO;

    Elem *no = li->fim;

    if (no->ant == NULL) {
        li->inicio = NULL;
        li->fim = NULL;
    } else {
        no->ant->prox = NULL;
        li->fim = no->ant;
    }

    if (li->cursor == no)
        li->cursor = li->fim;

    li->qtd--;
    free(no);
    return OK;
}

int tamanho_lista(Lista* li)
{
    if (li == NULL)
        return 0;
    int qtd = li->qtd;
    return qtd;
}

int lista_cheia(Lista* li)
{
    return FALSO;
}

int lista_vazia(Lista* li)
{
    if (li == NULL)
        return OK;
    if (li->inicio == NULL)
        return OK;
    return FALSO;
}

void imprime_lista_debug(Lista* li)
{
    Elem* no = li->inicio;

    if (li == NULL)
        return;
    while (no != NULL)
    {
        printf("Dado: %s # Ant: %p - Dado: %p - Prox: %p\n",no->dado,no->ant,no,no->prox);
        no = no->prox;
    }
    printf("-------------- FIM LISTA -----------------\n");
}


void imprime_lista(Lista* li, FILE* out)
{
    Elem* no = li->inicio;

    if (li == NULL)
        return;
    while (no != NULL)
    {
        fprintf(out, "%s",no->dado);
        if (no->prox != NULL) fprintf(out," ");
        no = no->prox;
    }
    fprintf(out, "\n");
}

// metodos especiais do texto

int carrega_arquivo(Lista* li, char* nome) {
    if (li == NULL || nome == NULL) return ERRO;

    FILE* f = fopen(nome, "rt");

    if (f == NULL) return ERRO;

    char line[256];
    int eof = 0;

    while (fgets(line, sizeof(line), f) != NULL && !eof) {
        char *token = strtok(line, " \t\n\r");
        while (token != NULL) {
            if (strcmp(token, "FIM") == 0) {
                eof = 1;
                break;
            }
            insere_lista_final(li, token);
            token = strtok(NULL, " \t\n\r");
        }
    }

    move_cursor_inicio(li);

    fclose(f);

    return OK;
}

int salva_arquivo(Lista* li, char* nome) {
    if (li == NULL || nome == NULL) return ERRO;

    FILE* f = fopen(nome, "wt");

    if (f == NULL) return ERRO;

    imprime_lista(li, f);

    fclose(f);

    return OK;

}

int insere_antes_cursor(Lista* li, char* dt) {
    if (li == NULL) return ERRO;

    if (li->cursor == NULL) {
        insere_lista_inicio(li, dt);
        return OK;
    }

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return ERRO;

    strcpy(no->dado, dt);

    Elem* cursor = li->cursor;
    Elem* ant = cursor->ant;

    no->prox = cursor;
    no->ant = ant;

    cursor->ant = no;

    if (ant != NULL) {
        ant->prox = no;
    } else {
        li->inicio = no;
    }

    li->cursor = no;

    li->qtd++;
    return OK;
}

int insere_prox_cursor(Lista* li, char* dt) {
    if (li == NULL) return ERRO;

    if (li->cursor == NULL) {
        insere_lista_inicio(li, dt);
        return OK;
    }

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return ERRO;

    strcpy(no->dado, dt);

    Elem* cursor = li->cursor;
    Elem* prox = cursor->prox;

    no->ant = cursor;
    no->prox = prox;

    cursor->prox = no;

    if (prox != NULL) {
        prox->ant = no;
    } else {
        li->fim = no;
    }

    li->cursor = no;

    li->qtd++;
    return OK;
}

int procura_palavra(Lista* li, char* query) {
    if (li==NULL || li->cursor == NULL) return ERRO;
    Elem* no = li->cursor;
    while (no != NULL) {
        if (strcmp(no->dado, query) == 0) {
            li->cursor = no;
            return OK;
        }
        no = no->prox;
    }
    return ERRO;
}

int troca_palavra(Lista* li, char* query) {
    if (li == NULL || li->cursor == NULL) return ERRO;
    Elem* no = li->cursor;

    strcpy(no->dado, query);

    return OK;

}

int remove_atual(Lista* li) {
    if (li == NULL || li->cursor == NULL) return ERRO;

    Elem* no = li->cursor;
    Elem* ant = no->ant;
    Elem* prox = no->prox;

    if (ant != NULL) {
        ant->prox = prox;
    } else {
        li->inicio = prox;
    }

    if (prox != NULL) {
        prox->ant = ant;
    } else {
        li->fim = ant;
    }

    if (ant != NULL) {
        li->cursor = ant;
    } else {
        li->cursor = prox;
    }

    free(no);
    li->qtd--;

    return OK;
}

void exibe_estatistica(Lista* li) {
    if (li == NULL) return;
    printf("%d\n", tamanho_lista(li));
}

void imprime_texto(Lista* li) {
    if (li == NULL || li->inicio == NULL) return;
    imprime_lista(li, stdout);
}

void imprime_palavra(Lista* li) {
    if (li == NULL || li->inicio == NULL) return;
    Elem* no = li->cursor;
    if (no == NULL) return;
    printf("%s\n", no->dado);
    return;
}

void imprime_adjacente(Lista* li) {
    if (li == NULL || li->cursor == NULL) return;
    int ant = 0;
    Elem* no = li->cursor;
    while (no->ant != NULL) {
        if (ant >= 5) break;
        no = no->ant;
        ant++;
    }
    while (ant > 0) {
        printf("%s ", no->dado);
        no = no->prox;
        ant--;
    }
    int dep = 0;
    no = li->cursor;
    printf("%s ", no->dado);
    while (no->prox != NULL) {
        if (dep >= 5) break;
        no = no->prox;
        printf("%s", no->dado);
        dep++;
        if (dep < 5) printf(" ");

    }

    printf("\n");
    return;

}

void move_cursor_inicio(Lista* li) {
    if (li == NULL || li->inicio == NULL) return;
    li->cursor = li->inicio;
}

void move_cursor_final(Lista* li) {
    if (li == NULL || li->inicio == NULL) return;
    li->cursor = li->fim;
}

void move_cursor_prox (Lista* li) {
    if (li == NULL || li->inicio == NULL || li->cursor == NULL) return;
    if (li->cursor->prox != NULL)
        li->cursor = li->cursor->prox;
}

void move_cursor_ant(Lista* li) {
    if (li == NULL || li->inicio == NULL || li->cursor == NULL) return;
    if (li->cursor->ant != NULL)
        li->cursor = li->cursor->ant;
}

void escrita_continua(Lista* li) {
    if (li == NULL) return;
    char buffer[126];
    while (fgets(buffer, 126, stdin) != NULL) {
        char *token = strtok(buffer, " \t\n\r");
        while (token != NULL) {
            if (strcmp(token, "#") == 0) {
                return;
            }
            insere_prox_cursor(li, token);
            token = strtok(NULL, " \t\n\r");
        }
    }
}