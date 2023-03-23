#include <Adafruit_NeoPixel.h> 
// Primer parametro = cantidad de pixeles en la tira
// Segundo parametro = pin de conexion a Arduino
Adafruit_NeoPixel tira = Adafruit_NeoPixel(8, 12, NEO_GRB + NEO_KHZ800); 


int maxCapacity = 10;

int getPixel() {
  return (counter * 8) / maxCapacity;
}

void setupLed() {
  tira.begin();       // inicializacion de la tira
  tira.show();        // muestra datos en pixel
  tira.setBrightness(20);               // brillo global para toda la tira
}


void handleLed(){
  int pixel = getPixel();
  if(pixel <= 2) {
    tira.setPixelColor(pixel, 0, 255, 0);   // cada pixel en color azul (posicion,R,G,B)
  } else if(pixel <=5) {
    tira.setPixelColor(pixel, 252, 232, 3);   // cada pixel en color azul (posicion,R,G,B)
  } else {
    tira.setPixelColor(pixel, 255, 0, 0);   // cada pixel en color azul (posicion,R,G,B)
  }
  tira.show();      // muestra datos en pixel 
}
