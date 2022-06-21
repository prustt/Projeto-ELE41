#include "LedControl.h"

/*
pin 4 conectado a entrada de Dados
pin 5 conectado ao CLK
pin 6 conectado ao CS
*/

LedControl lc=LedControl(4,6,5,1);
float vrtotal;
int linha;
int coluna;

void setup()
{
lc.shutdown(0,false); //comando para ligar a matriz de led, caso esteja meio dormindo
lc.setIntensity(0,4); //ajustando o brilho do led
lc.clearDisplay(0); //limpando a matriz, para nao haver led aceso

Serial.begin(57600);

}

void loop()
{
  float VR = analogRead(A1);//leitura analógica da tensão
 
  vrtotal = 1000*((3.8*VR)/1023);/*conversão da leitura de bytes para obter a tensão
  3.8 pois essa é a tensão da pilha e dividindo por quanto 1 byte equivale digitalmente*/

  Serial.print(VR); //teste para ver a leitura no serial
  Serial.print("   ");
  Serial.print(vrtotal);//como a tensão é baixa, multiplicamos com mil e colocamos como mV
  Serial.println("mV");

  if(vrtotal>=1500){
      for(int it=0;it<=7;it++){
        for(int j=0; j<=7; j++){
          lc.setLed(0, it, j, true);
        }
    }
  }
  if(vrtotal>=100){
      lc.setLed(0, 0, 0, true);
  }
  if(vrtotal>=200){
    for(int it=0;it<=1;it++){
      lc.setLed(0, 1, it, true);
    }
  }
  if(vrtotal>=300){
    for(int it=0;it<=2;it++){
      lc.setLed(0, 2, it, true);
    }
  }
  if(vrtotal>=400){
    for(int it=0;it<=3;it++){
      lc.setLed(0, 3, it, true);
    }
  }
  if(vrtotal>=500){
    for(int it=0;it<=4;it++){
      lc.setLed(0, 4, it, true);
    }
  }
  if(vrtotal>=600){
    for(int it=0;it<=5;it++){
      lc.setLed(0, 5, it, true);
    }
  }
  if(vrtotal>=700){
    for(int it=0;it<=6;it++){
      lc.setLed(0, 6, it, true);
    }
  }
  if(vrtotal>=800){
    for(int it=0;it<=7;it++){
      lc.setLed(0, 7, it, true);
    }
  }
  if(vrtotal>=900){
      linha=6;
      coluna=0;      
    for(int it=0;it<=7;it++){
      lc.setLed(0, linha, it-coluna, true);
      if(linha>=0)  linha--;
      if(coluna<=6) coluna++;
    }
  }
  if(vrtotal>=1000){
    linha=5;
    coluna=0;
    for(int it=0;it<=7;it++){
      lc.setLed(0, linha, it-coluna, true);
      if(linha>=0)  linha--;
      if(coluna<=5) coluna++;
    }
  }
  if(vrtotal>=1100){
    linha=4;
    coluna=0;
    for(int it=0;it<=7;it++){
      lc.setLed(0, linha, it-coluna, true);
      if(linha>=0)  linha--;
      if(coluna<=4) coluna++;
    }
  }
  if(vrtotal>=1200){
    linha=3;
    coluna=0;
    for(int it=0;it<=7;it++){
      lc.setLed(0, linha, it-coluna, true);
      if(linha>=0)  linha--;
      if(coluna<=3) coluna++;
      
    }
  }
  if(vrtotal>=1300){
    linha=2;
    coluna=0;
    for(int it=0;it<=7;it++){
      lc.setLed(0, linha, it-coluna, true);
      if(linha>=0)  linha--;
      if(coluna<=2) coluna++;
    }
  }
  if(vrtotal>=1400){
    for(int it=0;it<=7;it++){
      lc.setLed(0, 1, it, true);
      lc.setLed(0, 0, it-1, true);
    }
  }
 
  if(vrtotal==0){
    lc.clearDisplay(0);
  }
  delay(25);
}
