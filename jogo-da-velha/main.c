#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

// flags bitwise
#define NONE 0
#define P1WIN 1
#define P2WIN 2

int endFlag;

int i, j;

int board[3][3] = {{0, 0,0},{0,0,0},{0,0,0}};

int turn, roundNum, input;

// prototype das funcoes
void printBoard();

int numToIndex(char a, int input);

int validateMov(int num);

void doMovement ();

void updateBoard(int i, int j);

void checkEndCondition();

int main()
{
    turn = 1;

    roundNum = 0;

    endFlag = NONE;

    do {
        doMovement();

        roundNum++;

        if(DEBUG) printf("[DEBUG] Round %d", roundNum);

    } while (endFlag == NONE);

    return 0;
}


// imprime o tabuleiro todo na tela
void printBoard()
{
    printf("Tabuleiro:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j <3; j++) {
            printf("%d ", board[i][j]);
        }

        printf("\n");

    }
}


// converte a entrada de 0 a 9 para um indice da matriz que representa o tabuleiro
int numToIndex(char a, int input)
{
    // retorna linha
    if(a == 'i') return (int)((input - 1) / 3);

    // retorna coluna
    if(a == 'j') return (int)((input - 1) % 3);

    return -1;
}

// valida um movimento
int validateMov(int num)
{
    if (num < 1 || num > 9) return 0;

    if(board[numToIndex('i', num)][numToIndex('j', num)] == 0) return 1;

    return 0;
}

// executa o movimento
void doMovement ()
{
    while(1){
        if (scanf("%d", &input) != 1) break;

        if (validateMov(input)){
            printf("Jogada Valida %d\n", input);
            break;
        };
        printf("Jogada Invalida %d\n", input);
        printf("Jogador %d joga agora!\n", turn);
        printBoard();
    }

    updateBoard(numToIndex('i', input), numToIndex('j', input));

    if(roundNum > 3) checkEndCondition();

    if (endFlag == NONE) {
        turn = 3 - turn;

        printf("Jogador %d joga agora!\n", turn);
    } else {
        if  (endFlag & P1WIN) printf("Jogador 1 venceu!\n");
        if  (endFlag & P2WIN) printf("Jogador 2 venceu!\n");
    }

    printBoard();
}


void updateBoard(int i, int j)
{
    board[i][j] = turn;
}

void checkEndCondition() {

    // checa vitoria nas colunas
    for(i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0) {
            endFlag |= (board[i][0] == 1) ? P1WIN : P2WIN;
            return;
        }
    }

    // checa vitoria nas linhas
    for(i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0) {
            endFlag |= (board[0][i] == 1) ? P1WIN : P2WIN;
            return;
        }
    }

    if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        endFlag |= (board[1][1] == 1) ? P1WIN : P2WIN;
        return;
    }

    if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        endFlag |= (board[1][1] == 1) ? P1WIN : P2WIN;
        return;
    }

}
