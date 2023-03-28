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
  for(int i = 0; i < pixel; i++){
    if(i <= 2) {
      tira.setPixelColor(i, 0, 255, 0);
    } else if(i <=5) {
      tira.setPixelColor(i, 252, 232, 3);
    } else {
      tira.setPixelColor(i, 255, 0, 0);
    }
    tira.show();
  }
  tira.clear();
}
