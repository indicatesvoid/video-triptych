
#include "SensorMonitor.h"

SensorMonitor::SensorMonitor()
{
    this->delay = 250;
    this->time = ofGetElapsedTimeMillis();
    this->screenId = 1;

	serialReady = serial.setup(0, 9600); // open the first device
    ofLogNotice("serialReady :: "+ofToString(serialReady));
    ofAddListener(ofEvents().update, this, &SensorMonitor::onUpdate);
}

void SensorMonitor::onUpdate(ofEventArgs &e)
{
    if (ofGetElapsedTimeMillis() - time >= delay){
        time = ofGetElapsedTimeMillis();
		serial.writeByte(screenId);
		int pressure = serial.readByte();
        AppEvent::PressureData pd = {screenId, pressure};
        ofNotifyEvent(AppEvent::PRESSURE, pd);
    }
}