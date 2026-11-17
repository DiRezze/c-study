#include <stdio.h>
#include <stdlib.h>

//Declaracao da funcao fatorial
long int fatorial(long int n);

int main(void)
{
  long int numero;
  long int f;

  printf(">> Fatorial << \n\n");
  printf("Digite o numero que deseja calcular o fatorial: ");
  scanf("%ld",&numero);

  //chamada da funcao fatorial
  printf("Chamada inicial: Fatorial(%ld)\n",numero);
  f = fatorial(numero);

  printf("Fatorial(%ld) = %ld \n\n",numero,f);

  system ("Pause");
  return 0;
}

//Função recursiva que calcula o fatorial
//de um numero inteiro n
long int fatorial(long int n)
{
  long int temp;

  printf("Executa: Fatorial(%ld)\n",n);
  // Corte da recursao
  if ( n == 0 )
  {
     // Fatorial(0) eh 1
     printf("Retorna FIM: Fatorial(0)=1 \n");
     return (1);
  }
  else
  {
     // Fatorial(n) eh  N * Fatorial (n-1)
     printf("Chama: Fatorial(%ld)\n",n-1);
     temp = n * fatorial(n - 1);
     printf("Retorna: Fatorial(%ld) = %ld \n",n, temp);
     return( temp );
  }
}
