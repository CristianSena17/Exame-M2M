/*
  Exame est�gio � M2M Telemetria
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
  Descri��o: Uma fun��o que recebe um dado do tipo Dado e faz seu preenchimento.
  Par�metros: Um dado do tipo Dado.
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
  Descri��o: Um procedimento que recebe um dado do tipo Dado, o vetor buffer e faz seu preenchimento inicial.
  Par�metros: Um dado do tipo Dado e o vetor buffer.
  Retorno: N�o possui.
*/
void setupBuffer(Dados dado, int buffer[N]){

  //Limpa o buffer a partir da posi��o 2:
  for(int i = 2; i < 13; i++){
    buffer[i] = 0;
  }

  //Defini��o dos dados:
  buffer[0] = N;
  buffer[1] = dado.id;
  buffer[5] = dado.sq;
  buffer[9] = dado.vl;
}

/*
  Descri��o: Um procedimento que recebe o vetor buffer e faz sua impress�o.
  Par�metros: O vetor buffer.
  Retorno: N�o possui.
*/
void printBuffer(int buffer[N]){
  printf("|");
  for(int i = 0; i < 13; i++){
    printf(" %d |", buffer[i]);
  }
}

/*
  Descri��o: Um procedimento que recebe o vetor buffer e faz sua convers�o para Little endian.
  Par�metros: O vetor buffer.
  Retorno: N�o possui.
*/
void littleEndian(int buffer[N]){
  int temp;
  for(int i = 1; i < N-3; i += 4){
    //Faz o swap de uma posi��o com outra 3 posi��es a frente
    buffer[i] = buffer[i+3];
    buffer[i+3] = 0;
  }

  printBuffer(buffer); //Imprime o buffer
}

/*
  Descri��o: Um procedimento que recebe o vetor buffer e faz sua convers�o para Big endian.
  Par�metros: O vetor buffer.
  Retorno: N�o possui.
*/
void bigEndian(int buffer[N]){
  int temp;
  for(int i = 1; i < N-3; i += 4){
    //Faz o swap de uma posi��o com outra 3 posi��es atr�s
    buffer[i+3] = buffer[i];
    buffer[i] = 0;
  }

  printBuffer(buffer); //Imprime o buffer
}

/*
  Descri��o: Main
  Par�metros: N�o possui.
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

  printf("\n");
  system("pause"); //Pausa para a execu��o via exe

  return 0;
}
