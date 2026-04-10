#include <stdio.h>
#include <string.h>

// quantidade maxima de funcionarios
#define DEFAULT_FUNCIONARIO 3

// uma struct, um tipo especial de variavel que o programador
// pode criar
struct funcionario {
  char nome[129];
  float salario;
  int identificador;
  char cargo [65];
};

// como as funcoes foram colocadas depois da funcao main,
// elas devem ser declaradas aqui
void formulario(struct funcionario *colaborador);
void salario(struct funcionario *colaborador);
void impresao(struct funcionario *colaborador);
void maior(struct funcionario *colaborador, int n);


int main(void) {
  // o vetor struct e definido aqui
  struct funcionario colaborador[DEFAULT_FUNCIONARIO];

  // os printfs a seguir sao somente para informacao
  // os for foram usados porque estamos tratando de
  // um vetor e o for e necessario para percorrer o vetor
  printf("preencha dados dos funcionarios"); 
  for (int i = 0; i < DEFAULT_FUNCIONARIO; i++) {
    formulario(&colaborador[i]);
  }

  printf("dados do funcionarios");
  for (int i = 0; i < DEFAULT_FUNCIONARIO; i++) {
    impresao(&colaborador[i]);
  }

  printf("modificar salarios do funcioanrio");
  for (int i = 0; i < DEFAULT_FUNCIONARIO; i++) {
    salario(&colaborador[i]);
  }

  maior(colaborador, DEFAULT_FUNCIONARIO);

  return 0;
}

// uma funcao para preencher os dados dos funcionarios
// ela recebe um pointer ou endereço de tipo funcionario
// a funcao em si nao e nada mais que um monte de scanf
void formulario(struct funcionario *colaborador) {
  // essas variaveis foram criadas por segurança
  char nome[129];
  char cargo[65];
  printf("preencha os campos\n");
  printf("nome: ");
  scanf("%[^\n]s", nome);
  getchar();
  // o scanf ao invez de atribuir a string diretamente a struct atribui a variavel nome
  // dai com strncpy a tring nome é copiada no colaborador->nome e o 128 define o limite
  // dai no indice 128 da string é atribuido o caractere \0 para indicar o fim da string
  // esse processo todo é somente para evitar que ocorra um stouro de buffer
  // quando o nome é maior que 128 caractes
  // o mesmo se aplica para o cargo
  strncpy(colaborador->nome, nome, 128);
  colaborador->nome[128] = '\0';
  printf("salario: ");
  scanf("%f", &colaborador->salario);
  getchar();
  printf("codigo de identificacao: ");
  scanf("%d", &colaborador->identificador);
  getchar();
  printf("cargo: ");
  scanf("%[^\n]s", cargo);
  getchar();
  strncpy(colaborador->cargo, cargo, 64);
  colaborador->cargo[64] = '\0';
  printf("\n\n");
}

// a funcao recebe um ponteiro do tipo funcionario
// a funcao em si é somente um monte de printf
void impresao(struct funcionario *colaborador) {
  printf("nome: %s\n", colaborador->nome);
  printf("salario: %.2f\n", colaborador->salario);
  printf("identificador: %d\n", colaborador->identificador);
  printf("cargo: %s\n", colaborador->cargo);
  printf("\n\n");
}

// a funcao recebe um ponteiro do tipo funcionario
// amostra o nome e permite o usuario alterar o salario
void salario(struct funcionario *colaborador) {
  printf("nome: %s\n", colaborador->nome);
  printf("novo salario: ");
  scanf("%f", &colaborador->salario);
  getchar();
  printf("\n\n");
}

// a funcao recebe um ponteiro do tipo funcionario
void maior(struct funcionario *colaborador, int n) {
  // os indices sao inciados com 0
  int ma = 0, me = 0;
  for (int i = 0; i < n; i++) {
    if (colaborador[ma].salario < colaborador[i].salario) {
      // o salario do colaborador de inidce ma for menor queo o 
      // do atual, ma nao e o maior, entao o indice ma e atualizado
      // para o indice i que seria o maior
      ma = i; 
    }
    if (colaborador[me].salario > colaborador[i].salario) {
      // mesma coisa so que para o menor, isso é se o me for maior
      // que i ele nao seria o menor
      me = i;
    }
  }
  // amostra o cargo do menor salario e o cargo do maior salario
  printf("cargo: %s maior salario: %f\n", colaborador[ma].cargo, colaborador[ma].salario);
  printf("cargo: %s menor salario: %f\n", colaborador[me].cargo, colaborador[me].salario);
  printf("\n\n");
}
