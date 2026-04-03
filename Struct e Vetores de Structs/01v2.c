#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define e estruct ja foi explicado anteriormente entao nao
// explicarei novamente
#define MAX_VAGAS 5
#define MAX_TURMAS 3


struct aluno {
  int mat;
  char nome[81];
  float notas[3];
  float media;
};
typedef struct aluno Aluno;


struct turma {
  char id;
  int vagas;
  Aluno *alunos[MAX_VAGAS];
};
typedef struct turma Turma;


// cria o vetor/ponteiro turmas
Turma *turmas[MAX_TURMAS];
// o contadoe de turmas criadas, inciado com zero
int qtd_turmas = 0;


// declaracao de funcoes
Turma *cria_turma(char id);
Turma *procura_turma(Turma **turmas, int n, char id);
void matricula_aluno(Turma *turma, int mat, char *nome);
void lanca_notas(Turma *turma);
void imprime_alunos(Turma *turma);
void imprime_turmas(Turma **turmas, int n);
void limpa_memoria(Turma **turmas, int n);


int main() {
  // variavel de opcao
  int opcao = 0;
  // id sera usada para procurar por turmas pelo usuario
  char id_busca;

  printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n");
  printf("Autor: Ada Lovelace    Versao: 1.0\n");

  while (opcao != 6) {
    printf("\nMENU:\n1 - Criar turma\n2 - Listar turmas\n3 - Matricular aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - Sair\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);
    // necessario para impedir quebrar o codigo
    getchar();

    switch (opcao) {
      case 1: {
        // funciona de forma similar a criar pessoa na questao 2 da outra
        // lista de exercio de struct
        if (qtd_turmas < MAX_TURMAS) {
          printf("Criando nova turma...\nDigite um id: ");
          scanf(" %c", &id_busca);

          // aqui se usa atribuicao porque criar_turmas retorna uma
          // variavel t do tipo turma e os dados dessa variavel devem
          // ser copiadas em algum lugar para ser salva nesse caso
          // em algum indice do vetor turma
          turmas[qtd_turmas] = cria_turma(id_busca);
          // quando a turma for criada o qtd_turmas e incrementado em 1
          qtd_turmas++;

          printf("Turma %c criada com sucesso!\n", id_busca);

        } else {
          // caso a quantidade de turmas seja mior que o maximo
          // essa mensagem e imprimida
          printf("Limite de turmas atingidos\n");
        }
        break;
      }

      case 2: {
        // cham a funcao que imprimi turmas
        imprime_turmas(turmas, qtd_turmas);
        break;
      }

      case 3: {
        // variaveis criadas para armazenar os dados que serao entrges a funcao criar turma
        int mat;
        char nome[81];
        printf("Matriculando aluno...\nDigite o id da turma: ");
        scanf(" %c", &id_busca);

        // aqui o endereço da turma sera copiado para t caso ele seja encontrado
        Turma *t = procura_turma(turmas, qtd_turmas, id_busca);

        // verifica procura_turma econtrou uma turma ou nao
        if (t != NULL) {
          printf("Digite a matricula: ");
          scanf("%d", &mat);

          printf("Digite o nome: ");
          scanf(" %[^\n]", nome);
          getchar();

          // passa os dados inserido pelo usuario para a funcao
          // e a turma encontrada
          matricula_aluno(t, mat, nome);
        } else {
          // imprimi mensagem de erro caso nao encontre a turma
          printf("Turma inexistente!\n");
        }
        break;
      }

      case 4: {
        printf("Digite o id da turma: ");
        scanf(" %c", &id_busca);

        // mesma coisa do case 3
        Turma *tn = procura_turma(turmas, qtd_turmas, id_busca);

        // mesma coisa do case 3
        if (tn != NULL) {
          // chama a funcao lanca_notas e passa o endereço da turma
          lanca_notas(tn);
        } else {
          // imprimi mensagem de erro caso nao encontre a turma
          printf("Turma inexistente!\n");
        }
        break;
      }

      case 5: {
        printf("Digite o id da turma: ");
        scanf(" %c", &id_busca);

        // mesma coisa do case 3
        Turma *ta = procura_turma(turmas, qtd_turmas, id_busca);

        // mesma coisa do case 3
        if (ta != NULL) {
          // chama a funcao imprime_alunos e passa o endereço da turma
          imprime_alunos(ta);
        } else {
          // imprimi mensagem de erro caso nao encontre a turma
          printf("Turma inexistente!\n");
        }
        break;
      }

      case 6: {
        // limpa a memoria allocada para turmas e usuario
        // depois o while é quebrado
        limpa_memoria(turmas, qtd_turmas);
        printf("Obrigado por usar este programa!\n");
        break;
      }
    }
  }
  return 0;
}

// receve o id da turma como entrada
Turma *cria_turma(char id) {

  // a variavel t e alocada com o tamanho de uma turma e ira
  // temporariamente guardar os dados da turma
  Turma *t = (Turma*)malloc(sizeof(Turma));
  // verifica se alocacao ocorreu com sucesso
  if (t == NULL) {
    exit(1);
  }

  // atribui valores da turma em t
  t->id = id;
  t->vagas = MAX_VAGAS;
  // o vetor de alunos tem todos os seus indices com valor null
  for (int i = 0; i < MAX_VAGAS; i++) {
    t->alunos[i] = NULL;
  }

  // é retornado a turma t, que podera sera copiada em alguma outra variavel
  return t;
}

// a funcao de matricular alunos recebe o endereço da turma, a matricula do aluno
// e o nome do aluno, nao é obrigatorio o nome ser um ponteiro/endereco
// mas é mais eficiente na memoria do que copiar todos os caracteres para dentro da funcao
void matricula_aluno(Turma *turma, int mat, char *nome) {
  // o if verifica se ainda tem vagas disponiveis
  if (turma->vagas > 0) {
    // 5 - 5 = 0, 5 - 4 = 1; e assim segue ate que vagas seja
    // 0 porque o codigo nao sera mais executado
    int indice = MAX_VAGAS - turma->vagas;
    // alloca dinamicamente o tamanho do valor no indice de alunos
    turma->alunos[indice] = (Aluno*)malloc(sizeof(Aluno));
    // verifica alocacao
    if (turma->alunos[indice] == NULL) {
      exit(1);
    }

    // copia os dados do aluno no vetor no indice calculado
    turma->alunos[indice]->mat = mat;
    strncpy(turma->alunos[indice]->nome, nome, 80);
    turma->alunos[indice]->nome[80] = '\0';

    // zera as notas do aluno
    for (int i = 0; i < 3; i++) {
      turma->alunos[indice]->notas[i] = 0;
    }

    // zera a media
    turma->alunos[indice]->media = 0;
    // diminui o total de vagas em 1
    turma->vagas--;

    printf("Aluno matriculado com sucesso!\n");
  } else {
    // caso nao haja vagas
    printf("Limite maximo de vagas atingido\n");
  }
}

// recebe o endereço de uma turma
void lanca_notas(Turma *turma) {
  // o loop percorre por todos os alunos
  for (int i = 0; i < MAX_VAGAS; i++) {

    // verifica se a vaga nao e nula se for é porque nao ha aluno naquele indice/vaga
    if (turma->alunos[i] != NULL) {
      printf("Matricula: %d\tAluno: %s\n", turma->alunos[i]->mat, turma->alunos[i]->nome);
      // a soma e criada e inciada com 0 a cada loop
      float soma = 0;

      for (int j = 0; j < 3; j++) {
        printf("Digite a nota %d: ", j + 1);
        scanf("%f", &turma->alunos[i]->notas[j]);
        // a soma tem o seu conteudo somado mais o conteudo que esteja em turma->alunos[i]->notas[j]
        soma += turma->alunos[i]->notas[j];
      }
      // a media e calculada e atribuida a turma->alunos[i]->notas[j]
      turma->alunos[i]->media = soma / 3;
    }
  }
}

// recebe o endereco de uma turma
void imprime_alunos(Turma *turma) {
  // o for percorre o vetor de alunos dentro da turma imprimindo os dados
  for (int i = 0; i < MAX_VAGAS; i++) {
    if (turma->alunos[i] != NULL) {
      printf("Matricula: %d\nNome: %s\nMedia: %.1f\n", turma->alunos[i]->mat, turma->alunos[i]->nome, turma->alunos[i]->media);
    }
  }
}

// recebe o endereco do vetor turma e o total de turmas
void imprime_turmas(Turma **turmas, int n) {
  // o for percorre o vetor de turmas imprimindo os dados da turma
  for (int i = 0; i < n; i++) {
    if (turmas[i] != NULL) {
      printf("Turma %c - %d vagas disponíveis\n", turmas[i]->id, turmas[i]->vagas);
    }
  }
}

// rece o endereco do vetor turma, o total de turmas e o id que sera procurado
Turma *procura_turma(Turma **turmas, int n, char id) {
  // o for percorre o vetor de turma
  for (int i = 0; i < n; i++) {
    // o if verifica se a turma nao e nula e se o id da turma é igual
    // ao que foi diponibilizada para a funcao
    if (turmas[i] != NULL && turmas[i]->id == id) {
      // se encontrada e retornado o endereco da turma i
      return turmas[i];
    }
  }
  return NULL;
}

// recebe o endereco do vetor turma e o total de turmas
// como tem um vetor de ponteiros a memoria deve ser limpada
// de forma similar a uma matriz allocada dinamicamente de dentro para fora
void limpa_memoria(Turma **turmas, int n) {
  // o for percorre as turmas
  for (int i = 0; i < n; i++) {
    // o if verifica se a turma é nula
    if (turmas[i] != NULL) {
      // esse for percorre os alunos
      for (int j = 0; j < MAX_VAGAS; j++) {
        // verifica se o aluno nao é nulo
        if (turmas[i]->alunos[j] != NULL) {
          // libra a memoria alocada para o aluno
          free(turmas[i]->alunos[j]);
        }
      }
      // libera a memoria locada para turma
      free(turmas[i]);
    }
  }
}


