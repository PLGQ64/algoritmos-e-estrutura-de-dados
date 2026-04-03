#include <stdio.h>

int main(){
  // variavel x iniciada com 10
  int x = 10;
  // ponteiro p iniciado com o endereço de x
  int *p = &x;
  // ponteiro pp inicado com o endereço de do ponteiro p
  // o endereço do ponteiro p nao deve ser confudido com 
  // o endereço contido dentro de p
  int **pp = &p;

  // os valores sao imprimidos inicalmente x
  // o conteudo do endereço contido em p
  // e por fim o conteudo dentro do endereço contido em pp
  // dentro do endereço contido em p que é o conteudo de x
  printf("x = %d, p = %d, pp = %d", x, *p, **pp);
  

  return 0;
}
