#include <stdio.h>

// uma funçao que o maior valor dentro de um vetor
int maiorElemento(int *v, int n){
  // inicializace a variavel com o primerio valor do vetor
  // para que se tenha um valor incial que esteja presente no vetor
  // comparar com os outros valores de dentro do vator
  int m = v[0];

  // um laço for que percorre o vetor com um if dentro que verifica
  // se o m é menor que o valor de v[i]
  // caso sim o valor de m é atualizado para o valor que é maior que m
  // no final é retornado o valor m
  for(int i = 0; i < n; i++){
    if(v[i] > m){
      m = v[i];
    }
  }
  return m;
}

// estrutura semelhante as ultimas 3 questoes entao nao considero
// necessario explicar
int main(void){
  int n;
  printf("tamanho do vetor: ");
  scanf("%d", &n);
  int v[n];

  for(int i = 0; i < n; i++){
    printf("valor %d: ",i);
    scanf("%d", &v[i]);
  }
  printf("\n");

  printf("maior: %d", maiorElemento(v, n));

  return 0;
}
