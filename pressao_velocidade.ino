//Exemplo MPX
//Incluindo biblioteca
#include <MPX.h>

//Definindo construtor(sensor, Vs, pino)
MPX mpxv7002dp('MPXV7002DP',5,A0);

//Definindo o total de amostras a serem feitas
int amostrastotal=10;
//Definindo a frequência de amostragem (Hz)
int freq=1;
//Calculando o delay/ período de amostragem
int t=(1/freq)*1000;

//Definindo a quantidade de amostras usadas para gerar uma leitura
//Cada leitura é uma média entre n amostras para reduzir o erro associado
int amostras = 10;
//Definindo a densidade do fluido para calcular a velocidade em um pitot
float rho = 1.6;

void setup() {
  //Inicializando comunicação serial a uma taxa de 9600 bauds(bits/s)
  Serial.begin(9600);
 }

void loop() {
  //Iterando pelo número de amostras definido
  for(int i = 0; i < amostrastotal; i++){
    //Função da biblioteca que recebe o número de amostras para média e retorna o delta p
   float deltaP = mpxv7002dp.deltap(amostras);
   //Função da biblioteca que recebe o número de amostras para média e o rho e retorna a velocidade
   float velocidade = mpxv7002dp.pitot(amostras,rho);
   //Exibindo resultados no monitor Serial
   Serial.println(deltaP);
   Serial.println(velocidade);
   //Espera entre as medições definida pela frequência de amostragem
   delay(t);
  }
}
