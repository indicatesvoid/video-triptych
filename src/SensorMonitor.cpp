#include "SensorMonitor.h"

int SensorMonitor::numSensors;

SensorMonitor::SensorMonitor(int num)
{
    this->delay = 250;
    this->time = ofGetElapsedTimeMillis();
    SensorMonitor::numSensors = num;
    this->sensorId = 0;

	serialReady = serial.setup(0, 9600); // open the first device
    ofLogNotice("serialReady :: "+ofToString(serialReady));
    ofLogNotice("Num sensors :: " + ofToString(SensorMonitor::numSensors));
    ofAddListener(ofEvents().update, this, &SensorMonitor::onUpdate);
}

void SensorMonitor::onUpdate(ofEventArgs &e)
{
    if (ofGetElapsedTimeMillis() - time >= delay){
        time = ofGetElapsedTimeMillis();
		serial.writeByte(sensorId);
		int pressure = serial.readByte();
        AppEvent::PressureData pd = {sensorId, pressure};
        ofNotifyEvent(AppEvent::PRESSURE, pd);
        ofLogNotice("Pinging sensor # :: " + ofToString(sensorId));
        sensorId = (sensorId < numSensors - 1) ? sensorId + 1 : 0;
    }
}

int SensorMonitor::getNumSensors() {
    return numSensors;
}