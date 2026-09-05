#ifndef ATV2_LISTASEQUENCIAL_H
#define ATV2_LISTASEQUENCIAL_H
//Arquivo ListaSequencial.h

struct s_dado { double valor; };

typedef struct s_dado tipo_dado;

//Definição do tipo lista
struct s_lista{
    int qtd;
    int max;
    char nome[32];
    tipo_dado* dados;
};

typedef struct s_lista Lista;

Lista* cria_lista(int max, char* nome);
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

#endif //ATV2_LISTASEQUENCIAL_H
