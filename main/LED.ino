#include <Adafruit_NeoPixel.h> 
Adafruit_NeoPixel tira = Adafruit_NeoPixel(8, 12, NEO_GRB + NEO_KHZ800); 


int maxCapacity = 10;

int getPixel() {
  return (counter * 8) / maxCapacity;
}

void setupLed() {
  tira.begin();       
  tira.show();
  tira.setBrightness(20);
}


void handleLed(){
  int pixel = getPixel();
  if(pixel <= 2) {
    tira.setPixelColor(pixel, 0, 255, 0);
  } else if(pixel <=5) {
    tira.setPixelColor(pixel, 252, 232, 3);
  } else {
    tira.setPixelColor(pixel, 255, 0, 0);
  }
  tira.show();
}
