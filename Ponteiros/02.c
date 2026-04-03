#include <stdio.h>


int main(){
  // cria variavel
  int n = 5;
  // cria ponteiro e inicializa com o endereço da variavel n
  int *pn = &n;
  // troca o valor da variavel n usando o ponteiro
  *pn = 20;

  // amostra que o valor foi trocado
  printf("valor: %d", n);

  return 0;
}
