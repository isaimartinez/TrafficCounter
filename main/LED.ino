#include <Adafruit_NeoPixel.h> 

int maxCapacity = 10;

// Primer parametro = cantidad de pixeles en la tira
// Segundo parametro = pin de conexion a Arduino
Adafruit_NeoPixel tira = Adafruit_NeoPixel(8, 12, NEO_GRB + NEO_KHZ800); 

void setupLed() {
  tira.begin();       // inicializacion de la tira
  tira.show();        // muestra datos en pixel
  tira.setBrightness(20);               // brillo global para toda la tira
}


void handleLed(int counter){
  
}
