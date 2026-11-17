#include <stdio.h>
#include <stdlib.h>

void ContaRe (int Contador)
{
    if (Contador < 0)
    {
        return;
    }
    printf("Contagem: %d\n", Contador);
    Contador--;
    ContaRe(Contador);
    return;
}

int main()
{
    int Contador=10;

    printf("Contagem Regressiva Recursiva!\n");
    ContaRe(Contador);
    printf("Fim!\n");
    return 0;
}

