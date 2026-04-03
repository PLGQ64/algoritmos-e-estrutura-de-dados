#include <stdio.h>

int main() {
  int v[5] = {1,2,3,4,5};
  // um laço for que imprimi o conteudo do vetor v
  for (int i = 0; i < 5 ; i++) {
    printf("%d, ", *(v+i));
  }
  printf("\n");
  // outro laço for que imprimi o vetor v ao contrario
  // mas nao modifica o vetor
  // somente imprimi o contrario
  for (int j = 4; j >= 0; j--) {
    printf("%d, ", *(v+j));
  }

  return 0;
}
