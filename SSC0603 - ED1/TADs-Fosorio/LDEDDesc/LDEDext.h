//Arquivo LDED.h - Lista Dinamica Encadeada Dupla: Extended Lini,Lfim,Lcursor

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

typedef int  Tipo_Dado;

//Definição do tipo lista
struct elemento{
    struct elemento *ant;
    Tipo_Dado dado;
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
int consulta_lista_dado(LDED* li, Tipo_Dado dt, Elem **el);
int insere_lista_final(LDED* li, Tipo_Dado dt);
int insere_lista_inicio(LDED* li, Tipo_Dado dt);
// int insere_lista_ordenada(LDED* li, Tipo_Dado dt);
// int remove_lista(LDED* li, Tipo_Dado dt);
// int remove_lista_inicio(LDED* li);
// int remove_lista_final(LDED* li);
int tamanho_lista(LDED* li);
int lista_vazia(LDED* li);
int lista_cheia(LDED* lista);
void imprime_lista(LDED* li);
