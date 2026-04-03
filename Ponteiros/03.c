#include <stdio.h>

// uma fuçao que recebe os endereços como valores de entrada
// e comsegue manipular de que foi dado o endereço
void soma(int *a, int *b, int *resultado) {
  // nesse caso o ponteiro resultado esta modificando 
  // o valor da variavel a o qual ele aponta
  *resultado = *a + *b;
}

int main(void) {
  // cria as variaveis
  int a, b, resultado;

  printf("valor A e B: ");
  // coloca algum valor inserido pelo usuario na variavel
  scanf("%d%d", &a, &b);
  // paça os endereços da variavel
  soma(&a, &b, &resultado);

  // imprimi o resultado
  printf("resultado: %d", resultado);

  return 0;
}
