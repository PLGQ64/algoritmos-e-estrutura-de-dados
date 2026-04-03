#include <stdio.h>

// um funçao que recebe o endereço e tamanho de um vetor
// e retorna a soma de todos os valores dentro do vetor
int somaVetor(int *v, int n){
  int s = 0;
  for(int i = 0; i < n; i++){
    s += *(v+i);
  }
  return s;
}

int main(void){
  int n;
  printf("tamanho do vetor: ");
  scanf("%d", &n);
  int v[n];

  // o usuario insere os valores dentro do vetor
  for(int i = 0; i < n; i++){
    printf("valor %d do vetor: ", i);
    scanf("%d",&v[i]);
  }

  // o vetor v nao precisa de & pois um vetor ja é um ponterio
  // e o v sem indice retorna o endereço inicial do vetor
  // indice nao foi declarado como um vetor na funcao
  // entao a funçao recebe uma copia do valor de n
  printf("resultado: %d", somaVetor(v, n));

  return 0;
}
