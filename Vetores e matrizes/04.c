#include <stdio.h>
#include <stdlib.h>

int main(void){
  int quantidade_pesoas;
  // o ponteiro vazio é criado que sera usado como um vetor
  int *v; 
  // um ponteiro de ponteiro é criado vazio e sera usado como uma matriz
  char **matriz;

  printf("quantidade de pessoas: ");
  scanf("%d", &quantidade_pesoas);
  getchar();

  // a coluna inicial da matriz é alocada normalmente 
  matriz = (char**)malloc(quantidade_pesoas * sizeof(char*));
  if(!matriz){printf("null"); exit(1);}
  // a linhas que foram alocads nas questoes anteriores erao vetores
  // agora elas sao usadas para armazenar uma string que é um vetor de chars
  for(int i = 0; i < quantidade_pesoas; i++){
    matriz[i] = (char*)malloc(128 * sizeof(char));
    if(!matriz[i]){printf("null [%d]", i); exit(1);}
  }

  // esse vetor que foi criado anteriormente
  // agora e allocado dinamicamente com (quantidade_pessoas) de elementos 
  v = (int*)malloc(quantidade_pesoas * sizeof(int));

  for(int i = 0; i < quantidade_pesoas; i++){
    // o nome é alocado na linha i da matriz
    printf("nome [%d]: ",i);
    scanf("%[^\n]s", &matriz[i][0]);
    getchar();
    // é a idade é alocada no indice i do vetor
    printf("idade [%d]: ",i);
    scanf("%d", (v+i));
    getchar();
  }

  // o nome e idade das pessoa e imprimidido
  for(int i = 0; i < quantidade_pesoas; i++){
    printf("nome completo: %s; idade: %d\n", matriz[i], v[i]);
  }

  // memoria e liberada, mesma logica das questoes anterior
  // com excesao do vetor porque ele nao é um vetor de ponteiros
  // entao ele so precisa de um free
  for(int i = 0; i < quantidade_pesoas; i++){free(matriz[i]);}
  free(matriz);
  free(v);

  return 0;
}
