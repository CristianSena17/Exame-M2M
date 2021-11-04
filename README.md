# Exame estágio – M2M Telemetria
Desenvolvido por Cristian Fernandes Sena
# Proposta
Desenvolver uma rotina para serializar e imprimir a seguinte estrutura de dados:

```c
{
  int id; // Identificador
  int sq; // Sequenciador
  int vl; // Valor
}
```
O buffer serializado deverá conter um byte para indicar o tamanho:
|   Tamanho  | ID <br /> (b0)  | ID <br /> (b1)  | ID <br /> (b2)  | ID <br /> (b3)  | SQ <br /> (b0)  | SQ <br /> (b1)  | SQ <br /> (b2)  | SQ <br /> (b3)  | VL <br /> (b0)  | VL <br /> (b1)  | VL <br /> (b2)  | VL <br /> (b3)  |
|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|

Os dados do buffer poderão ser ordenados tanto em big endian quanto em little endian. O candidato deverá indicar a ordem no final da impressão. Ex:

Considerando id = 3, sq = 5, vl = 255

```c
*Little endian :
13-3-0-0-0-5-0-0-0-255-0-0-0
*Big endian :
13-0-0-0-3-0-0-0-5-0-0-0-255
```

# Instruções de Reprodução
O algoritmo pode ser executado atravez do exe: <a href="https://github.com/CristianSena17/Exame-M2M/blob/main/Exame_M2M/bin/Debug/Exame_M2M.exe">Exame_M2M.exe</a> ou de forma online em: https://replit.com/@CristianSena/Exame-Estagio

