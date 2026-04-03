#include <stdio.h>

// funcao que recebe o endereço de 2 valores e retorna o maior
int maior(int *a, int *b) {
  if (*a > *b) {
    return *a;
  } else {
    return *b;
  }
}

int main(void) {
  int a, b;

  printf("valor A e B: ");
  scanf("%d%d", &a, &b);

  // a funcao recebe os endereço mas retorna o conteudo
  // do ponteiro que tiver o maior valor
  // caso ela retornasse o endereço seria imprimido o endereço ao inves 
  // do resultado
  printf("maior: %d", maior(&a,&b));

  return 0;
}
