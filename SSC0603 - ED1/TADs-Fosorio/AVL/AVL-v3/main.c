#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main(){
    ArvAVL* avl;
    int res,i;
    //int N = 10, dados[10] = {50,25,10,5,7,3,30,20,8,15};
    int N = 10, dados[10] = {1,2,3,10,4,5,9,7,8,6};

    avl = cria_ArvAVL();

    for(i=0;i<N;i++){
        printf("========================\n");
        printf("Inserindo: %d\n",dados[i]);
        res = insere_ArvAVL(avl,dados[i]);
        if (res==ERRO) printf(">> Erro na insercao!\n");
    }

    printf("\n\n");
    printf("AVL tree em Ordem:\n");
    emOrdem_ArvAVL(avl);
    printf("> Total de Nodos: %d\n",totalNO_ArvAVL(avl));
    printf("> Altura da AVL : %d\n",altura_ArvAVL(avl));

    printf("\n");


    system("Pause");

    printf("\n\n");
    printf("## AVL tree em Pre-Ordem:\n");
    preOrdem_ArvAVL(avl);
    printf("\n");

    system("Pause");

    remove_ArvAVL(avl,6);
    printf("\nAVL tree Removido nodo 6:\n");
    emOrdem_ArvAVL(avl);
    printf("\n\n");

    system("Pause");

    remove_ArvAVL(avl,7);
    printf("\nAVL tree Removido nodo 7:\n");
    emOrdem_ArvAVL(avl);
    printf("\n\n");

    system("Pause");

    remove_ArvAVL(avl,4);
    printf("\nAVL tree Removido nodo 4:\n");
    emOrdem_ArvAVL(avl);
    printf("\n\n");

    system("Pause");

    printf("\n## AVL tree em Pre-Ordem:\n");
    preOrdem_ArvAVL(avl);
    printf("\n");

    printf("> Total de Nodos: %d\n",totalNO_ArvAVL(avl));
    printf("> Altura da AVL : %d\n",altura_ArvAVL(avl));

    system("Pause");

    libera_ArvAVL(avl);

    return 0;
}
