
//Arquivo LDED.h - Lista Dinamica Encadeada Dupla: Extended Lini,Lfim,Lcursor

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

typedef struct {
    char prefixo[5];
    char palavra[50];
    int usos;
} Tipo_Dados;

//Definição do tipo lista
struct elemento{
    struct elemento *ant;
    Tipo_Dados dado;
    struct elemento *prox;
};

typedef struct elemento Elem;

struct LDEDptrs{
  struct elemento *Lini;
  struct elemento *Lfim;
  struct elemento *Lcursor;
};

typedef struct LDEDptrs LDED;

LDED* cria_lista();
void libera_lista(LDED* li);
int consulta_lista_dado(LDED* li, char* prefixo);
int insere_lista_ordenado(LDED* li, Tipo_Dados* dt);
void imprime_lista(LDED* li);

int le_arquivo(LDED* li, char* path);
