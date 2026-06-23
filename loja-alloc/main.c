#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buffer[128];
int num, i, j;

char (*pLavras)[50];

typedef struct {
    int nro;
    float val;
} Produto;

Produto *pProducts;

int main()
{
    fgets(buffer, sizeof(buffer), stdin);
    num = atoi(buffer);

    pProducts = (Produto *) calloc(num, sizeof(Produto) * num);

    for(i = 0; i < num; i++) {
        fgets(buffer, sizeof(buffer), stdin);

        pProducts[i].nro = atoi(buffer);

        fgets(buffer, sizeof(buffer), stdin);

        pProducts[i].val = atof(buffer);
    }

    for(i = 0; i < num; i++) {
        printf("P %d\n", i);
        printf("# %d\n", pProducts[i].nro);
        printf("$ %.2f\n", pProducts[i].val);
    }

    free(pProducts);

    printf("X\n");

    return 0;
}
