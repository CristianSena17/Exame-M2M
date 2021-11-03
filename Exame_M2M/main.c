/*
  Exame estágio – M2M Telemetria
  Cristian Fernandes Sena - 03/11/2021
*/

#include <stdio.h>

#define N 13 //Tamamho do buffer (para 3 inteiros de 4 bytes, mais um byte de tamanho)

typedef struct Dados{
  int id; // Identificador
  int sq; // Sequenciador
  int vl; // Valor
}Dados;

/*
  Descrição: Uma função que recebe um dado do tipo Dado e faz seu preenchimento.
  Parâmetros: Um dado do tipo Dado.
  Retorno: O dado preenchido.
*/
Dados leitura (Dados dado){
  printf("Informe o Identificador: ");
  scanf("%d", &dado.id);
  printf("Informe o Sequenciador: ");
  scanf("%d", &dado.sq);
  printf("Informe o Valor: ");
  scanf("%d", &dado.vl);

  return dado;
}

/*
  Descrição: Um procedimento que recebe um dado do tipo Dado, o vetor buffer e faz seu preenchimento inicial.
  Parâmetros: Um dado do tipo Dado e o vetor buffer.
  Retorno: Não possui.
*/
void setupBuffer(Dados dado, int buffer[N]){

  //Limpa o buffer a partir da posição 2:
  for(int i = 2; i < 13; i++){
    buffer[i] = 0;
  }

  //Definição dos dados:
  buffer[0] = N;
  buffer[1] = dado.id;
  buffer[5] = dado.sq;
  buffer[9] = dado.vl;
}

/*
  Descrição: Um procedimento que recebe o vetor buffer e faz sua impressão.
  Parâmetros: O vetor buffer.
  Retorno: Não possui.
*/
void printBuffer(int buffer[N]){
  printf("|");
  for(int i = 0; i < 13; i++){
    printf(" %d |", buffer[i]);
  }
}

/*
  Descrição: Um procedimento que recebe o vetor buffer e faz sua conversão para Little endian.
  Parâmetros: O vetor buffer.
  Retorno: Não possui.
*/
void littleEndian(int buffer[N]){
  int temp;
  for(int i = 1; i < N-3; i += 4){
    //Faz o swap de uma posição com outra 3 posições a frente
    buffer[i] = buffer[i+3];
    buffer[i+3] = 0;
  }

  printBuffer(buffer); //Imprime o buffer
}

/*
  Descrição: Um procedimento que recebe o vetor buffer e faz sua conversão para Big endian.
  Parâmetros: O vetor buffer.
  Retorno: Não possui.
*/
void bigEndian(int buffer[N]){
  int temp;
  for(int i = 1; i < N-3; i += 4){
    //Faz o swap de uma posição com outra 3 posições atrás
    buffer[i+3] = buffer[i];
    buffer[i] = 0;
  }

  printBuffer(buffer); //Imprime o buffer
}

/*
  Descrição: Main
  Parâmetros: Não possui.
  Retorno: int 0;
*/
int main(void) {
  Dados dado;
  int buffer[N];

  dado = leitura(dado);

  setupBuffer(dado, buffer);

  printf("\nBig endian: \n");
  bigEndian(buffer);

  printf("\nLittle endian: \n");
  littleEndian(buffer);

  return 0;
}
