#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h" //inclui os Protótipos

// Local functions (Prototipo da funcao)
void libera_NO_AVL(struct NO_AVL* no);
int altura_NO_AVL(struct NO_AVL* no);
struct NO_AVL* procuraMenor_AVL(struct NO_AVL* atual);
int fatorBalanceamento_NO_AVL(struct NO_AVL* no);
int maior(int x, int y);
void RotacaoLL(ArvAVL *A);
void RotacaoRR(ArvAVL *A);
void RotacaoLR(ArvAVL *A);
void RotacaoRL(ArvAVL *A);


// struct NO_AVL* remove_atual(struct NO* atual);

ArvAVL* cria_ArvAVL(){
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO_AVL(struct NO_AVL* no){
    if(no == NULL)
        return;
    libera_NO_AVL(no->esq);
    libera_NO_AVL(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvAVL(ArvAVL* raiz){
    if(raiz == NULL)
        return;
    libera_NO_AVL(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int altura_NO_AVL(struct NO_AVL* no){
    if(no == NULL)
        return -1;
    else
    return no->altura;
}

int fatorBalanceamento_NO_AVL(struct NO_AVL* no){
    return labs(altura_NO_AVL(no->esq) - altura_NO_AVL(no->dir));
}

int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

int estaVazia_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

void preOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        //printf("%d\n",(*raiz)->info);
        //printf("No %d: %d\n",(*raiz)->info,fatorBalanceamento_NO(*raiz));
        printf("No %d - ",(*raiz)->info);

        if ((*raiz)->esq != NULL) // Tem Esquerda?
            printf("Esq: %d - ",(*raiz)->esq->info);
        else
            printf("Esq: NULL - ");

        if ((*raiz)->dir != NULL) // Tem Direita?
            printf("Dir: %d \n",(*raiz)->dir->info);
        else
            printf("Dir: NULL \n");
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void emOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvAVL(&((*raiz)->esq));
        //printf("%d\n",(*raiz)->info);
        //printf("No %d: H(%d) fb(%d)\n",(*raiz)->info,altura_NO_AVL(*raiz),fatorBalanceamento_NO_AVL(*raiz));
        printf("Dado: %d\n",(*raiz)->info);
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void posOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);
    }
}

int consulta_ArvAVL(ArvAVL *raiz, Tipo_Dado valor){
    if(raiz == NULL)
        return 0;
    struct NO_AVL* atual = *raiz;
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

//=================================
void RotacaoLL(ArvAVL *A){//LL
    printf("RotacaoLL\n");
    struct NO_AVL *B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = *A;
    (*A)->altura = maior(altura_NO_AVL((*A)->esq),altura_NO_AVL((*A)->dir)) + 1;
    B->altura = maior(altura_NO_AVL(B->esq),(*A)->altura) + 1;
    *A = B;
}

void RotacaoRR(ArvAVL *A){//RR
    printf("RotacaoRR\n");
    struct NO_AVL *B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->altura = maior(altura_NO_AVL((*A)->esq),altura_NO_AVL((*A)->dir)) + 1;
    B->altura = maior(altura_NO_AVL(B->dir),(*A)->altura) + 1;
    (*A) = B;
}

void RotacaoLR(ArvAVL *A){//LR
    RotacaoRR(&(*A)->esq);
    RotacaoLL(A);
}

void RotacaoRL(ArvAVL *A){//RL
    RotacaoLL(&(*A)->dir);
    RotacaoRR(A);
}

int insere_ArvAVL(ArvAVL *raiz, Tipo_Dado valor){
    int res;
    if(*raiz == NULL){//árvore vazia ou nó folha
        struct NO_AVL *novo;
        novo = (struct NO_AVL*)malloc(sizeof(struct NO_AVL));
        if(novo == NULL)
            return 0;

        novo->info = valor;
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO_AVL *atual = *raiz;
    if(valor < atual->info){
        if((res = insere_ArvAVL(&(atual->esq), valor)) == 1){
            if(fatorBalanceamento_NO_AVL(atual) >= 2){
                if(valor < (*raiz)->esq->info ){
                    RotacaoLL(raiz);
                }else{
                    RotacaoLR(raiz);
                }
            }
        }
    }else{
        if(valor > atual->info){
            if((res = insere_ArvAVL(&(atual->dir), valor)) == 1){
                if(fatorBalanceamento_NO_AVL(atual) >= 2){
                    if((*raiz)->dir->info < valor){
                        RotacaoRR(raiz);
                    }else{
                        RotacaoRL(raiz);
                    }
                }
            }
        }else{
            printf("Valor duplicado!!\n");
            return 0;
        }
    }

    atual->altura = maior(altura_NO_AVL(atual->esq),altura_NO_AVL(atual->dir)) + 1;

    return res;
}

struct NO_AVL* procuraMenor_AVL(struct NO_AVL* atual){
    struct NO_AVL *no1 = atual;
    struct NO_AVL *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

int remove_ArvAVL(ArvAVL *raiz, int valor){
	if(*raiz == NULL){// valor não existe
	    printf("valor não existe!!\n");
	    return 0;
	}

    int res;
	if(valor < (*raiz)->info){
	    if((res = remove_ArvAVL(&(*raiz)->esq,valor)) == 1){
            if(fatorBalanceamento_NO_AVL(*raiz) >= 2){
                if(altura_NO_AVL((*raiz)->dir->esq) <= altura_NO_AVL((*raiz)->dir->dir))
                    RotacaoRR(raiz);
                else
                    RotacaoRL(raiz);
            }
	    }
	}

	if((*raiz)->info < valor){
	    if((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1){
            if(fatorBalanceamento_NO_AVL(*raiz) >= 2){
                if(altura_NO_AVL((*raiz)->esq->dir) <= altura_NO_AVL((*raiz)->esq->esq) )
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
	    }
	}

	if((*raiz)->info == valor){
	    if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)){// nó tem 1 filho ou nenhum
			struct NO_AVL *oldNode = (*raiz);
			if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
			free(oldNode);
		}else { // nó tem 2 filhos
			struct NO_AVL* temp = procuraMenor_AVL((*raiz)->dir);
			(*raiz)->info = temp->info;
			remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);
            if(fatorBalanceamento_NO_AVL(*raiz) >= 2){
				if(altura_NO_AVL((*raiz)->esq->dir) <= altura_NO_AVL((*raiz)->esq->esq))
					RotacaoLL(raiz);
				else
					RotacaoLR(raiz);
			}
		}
		if (*raiz != NULL)
            (*raiz)->altura = maior(altura_NO_AVL((*raiz)->esq),altura_NO_AVL((*raiz)->dir)) + 1;
		return 1;
	}

	(*raiz)->altura = maior(altura_NO_AVL((*raiz)->esq),altura_NO_AVL((*raiz)->dir)) + 1;

	return res;
}
