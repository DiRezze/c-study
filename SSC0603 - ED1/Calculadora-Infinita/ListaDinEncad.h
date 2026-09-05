//Arquivo ListaDinEncad.h

#define FALSO      0
#define VERDADEIRO 1

#define OK          1
#define ERRO       -1

typedef int Tipo_Dado;

struct elemento{
    Tipo_Dado dado;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, Tipo_Dado dt);
int insere_lista_inicio(Lista* li, Tipo_Dado dt);
int insere_lista_ordenada(Lista* li, Tipo_Dado dt);
int remove_lista(Lista* li, Tipo_Dado dt);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
void imprime_lista(Lista* li);
int soma_numeros(Lista* n1, Lista* n2, Lista* resultado);
int normaliza_numero(Lista* li, int qtd_zeros);