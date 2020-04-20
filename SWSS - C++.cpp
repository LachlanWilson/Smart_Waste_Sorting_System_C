// SWSS - C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

void DataRecording(int SensorInfo){
	printf("%d", SensorInfo);
		//with open('Data.txt', 'a') as the_file : the_file.write(wasteType + " | " + str(SensorInfo) + '\n')
}

int Sensor() {
	int SensorData = 5;
		//SensorData = Sensor()
	return SensorData;
}

void MechElements(int SensorInfo) {
	printf("working");
}


int main(){
	while (true) {
		int SensorInfo = Sensor(); // return number

			if (SensorInfo != 0) {
			// do anything that needs to happen for processing the data
				DataRecording(SensorInfo);
				MechElements(SensorInfo);
			}
		}
	}


