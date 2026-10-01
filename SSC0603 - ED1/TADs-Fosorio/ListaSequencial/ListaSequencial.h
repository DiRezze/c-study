//Arquivo ListaSequencial.h

#define MAX 100    // Estrutura pre-alocada: Estatica

struct s_dado { int valor; };

typedef struct s_dado tipo_dado;

//Definição do tipo lista
struct s_lista{
    int qtd;
    tipo_dado dados[MAX];
};

typedef struct s_lista Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int consulta_lista_pos(Lista* li, int pos, tipo_dado *dado);
int insere_lista_final(Lista* li, tipo_dado dado);
int insere_lista_inicio(Lista* li, tipo_dado dado);
int insere_lista_ordenada(Lista* li, tipo_dado dado);
int remove_lista(Lista* li, tipo_dado dado);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);

int remove_lista_otimizado(Lista* li, tipo_dado dado);
