#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_ARQ "master.txt"
#define NOME_SAIDA "final.txt"
#define DEBUG 0

typedef struct {
    int numero;
    char nomeCliente[30];
    double saldo;
} Conta;

// declaracao das subrotinas do programa definidas no documento
int le_menu_opcao(void);
int le_arquivo(char *nome);
int grava_arquivo(char *nome, int nClientes);
int procura_conta(int conta);
double deposito(int nCliente, double valor);
double saque(int nCliente, double valor);
void transfere(double *saldo1, double *saldo2);
void exibe_saldo_conta(int conta);
void exibe_contas(void);

// subrotinas extras
/**
*    @brief libera a mem�ria alocada, fecha arquivos que possam estar abertos e encerra o programa
*/
void end_program(void);

// vari�veis de controle do programa
char buffer[126];
int isAccountsLoaded, numLido, query;
double qVal, resultado;
FILE *Arq;

// dados do programa
Conta *contas;

int main(){
    isAccountsLoaded = 0;
    while(1) {
        switch(le_menu_opcao()) {
            case 0:
                end_program();
                break;
            case 1:
                le_arquivo(NOME_ARQ);
                break;
            case 2:
                fgets(buffer, sizeof(buffer), stdin);
                query = atoi(buffer);
                fgets(buffer, sizeof(buffer), stdin);
                qVal = atof(buffer);
                if(DEBUG) printf("DEBUG: Buscando a conta numero: %d\n", query);
                resultado = deposito(query, qVal);
                if(resultado >=0)
                    printf("SALDO %.2f\n", resultado);
                break;
            case 3:
                fgets(buffer, sizeof(buffer), stdin);
                query = atoi(buffer);
                fgets(buffer, sizeof(buffer), stdin);
                qVal = atof(buffer);
                if(DEBUG) printf("DEBUG: Buscando a conta numero: %d\n", query);
                resultado = saque(query, qVal);
                printf("SALDO %.2f\n", resultado);
                break;
            case 4:
                fgets(buffer, sizeof(buffer), stdin);
                int q1 = atoi(buffer);
                fgets(buffer, sizeof(buffer), stdin);
                int q2 = atoi(buffer);
                int idx1 = procura_conta(q1);
                int idx2 = procura_conta(q2);
                if (idx1 < 0 || idx2 < 0) break;
                transfere(&contas[idx1].saldo, &contas[idx2].saldo);
                break;
            case 5:
                fgets(buffer, sizeof(buffer), stdin);
                query = atoi(buffer);
                exibe_saldo_conta(query);
                break;
            case 6:
                exibe_contas();
                break;
            case 7:
                grava_arquivo(NOME_SAIDA, numLido);
                break;
            default:
                break;

        }
    }

    return 0;
}

// definicao das subrotinas do programa
int le_menu_opcao() {
    char buffer[32];
    fgets(buffer, sizeof(buffer), stdin);
    return atoi(buffer);
}

void end_program(){
    if (Arq != NULL) {
        fclose(Arq);
    }
    if (contas != NULL) {
        free(contas);
        contas = NULL;
    }

    exit(0);
}

int le_arquivo(char *nome) {
    Arq = fopen(nome, "rt");

    if(!Arq){
        printf("ERRO ARQUIVO \n");
        return -1;
    };

    int numArq, numReal;

    numReal = 0;

    fgets(buffer, sizeof(buffer), Arq);

    numArq = atoi(buffer);

    contas = (Conta *)malloc(numArq * sizeof(Conta));

    for(int i = 0; i < numArq; i++) {
        fgets(buffer, sizeof(buffer), Arq);
        if(buffer[0] == '#') break;
        contas[i].numero = atoi(buffer);


        fgets(buffer, sizeof(buffer), Arq);
        buffer[strcspn(buffer, "\r\n")] = '\0';
        strncpy(contas[i].nomeCliente, buffer, sizeof(contas[i].nomeCliente)-1);
        contas[i].nomeCliente[sizeof(contas[i].nomeCliente)-1] = '\0';

        fgets(buffer, sizeof(buffer), Arq);
        contas[i].saldo = atof(buffer);

        numReal++;

        if(DEBUG) printf("Indice %d -> ID: [%d] | Nome: [%s] | Saldo: [%.2f]\n",
               i, contas[i].numero, contas[i].nomeCliente, contas[i].saldo);
    }

    fclose(Arq);
    Arq = NULL;

    printf("LIDOS %d\n", numReal);

    isAccountsLoaded = 1;

    numLido = numReal;

    return numReal;
}

int grava_arquivo(char* nome, int nClientes) {
    if(!isAccountsLoaded) return -2;
    Arq = fopen(nome, "wt");

    if(!Arq){
        printf("ERRO ARQUIVO \n");
        return -1;
    };
    fprintf(Arq, "%d", nClientes);
    for(int i = 0; i < nClientes; i++) {
        fprintf(Arq, "%d\n%s\n%.2f\n",  contas[i].numero, contas[i].nomeCliente, contas[i].saldo);
    }
    fprintf(Arq, "#\n");

    printf("GRAVADOS %d\n", nClientes);
    fclose(Arq);
    Arq = NULL;

}

int procura_conta(int conta){
    if(!isAccountsLoaded) return -2;

    for(int i = 0; i < numLido; i++) {
        if(contas[i].numero == conta) return i;
    }

    printf("ERRO CONTA \n");

    return -1;
}

double deposito(int nCliente, double valor) {
    if(!isAccountsLoaded) return -2;
    int i = procura_conta(nCliente);
    if(i < 0) {
        return -1;
    }
    contas[i].saldo += valor;
    return contas[i].saldo;
}

double saque(int nCliente, double valor) {
    if(!isAccountsLoaded) return -2;
    int i = procura_conta(nCliente);
    contas[i].saldo -= valor;
    return contas[i].saldo;
}

void exibe_saldo_conta(int conta) {
    if(!isAccountsLoaded) return;
    int i = procura_conta(conta);
    if(i >= 0){
            printf("%d\n%s\n%.2f\n",contas[i].numero, contas[i].nomeCliente, contas[i].saldo);
    }
}

void exibe_contas() {
    printf("CONTAS %d\n", numLido);
    for(int i = 0; i < numLido; i++) {
        printf("%d\n%s\n%.2f\n",  contas[i].numero, contas[i].nomeCliente, contas[i].saldo);
    }
}

void transfere(double* saldo1, double* saldo2) {
    double temp = *saldo1;
    *saldo1 = *saldo2;
    *saldo2 = temp;
    printf("TRANSF OK\n");
}
