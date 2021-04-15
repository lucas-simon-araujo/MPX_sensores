//Exemplo MPX
//Incluindo biblioteca
#include <MPX.h>

//Definindo construtor
char sensor = "MPXV7002DP";
float Vs = 5;
int pino = A0;
MPX mpxv7002dp(sensor,Vs,pino);

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
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < amostrastotal, i++){
   float deltaP = mpxv7002dp.deltap(amostras);
   float velocidade = mpxv7002dp.pitot(amostras,rho);
   Serial.println(deltaP);
   Serial.println(velocidade;)
   delay(t);
  }
}
