void printDistances(int l, int r) {
  // Debugging output
  Serial.print("Left distance: ");
  Serial.print(l);
  Serial.print(" cm, right distance: ");
  Serial.print(r);
  Serial.println(" cm");
}

void printIsActivated(bool x,bool y){
  // Debugging output
  Serial.print("isLeftSensorActivated ");
  Serial.print(x);
  Serial.print(" isRightSensorActivated ");
  Serial.println(y);
}

void printDirection(){
  if(leftSensorActivated){
    Serial.print("Entrando ");
    Serial.println(leftSensorActivated);
  }
  if(rightSensorActivated){
    Serial.print("Saliendo ");
    Serial.println(rightSensorActivated);
  }
}

void printStage(){
  Serial.print("Stage ");  
  Serial.print(stage);
}

void printCounter() {
  Serial.print("  Counter ");  
  Serial.println(counter);
}
