#include <stdio.h>
#include <stdlib.h>

// recebe o vetor v tamanho do vetor n e o ponteiro m 
// o ponteito m é onde o resultado da media sera colocado
void media(float *v, float n, float *m){
  int soma = 0;
  for(int i = 0; i < n; i++){
    // soma todos os valores do ponteiro
    soma += v[i];
  }
  // cacula e armazena a media em m
  *m = soma/n;
}

int main(void){
  float n;
  float m;
  printf("tamanho do vetor: ");
  scanf("%f", &n);
  // o vetor v é alocado dinamicamente com tamanho n
  // o (float*) faz com que o ponterio retornado seja to tipo float*
  // malloc(n * sizeof(float)) alloca a memoria de tamanho (n vezes o tamaho de um float) bits
  float *v = (float*)malloc(n * sizeof(float));

  for(int i = 0; i < n; i++){
    printf("valor %d: ",i);
    scanf("%f", v+i);
  }
  // a media é calculada e armazenada em m
  media(v,n,&m);

  // a media é imprimida
  printf("media: %.2f", m);

  // como a memoria foi alocada usando malloc
  // e necessario liberar a memoria manualmente
  free(v);
  return 0;
}
