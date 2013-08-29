#include "Sensor.h"

#define NUM_SENSORS 2
Sensor* sensors[NUM_SENSORS] = {
	new Sensor(0, 1),
	new Sensor(1, 2)
};

void setup()
{
	Serial.begin(9600);
}

void loop()
{
  if(Serial.available() > 0) {
    int sensor, degrees;
    int inByte = Serial.read();
//    Serial.print("IN BYTE :: "); Serial.println(inByte);
    sensor = analogRead(inByte);
    degrees = map(sensor, 768, 853, 0, 90);
    if (degrees < 0) degrees = 0;
    Serial.write(degrees);
  }
  
//	if (Serial.available() > 0) {
//		int sensor, degrees;
//		int inByte = Serial.read();
//		Serial.print("IN BYTE :: "); Serial.println(inByte);
//		for(int sensor = 0; sensor < NUM_SENSORS; sensor++) {
//			if(sensors[sensor]->screenId == inByte) {
//				sensor = analogRead(sensors[sensor]->pin);
//				degrees = map(sensor, 768, 853, 0, 90);
//				if (degrees < 0) degrees = 0;
//				Serial.write(degrees);
//			}
//		}
//	}
}
