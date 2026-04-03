#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// maximo de pesssoas
#define MAX_PESSOAS 3

// struct de pessoa
struct pessoa {
  char nome[129];
  int doc;
  int idade;
};
// typedef permite trocar o nome de variavel para
// algum outro definido pelo ususario como
// struct pessoa agora somente precisa digitar
// pessoa de acordo com a linha de codigo a seguir
typedef struct pessoa pessoa;


// inicializaçao das funçoes
void dados(pessoa *p);
void imprimir(pessoa *p);
void upidade(pessoa *p);
void velho(pessoa *p, int tamanho);


// a contagem do total de pessoas criadas
// é atualidado toda vez que uma pessoa é
// criada
int p_count = 0;

int main(void) {
  pessoa humano[MAX_PESSOAS];
  int opt = 0;
  // o codigo fica rodando enquanto o opt for diferente de -1 ou 
  // como vamos ver mais afrente, diferente de 5.
    while (opt != -1) {
      opt = 0;
      // o printf com uma tui para o usuario e um scanf para pegar a escolha
      printf("1-inserir dados da pessoa\n2-imprimir dados da pessoa\n3-trocar idade da pessoa\n4-pessoa mais velha\n5-sair\n");
      printf("opcao: ");
      scanf("%d",&opt);
      // esse getchar impede \n que fica no buffer cause mais problemas
      // mais afrente
      getchar();
      
      // um switch verifica os casos (cases) para uma variavel e
      // e executa esse case caso a condicao seja verdadeira
      switch (opt) {
        case 1: {
          // enquanto a quantidade de pessoas for menor que o maximo
          // essa linha de codigo e escutada
          if(p_count < MAX_PESSOAS){
            printf("insira dados da pessoa\n");
            // a funcao dados é imprimida
            dados(&humano[p_count]);
            // o contador e icrementado em 1
            p_count++;
            // o break é necessario para impedir que os outros cases 
            // ainda sejam verificados
            break;
          }else{
            // se a quantidade de pessoas for maior que o maximo de
            // pessoa, essa mensagem e imprimida
            printf("maximo de pessoas atingido\n");
            break;
          }
          break;
        }

        case 2: {
          // chama a funcao que imprimi os dados das
          // pessoas, com um for para imprimir os dados
          // de todas as pessoas
          printf("dados das pessoas: ");
          for(int i = 0; i < p_count; i++){
            imprimir(&humano[i]);
          }
          break;
        }

        case 3: {
          int id, achou = 0;
          printf("trocar idade da pessoa, insira numero de documento: ");
          scanf("%d", &id);
          // dentro do for o if verifica se alguma pessoa tem o mesmo numero
          // de documento que o usuario esta procurando, caso sim ele
          // chama a funcao updidade e atualiza a variavel achou para 1
          for(int i = 0; i < p_count; i++){
            if(humano[i].doc == id){
              upidade(&humano[i]);
              achou = 1;
              break;
            }
          }
          // se achou ainda for 0 entao a pessoa nao foi achada e a 
          // mensagem é imprimida
          if(achou == 0)printf("numero de documento nao existe");
          break;
        }

        case 4: {
          // chama a funcao velho para ver a pessoa mais velha e mais nova
          velho(humano, p_count);
          break;
        }

        case 5: {
          // termina o codigo, com saida 0
          exit(0);
          break;
        }
      }
    }

  return 0;
}

// recebe um ponteiro do tipo pessoa como entrada
// e pede os dados para o ponteiro
void dados(pessoa *p) {
  // a variavel nome existe pelo mesmo motivo que na questao anterior
  char nome[129];
  printf("nome: ");
  scanf("%[^\n]", nome);
  getchar();
  strncpy(p->nome, nome, 128);
  p->nome[128] = '\0';
  printf("numero de documentacao: ");
  scanf("%d", &p->doc);
  getchar();
  printf("idade: ");
  scanf("%d", &p->idade);
  getchar();
  printf("\n\n");
}

// recebe um ponteiro do tipo pessoa como entrada
// um monte de printf
void imprimir(pessoa *p) {
  printf("nome: %s\n", p->nome);
  printf("numero de documento: %d\n", p->doc);
  printf("idade: %d\n", p->idade);
  printf("\n\n");
}

// atualiza o a idade do ponteiro pessoa que lhe foi entrege
void upidade(pessoa *p) {
  printf("nova idade: ");
  scanf("%d", &p->idade);
  getchar();
}

// encontra a pessoa mais velha seguindo a mesma logica do 
// maior salario da questao anterior so que agora com a idade
void velho(pessoa *p, int tamanho) {
  int v = 0, n = 0;
  for(int i = 0; i < tamanho; i++) {
    if(p[v].idade < p[i].idade) {
      v = i;
    }
    if(p[n].idade > p[i].idade) {
      n = i;
    }
  }
  // imprime os resultados com nome e idade
  printf("pessoa mais velha: %s; idade: %d\n", p[v].nome, p[v].idade);
  printf("pessoa mais nova: %s; idade: %d\n", p[n].nome, p[n].idade);
}
