//Autor: Lucas Simon Araújo
//13/04/2021
//Obtenção de diferença de pressão (manômetro) e velocidade (pitot+manômetro) de escoamento de um fluido
//Sensores da família MPX
//Entradas: sensor (sensor), tensão de alimentação (Vs), pino (pino) amostras para obter média (amostras), densidade do fluido (rho)
//Saídas: diferença de pressão (deltap), velocidade (velocidade)
//A resolver: 
//-Criar função que calcule o offset (melhor fora ou dentro das leituras (dificuldade de separar iterações de erro de iterações de média)?)
//-Definir frequencia de amostragem, número de amostras, amostras para obter leitura média, amostras para obter erro médio
//-Aplicar todos os coeficientes (m,b) dos sensores com um switch...case para que o usuário possa apenas escolher o sensor

//Importando o arquivo .h
#include <MPX.h>

//Criando os argumentos como variáveis globais
char _sensor;
float _Vs;
int _pino;

//Criando o construtor, inicializador, 'setup' da biblioteca
//Argumentos são variáveis locais, só funcionam dentro da função
MPX::MPX(char sensor,float Vs,int pino){
  //Transformando os argumentos locais em globais
  _sensor = sensor;
  _Vs = Vs;
  _pino = pino;
}

//Definido as funções
float MPX::deltap(int amostras){
  //Seleção dos coeficientes para o sensor escolhido
  //da curva de resposta do datasheet fabricante do sensor
  if (_sensor == 'MPXV7002DP'){
    //para MPXV7002DP
    float m = 1; //sensibilidade/coeficiente angular da tensão em relação a pressão/diferença de pressão
    float b= _Vs/2; //intersecção/coeficiente linear da tensão em relação a pressão/diferença de pressão
  }
  
  // inicializa as variáveis que vão receber os valores:
  //do conversor ADC (analogic-digital converter)
  float media_adc = 0; 
  //da tensão
  float tensao = 0;
  //do diferencial de pressão
  float delta_p = 0;
  
  //cálculo da média das leituras do conversor ADC
  //itera a quantidade de amostras que foi configurada
  for (int contador=0;contador<amostras;contador++){
    //soma as leituras de todas as amostras subtraídas do erro médio
    media_adc += analogRead(_pino)
  }
  media_adc/=amostras;
  
  //Convertendo a leitura ADC em tensão
  tensao=(Vs*media_adc)/1023;

  //Convertendo a leitura em tensão para diferença de pressão
  //em KPa
  return delta_p = (tensao/m)-b;
}

float MPX::pitot(){
  //Seleção dos coeficientes para o sensor escolhido
  //da curva de resposta do datasheet fabricante do sensor
  if (_sensor == 'MPXV7002DP'){
    //para MPXV7002DP
    float m = 1; //sensibilidade/coeficiente angular da tensão em relação a pressão/diferença de pressão
    float b= _Vs/2; //intersecção/coeficiente linear da tensão em relação a pressão/diferença de pressão
  }
  
  // inicializa as variáveis que vão receber os valores:
  //do conversor ADC (analogic-digital converter)
  float media_adc = 0; 
  //da tensão
  float tensao = 0;
  //do diferencial de pressão
  float delta_p = 0;
  
  //cálculo da média das leituras do conversor ADC
  //itera a quantidade de amostras que foi configurada
  for (int contador=0;contador<amostras;contador++){
    //soma as leituras de todas as amostras subtraídas do erro médio
    media_adc += analogRead(_pino)
  }
  media_adc/=amostras;
  
  //Convertendo a leitura ADC em tensão
  tensao=(Vs*media_adc)/1023;

  //Convertendo a leitura em tensão para diferença de pressão
  //em KPa
  delta_p = (tensao/m)-b;
  
  // para um delta P negativo temos uma velocidade positiva
  if (delta_p<0){
    return velocidade = -sqrt((1000*abs(delta_p))/rho);
  } 
  // para um delta P negativo temos uma velocidade positiva
  else if(delta_p>0){
    return velocidade = sqrt((1000*abs(delta_p))/rho);
  }
  // se não for nem negativo nem positivo é nulo
  else{
    return 0;
  }
}