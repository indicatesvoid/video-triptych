
#include "PressureMonitor.h"

PressureMonitor::PressureMonitor()
{
    this->delay = 1000;
    this->time = ofGetElapsedTimeMillis();
    this->screenId = 1;

//	serialReady = serial.setup(0, 9600); // open the first device
	serialReady = serial.setup("COM3", 9600);
    ofLogNotice("serialReady :: "+ofToString(serialReady));
    ofAddListener(ofEvents().update, this, &PressureMonitor::onUpdate);
}

void PressureMonitor::onUpdate(ofEventArgs &e)
{
    if (ofGetElapsedTimeMillis() - time >= delay){
        time = ofGetElapsedTimeMillis();
		serial.writeByte(screenId);
		int pressure = serial.readByte();
        AppEvent::PressureData pd = {screenId, pressure};
        ofNotifyEvent(AppEvent::PRESSURE, pd);
    }
}