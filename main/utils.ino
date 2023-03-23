bool isSensorActivated(int x) {
  if(x > minTol && x < maxTol) {
    return true;
  } else {
    return false; 
  }
}

void reset() {
  stage = 0;
  leftSensorActivated = false;
  rightSensorActivated = false;
  nTryes = 0;
}
