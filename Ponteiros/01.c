#include <stdio.h>

// funcao main
int main(){
  // variaveis
  int x = 7;
  int *px = &x;
  // o primeiro printf imprimi os valores dentro da variavel, primeiramente usando a variavel
  // e o segundo usando o ponteiro que aponta para a variavel
  printf("valor de x: %d; valor do ponteiro de x: %d\n;", x, *px);
  // o segudno printf imprimi os endereços da variavel primeiramente usando a variavel
  // e depois o ponteiro para amostrar que eles tem os mesmos endereços
  printf("valor de memoria de x: %p; valor de memoria do ponteiro de x: %p;", &x, px);
  return 0;
}
