
#include <Adafruit_NeoPixel.h>    // importa libreria

// Primer parametro = cantidad de pixeles en la tira
// Segundo parametro = pin de conexion a Arduino
// Tercer parametro:
//   NEO_KHZ800  800 KHz velocidad de datos (WS2812 y nuevos)
//   NEO_KHZ400  400 KHz velocidad de datos (WS2811 y mas antiguos)
//   NEO_GRB     flujo de datos en orden GRB (WS2812 y nuevos)
//   NEO_RGB     flujo de datos en orden RGB (versiones mas antiguas)

Adafruit_NeoPixel tira = Adafruit_NeoPixel(8, 12, NEO_GRB + NEO_KHZ800); // creacion de objeto "tira"
// con una cantidad de 8 pixeles, sobre pin 2 de Arduino y configurado para WS2812

void setup(){
  Serial.begin(9600);
  tira.begin();       // inicializacion de la tira
  tira.show();        // muestra datos en pixel
}

void loop(){
  tira.setBrightness(20);               // brillo global para toda la tira
  for(int i = 0; i < 8; i++){   // bucle para recorrer posiciones 0 a 7
    Serial.println(i);
    if(i <= 2) {
      tira.setPixelColor(i, 0, 255, 0);   // cada pixel en color azul (posicion,R,G,B)
    } else if(i <=5) {
      tira.setPixelColor(i, 252, 232, 3);   // cada pixel en color azul (posicion,R,G,B)
    } else {
      tira.setPixelColor(i, 255, 0, 0);   // cada pixel en color azul (posicion,R,G,B)
      
    }
    tira.show();      // muestra datos en pixel 
    delay(500);       // breve demora de medio segundo
  }
  tira.clear();       // restablece todos los pixeles en apagado
}
