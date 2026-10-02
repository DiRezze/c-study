// TAD personalizado: Texto

// Orginal: Arquivo LDED.h - Lista Dinamica Encadeada Dupla

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

typedef char Palavra[32];

typedef struct elemento{
    struct elemento *ant;
    Palavra dado;
    struct elemento *prox;
} Elem;

typedef struct {
    Elem *inicio;
    Elem *fim;
    Elem *cursor;
    int qtd;
} Lista;

// metodos base do TAD
Lista* cria_lista();
void libera_lista(Lista* li);
int consulta_lista_pos(Lista* li, int pos, Palavra *dt);
int consulta_lista_dado(Lista* li, Palavra dt, Elem **el);
int insere_lista_final(Lista* li, Palavra dt);
int insere_lista_inicio(Lista* li, Palavra dt);
int remove_lista(Lista* li, Palavra dt);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista_debug(Lista* li);
void imprime_lista(Lista* li, FILE* out);


// metodos especiais do texto
int carrega_arquivo(Lista* li, char* nome);
int salva_arquivo(Lista* li, char* nome);

int insere_antes_cursor(Lista* li, char* dt);
int insere_prox_cursor(Lista* li, char* dt);

int procura_palavra(Lista* li, char* query);

int troca_palavra(Lista* li, char* dt);

int remove_atual(Lista* li);

void exibe_estatistica(Lista* li);

void imprime_texto(Lista* li);
void imprime_palavra(Lista* li);
void imprime_adjacente(Lista* li);

void move_cursor_inicio(Lista* li);
void move_cursor_final(Lista* li);
void move_cursor_prox(Lista* li);
void move_cursor_ant(Lista* li);

void escrita_continua(Lista* li);
