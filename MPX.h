//Verifica se a biblioteca já foi definida em outro momento
//Evita duplicações
#ifndef _MPX_H
//Define a biblioteca
#define _MPX_H
//Inclui as funções nativas do Arduino
#include <Arduino.h>

class MPX{
  //funções e variáveis usadas apenas dentro da biblioteca (variáveis locais)
  private:
  //funções e variáveis disponíveis para serem acessadas pelo código (variáveis globais)
  public:
    //Declarando o construtor, inicializador, 'setup' da biblioteca
    //Dentro dos parênteses estão os argumentos
    MPX(char sensor,float Vs,int pino);
    //Funções a serem chamadas do arquivo .cpp
    float deltap(int amostras){
    }
    float pitot(float rho,int amostras){    
    }   
};

#endif
