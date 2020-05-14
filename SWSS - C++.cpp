
#include "AS726X.h"

AS726X sensor;

int SensorData[6];

void setup() {
  Wire.begin();
  Serial.begin(115200);

  sensor.begin();
}

void Sensor() {
  //NIR Readings

  int R = sensor.getR();
  int S = sensor.getS();
  int T = sensor.getT();
  int U = sensor.getU();
  int V = sensor.getV();
  int W = sensor.getW();

  SensorData[0] = R;
  SensorData[1] = S; 
  SensorData[2] = T;
  SensorData[3] = U;
  SensorData[4] = V;
  SensorData[5] = W;
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

int DataInterpret() {
  if (((SensorData[0] > 0)&&(SensorData[0] < 100))&&((SensorData[1] > 0)&&(SensorData[1] < 100))){
      // example
    return 1;
  }else if (SensorData[1] > 100){
    // nested if statements will be used also here, so that we can check for very specific conditions
    return 2;
  }
  return 0; // no material or unknown material
}


void loop(){
  while (true) {
    Sensor(); // return number
    int SensorInterp = DataInterpret();
    MechElements(SensorInterp);
  }
}