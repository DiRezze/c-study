#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABO.h"

ArvBin* cria_ArvBin(void){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);
    free(raiz);
}

int insere_ArvBin(ArvBin* raiz, Tipo_Dados valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    
    strcpy(novo->info.orig, valor.orig);
    strcpy(novo->info.trad, valor.trad);
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(strcmp(valor.orig, atual->info.orig) == 0 ){
                // elemento j� existe
                free(novo);
                return 0;
            }

            if(strcmp(valor.orig, atual->info.orig) > 0)
                // mover para a direta
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(strcmp(valor.orig, ant->info.orig) > 0)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
int remove_ArvBin(ArvBin *raiz, Tipo_Dados valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(strcmp(valor.orig, atual->info.orig)==0){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(strcmp(valor.orig, atual->info.orig) > 0)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

int consulta_ArvBin(ArvBin *raiz, char* valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(strcmp(valor, atual->info.orig)==0){
            return 1;
        }
        if(strcmp(valor, atual->info.orig) > 0)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

char* consulta_traducao(ArvBin *raiz, char* orig) {
    if(raiz == NULL) return NULL;
    struct NO* atual = *raiz;
    int consultados = 0;

    while (atual != NULL) {
        consultados++;
        int comp = strcmp(orig, atual->info.orig);

        if (comp == 0) {
            size_t tam = strlen(atual->info.trad) + 20;
            char* out = malloc(tam);
            if (out == NULL) return NULL;

            snprintf(out, tam, "%s %d", atual->info.trad, consultados);
            return out;
        }

        if (comp > 0) {
            atual = atual->dir;
        } else {
            atual = atual->esq;
        }
    }

    return NULL;
}

void preOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%s -> %s\n",(*raiz)->info.orig, (*raiz)->info.trad);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%s -> %s\n",(*raiz)->info.orig, (*raiz)->info.trad);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_Simplificado(ArvBin *raiz)
{
    if(raiz != NULL && *raiz != NULL){
        emOrdem_Simplificado(&((*raiz)->esq));
        printf("%s %s\n",(*raiz)->info.orig, (*raiz)->info.trad);
        emOrdem_Simplificado(&((*raiz)->dir));
    }
}

void emOrdemInversa_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdemInversa_ArvBin(&((*raiz)->dir));
        printf("%s -> %s\n",(*raiz)->info.orig, (*raiz)->info.trad);
        emOrdemInversa_ArvBin(&((*raiz)->esq));
    }
}


void posOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%s -> %s\n",(*raiz)->info.orig, (*raiz)->info.trad);
    }
}

// Funcoes Adicionais de Arvore

void Procura_preOrdem_ArvBin(ArvBin *raiz, Tipo_Dados valor, int *achou)
{
    if(raiz == NULL)
        return;
    if (*achou)
        return;
    if(*raiz != NULL)
    {
        if (strcmp(valor.orig, (*raiz)->info.orig) == 0)
        {
            printf("Achou: %s %s! \n",(*raiz)->info.orig, (*raiz)->info.trad);
            *achou=1;
        }
        Procura_preOrdem_ArvBin(&((*raiz)->esq),valor,achou);
        Procura_preOrdem_ArvBin(&((*raiz)->dir),valor,achou);
    }
}

void Exibe_emOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;

    if(*raiz != NULL)
    {
        printf("Atual: %s - Vai para Esquerda \n",(*raiz)->info.orig);
        Exibe_emOrdem_ArvBin(&((*raiz)->esq));
        printf("Dado : %s \n",(*raiz)->info.orig);
        printf("Atual: %s - Vai para Direita \n",(*raiz)->info.orig);
        Exibe_emOrdem_ArvBin(&((*raiz)->dir));
        printf("Feito(%s) \n",(*raiz)->info.orig);
    }
    else
        printf("NULL\n");

}

int carrega_arquivo(char* path, ArvBin* target) {
    if(target == NULL || path == NULL) return -1;
    
    int read = 0;
    
    FILE* f = fopen(path, "rt");
    if(f == NULL) return -1;
    
    char buffer[256];
    
    while(fgets(buffer, sizeof(buffer), f) != NULL) {
        char* token = strtok(buffer, " \t\n\r");
        
        if(token == NULL) continue;
        if(token[0] == '#') break;
        
        Tipo_Dados newNode;
        
        strncpy(newNode.orig, token, sizeof(newNode.orig) - 1);
        
        token = strtok(NULL, " \t\n\r");
        if(token == NULL) continue;
        
        strncpy(newNode.trad, token, sizeof(newNode.trad) - 1);
        
        insere_ArvBin(target, newNode);
        
        read++;
    }
    fclose(f);
    
    return read;
}
