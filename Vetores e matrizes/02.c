#include <stdio.h>
#include <stdlib.h>

int main(void){
  int linhas, colunas;
  // atribui o valor para linhas
  printf("numero de linhas: ");
  scanf(" %d", &linhas);
  // o getchar por segurança consome o caractere que ainda esteja no buffer
  getchar();
  // atribui o valor para colunas
  printf("numero de colunas: ");
  scanf(" %d", &colunas);
  getchar();

  // a primeira coluna deve ser alocada com o tamanho do total de linhas
  // para que ela possa armazenar os ponteiros que serao as linas
  int **matriz = (int**)malloc(linhas * sizeof(int*));
  // verifica se a alocaçao ocorreu com sucesso
  if(!matriz){printf("erro de alocacao"); exit(0);}

  // agora as linhas sao alocadas
  // o for percorre a primera coluna alocando um ponteiro que sera a linha
  // e isso é feito para cada indice da primeira coluna
  for(int i = 0; i < linhas; i++){
    matriz[i] = (int*)malloc(colunas * sizeof(int));
    if(!matriz[i]){printf("erro de alocacao da linha"); exit(0);}
  }


  // a mesmo que o anterior so que agora para a matriz transposta
  // com os valores trocados porque é uma matriz transposta
  int **tmatriz = (int**)malloc(colunas * sizeof(int*));
  if(!tmatriz){printf("erro de alocacao da tmatriz"); exit(0);}

  for(int i = 0; i < colunas; i++){
    tmatriz[i] = (int*)malloc(linhas * sizeof(int));
    if(!tmatriz[i]){printf("erro de alocacao da linha da tmatriz"); exit(0);}
  }


  // os valores sao inseridos pelo usuario na matriz
  for(int i = 0; i < linhas; i++){
    for(int j = 0; j < colunas; j++){
      printf("valor da matris (%d, %d): ",i,j);
      scanf("%d", &matriz[i][j]);
    }
  }
  // a matriz transposta e criada
  for(int i = 0; i < linhas; i++){
    for(int j = 0; j < colunas; j++){
      tmatriz[j][i] = matriz[i][j];
    }
  }

  // a matriz inserida e impressa
  printf("matriz inserida: \n");
  for(int i = 0; i < linhas; i++){
    for(int j = 0; j < colunas; j++){
      printf("%d",matriz[i][j]);
    }
    printf("\n");
  }

  // a matriz transposta e impresa
  printf("matriz transposta: \n");
  for(int i = 0; i < colunas; i++){
    for(int j = 0; j < linhas; j++){
      printf("%d",tmatriz[i][j]);
    }
    printf("\n");
  }

  // agora para liberar a memoria deve ser liberada de dentro para fora
  // porque se a primeira coluna que foi criada for liberada
  // nao teremos mais como liberar as linhas pois nao teremos accesso 
  // ao endereço de memoria no qual elas se encontram
  for (int i = 0; i < linhas; i++) free(matriz[i]);
    free(matriz);
  for (int i = 0; i < colunas; i++) free(tmatriz[i]);
    free(tmatriz);

  return 0;
}
