#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *Arq;

double num[10];

int i;

int main()
{
    Arq = fopen("nros.bin", "rb");

    if  (Arq){
       fread(num,sizeof(double),10,Arq);
       fclose(Arq);
   }
   else  printf ("FILE OPEN ERROR\n");

    for(i = 0; i < 10; i++) {
        printf("%.2lf\n", num[i]);
    }

    return 0;
}
