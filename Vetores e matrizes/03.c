#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  // o valor aleatorio é semeado por srand()
  // a semente e dada pela funcao time que dara
  // a hora atual como valor
  srand(time(NULL));
  int n, **matriz;


  printf("ordem da matriz: ");
  scanf("%d", &n);

  // alocacao malloc e realizada da mesma maneira que a questao anterior
  matriz = (int**)malloc(n * sizeof(int*));
  if(!matriz){printf("null coluna"); exit(1);}

  for(int i = 0; i < n; i++){
    matriz[i] = (int*)malloc(n * sizeof(int));
    if(!matriz){printf("null linha [%d]", i); exit(1);}
  }


  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      // o valor aleatorio e atrubido apartir da funcao (rand() % 100) + 1
      // rand gera um valor aleatorio de tamanho aleatorio
      // esse valor e dividio por 100 o que garante que sempre
      // o resto da divisao resultara em um valo de 0 a 99
      // o + 1 faz com que seja de 1 a 100 
      matriz[i][j] = (rand() % 100) + 1;
    }
  }

  // a matriz e imprimida
  for(int i = 0; i < n; i++){
    printf("|");
    for(int j = 0; j < n; j++){
      printf("%03d|", matriz[i][j]);
    }
    printf("\n");
  }

  // a memoria e liberada seguindo a mesma logica que a questao anterior
  for(int i = 0; i < 0; i++){free(matriz[i]);}
  free(matriz);

  return 0;
}
