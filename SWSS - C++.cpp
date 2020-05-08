// SWSS - C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "AS726X.h"

AS726X sensor;

void setup() {
  Wire.begin();
  Serial.begin(115200);

  sensor.begin();
}

int Sensor() {
  //NIR Readings

  int R = sensor.getR();
  int S = sensor.getS();
  int T = sensor.getT();
  int U = sensor.getU();
  int V = sensor.getV();
  int W = sensor.getW();

  int SensorData[6] = {R,S,T,U,V,W};
  
  return SensorData;
}

void MechElements(int SensorInfo) {

}

int DataInterprate(int sensorData[6]) {
  if (sensorData[0] == 100){
      // example
    return 1;
  }else if (sensorData[1] == 50){
    // nested if statements will be used also here, so that we can check for very specific conditions
    return 2;
  }
  return 0;
}


void loop(){
  while (true) {
    int sensorData = Sensor(); // return number
    int SensorInterp = DataInterprate(sensorData);
    if (SensorInterp != 0) {
      // do anything that needs to happen for processing the data
      MechElements(SensorInterp);
    }
  }
}