#include <stdio.h>

void troca(int *a, int *b){
  // para trocar o valores das variaveis é necessario 
  // guardar temporariamente o valor da primeira variavel que
  // sera trocado
  int c = *a;
  *a = *b;
  *b = c;
}

int main(){
  // cria e declara
  int a = 3, b = 5;
  // passa endereços
  troca(&a, &b);

  // imprimi resultados
  printf("a = %d; b = %d", a, b);

  return 0;
}
