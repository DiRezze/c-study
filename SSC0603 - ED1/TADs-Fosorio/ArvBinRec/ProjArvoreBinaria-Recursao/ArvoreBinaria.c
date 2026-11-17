#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h" //inclui os Protótipos

ArvBin* Nodo_atual;

ArvBin* cria_ArvBin(){
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
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int insere_ArvBin(ArvBin* raiz, Tipo_Dado valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;//elemento já existe
            }

            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
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
    // no2 é o nó anterior a r na ordem e-r-d
    // no1 é o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}
// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
int remove_ArvBin(ArvBin *raiz, Tipo_Dado valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
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
        if(valor > atual->info)
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

//
// BUSCA BINÁRIA na ABB
//
int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

//
// EXIBICAO ARVORE em Pre-Ordem
// TODOS nodos - Percoree de modo EXAUSTIVO
//
void preOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->info);          // Info é Int
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
        printf("%d\n",(*raiz)->info);          // Info é Int
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);         // Info é Int
    }
}

// Funcoes Adicionais de Arvore

//
// BUSCA ATE ENCONTRAR em Pre-Ordem (COM CORTE!)
// USA FLAG "Global"
//

int Procura_preOrdem_Com_Corte_ArvBin(ArvBin *raiz, Tipo_Dado valor, int *achou)
{
    int retesq,retdir;

    if(raiz == NULL)
        return 0;
    if (*achou)
        return 1;

    if(*raiz != NULL)
    {
        if (valor == (*raiz)->info)
        {
            printf("Achou: %d! \n",(*raiz)->info);   // Info é Int
            *achou=1;
            Nodo_atual=raiz;
            return 1;
        }
        if (!(*achou)) retesq=Procura_preOrdem_Com_Corte_ArvBin(&((*raiz)->esq), valor, achou);
        if (!(*achou)) retdir=Procura_preOrdem_Com_Corte_ArvBin(&((*raiz)->dir), valor, achou);
        if (retesq  || retdir) return 1;
        else return 0;
    }
    else
        return 0;
}

int Exibe_preOrdem_Com_Corte_ArvBin(ArvBin *raiz, Tipo_Dado valor, int *achou)
{
    int retesq, retdir;

    if(raiz == NULL)
        return 0;
    if (*achou)
        return 1;

    if(*raiz != NULL)
    {
        printf("Visita Dado : %d \n",(*raiz)->info);

        if (valor == (*raiz)->info)
        {
            printf("Achou: %d! \n",(*raiz)->info);   // Info é Int
            *achou=1;
            return 1;
        }
        if (!(*achou))
        {
            printf("Atual: %d - Vai para Esquerda \n",(*raiz)->info);   // Info é Int
            retesq = Exibe_preOrdem_Com_Corte_ArvBin(&((*raiz)->esq),valor,achou);
        }
        if (!(*achou))
        {
            printf("Atual: %d - Vai para Direita \n",(*raiz)->info);    // Info é Int
            retdir = Exibe_preOrdem_Com_Corte_ArvBin(&((*raiz)->dir),valor,achou);
        }
        printf("Feito(%d) \n",(*raiz)->info);                       // Info é Int
        if (retesq  || retdir) return 1;
        else return 0;
    }
    else
    {
        printf("Fim Arvore\n");
        return 0;
    }
}

void Exibe_emOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;

    if(*raiz != NULL)
    {
        printf("Atual: %d - Vai para Esquerda \n",(*raiz)->info);   // Info é Int
        Exibe_emOrdem_ArvBin(&((*raiz)->esq));
        printf("Dado : %d \n",(*raiz)->info);
        printf("Atual: %d - Vai para Direita \n",(*raiz)->info);    // Info é Int
        Exibe_emOrdem_ArvBin(&((*raiz)->dir));
        printf("Feito(%d) \n",(*raiz)->info);                       // Info é Int
    }
    else
        printf("NULL\n");

}
