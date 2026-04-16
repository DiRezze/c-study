#include <stdio.h>
#include <stdlib.h>

#define ERRO_DIA 1
#define ERRO_MES 2
#define ERRO_ANO 4
#define BISSEXTO 8

int dia, mes, ano;

int flags = 0;

int main()
{

    scanf("%d %d %d", &dia, &mes, &ano);

    if (ano <= 0) flags |= ERRO_ANO;

    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        flags |= BISSEXTO;
    }

    if(mes < 1 || mes > 12) flags |= ERRO_MES;

    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        flags |= (dia > 31 || dia < 1) ? ERRO_DIA : 0;
    }

    if(mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        flags |= (dia > 30 || dia < 1) ? ERRO_DIA : 0;
    }

    if(mes==2 && (flags & BISSEXTO)){
        flags |= (dia > 29 || dia < 1) ? ERRO_DIA : 0;
    }

    if(mes==2 && !(flags & BISSEXTO)){
        flags |= (dia > 28 || dia < 1) ? ERRO_DIA : 0;
    }

    if ((flags & (ERRO_DIA | ERRO_MES | ERRO_ANO)) == 0){
        printf("VALID DATE\n");
    } else {
        printf("INVALID DATE\n");
    }

    return 0;

}
