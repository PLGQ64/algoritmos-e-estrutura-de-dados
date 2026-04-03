#include <stdio.h>

// inverte o vetor original usando ponteiros
void inverter(int *v, int n){
  // variavel criada temporariamente para armazenar o vetor inverso
  int v2[n];
  for(int i = 0; i < n; i++){
    // o vetor iverso e criado apartir da atribuicao desse jeito
    // supondo que o vetor tem 4 elementos primeiro ciclo: v2[3] = v[0]
    // segundo ciclo: v2[2] = v[1]; e assim por diante
    v2[(n-1)-i] = v[i];
  }
  for(int i = 0; i < n; i++){
    // subistitui os valores originais de v por v2
    // mas isso somente acontece porque v
    // tem o mesmo endereço do vetor v na funçao main
    v[i] = v2[i];
  }
}

int main(void){
  int n;
  printf("tamanho: ");
  scanf("%d", &n);
  int v[n];

  for(int i = 0; i < n; i++){
    printf("valor %d: ", i);
    scanf("%d", &v[i]);
  }
  // a inversao ocorre aqui onde e passado o endereço e tamanho "n" de v
  inverter(v,n);

  // o vetor original e imprimido, mas agora ele deve ser o inverso
  // porcausa da funcao inverter()
  printf("invertido: ");
  for(int i = 0; i < n; i++){
    printf("%d, ",v[i]);
  }

  return 0;
}
