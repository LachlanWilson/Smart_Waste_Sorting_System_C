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
  if (SensorInfo == 0){
    //allow any material to pass, this is undefined material
  } else if (SensorInfo == 1){
    //sort into material 1
  } else if (SensorInfo == 2){
    //sort into material 2
  } else if (SensorInfo == 3){
    //sort into material 3
  } else if (SensorInfo == 4){
    //sort into material 4
  } 
  // many of these could be made depending on number of known materials
}

int DataInterpret(int sensorData[6]) {
  if (((sensorData[0] > 0)&&(sensorData[0] < 100))&&((sensorData[1] > 0)&&(sensorData[1] < 100))){
      // example
    return 1;
  }else if (sensorData[1] > 100){
    // nested if statements will be used also here, so that we can check for very specific conditions
    return 2;
  }
  return 0; // no material or unknown material
}


void loop(){
  while (true) {
    int sensorData = Sensor(); // return number
    int SensorInterp = DataInterpret(sensorData);
    MechElements(SensorInterp);
  }
}