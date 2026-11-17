//  Arquivo ArvBinaria.h
//  TAD: ProjArvoreBinaria-V2

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

typedef struct {
    char orig[20];
    char trad[20];
} Tipo_Dados;

//Defini��o do tipo Arvore
struct NO{
    Tipo_Dados info;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO NodoArvBin;
typedef struct NO *ArvBin;

ArvBin* cria_ArvBin(void);
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin *raiz, Tipo_Dados valor);
int remove_ArvBin(ArvBin *raiz, Tipo_Dados valor);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, char* valor);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);

void emOrdem_Simplificado(ArvBin *raiz);
void emOrdemInversa_ArvBin(ArvBin *raiz);

// Funcoes Adicionais
void Procura_preOrdem_ArvBin(ArvBin *raiz, Tipo_Dados valor, int *achou);
void Exibe_emOrdem_ArvBin(ArvBin *raiz);

int carrega_arquivo(char* path, ArvBin* target);
char* consulta_traducao(ArvBin *raiz, char* orig);
