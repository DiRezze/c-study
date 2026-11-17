//  Arquivo ArvoreAVL.h
//  TAD: Arvore Balanceada AVL - v3

#ifndef FALSO
#define FALSO      0
#define VERDADEIRO 1
#endif

#ifndef OK
#define OK         1
#define ERRO       0
#endif

typedef int Tipo_Dado;

//Definição do tipo Arvore
struct NO_AVL{
    Tipo_Dado info;
	int  altura;
    struct NO_AVL *esq;
    struct NO_AVL *dir;
};

typedef struct NO_AVL NodoArvAVL;
typedef struct NO_AVL *ArvAVL;

ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);
int insere_ArvAVL(ArvAVL *raiz, Tipo_Dado dado);
int remove_ArvAVL(ArvAVL *raiz, Tipo_Dado valor);
int estaVazia_ArvAVL(ArvAVL *raiz);
int altura_ArvAVL(ArvAVL *raiz);
int totalNO_ArvAVL(ArvAVL *raiz);
int consulta_ArvAVL(ArvAVL *raiz, Tipo_Dado valor);
void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz);
void posOrdem_ArvAVL(ArvAVL *raiz);

