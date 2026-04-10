#include <stdio.h>
#include <stdlib.h>

int main(void){
  int n;
  printf("tamanho do vetor: ");
  scanf("%d", &n);
  // o vetor e allocado dinamicamente
  // mesma explicacao da 11 so que agora com um int
  int *v = (int*)malloc(n * sizeof(int));
  // verifica se foi allocada com sucesso
  if(v == NULL){
    exit (printf("erro de allocacao"));
  }

  // usuario insere os valores dentro do vetor
  for(int i = 0; i < n; i++){
    printf("valor %d: ", i);
    scanf("%d", (v+i));
  }

  // imprimi o inverso do vetor
  printf("vetor inverso: ");
  for(int j = (n-1); j >= 0; j--){
    printf("%d, ", v[j]);
  }

  free(v);

  return 0;
}
