
#include "PressureMonitor.h"

PressureMonitor::PressureMonitor()
{
    this->delay = 250;
    this->time = ofGetElapsedTimeMillis();
    this->screenId = 1;

//  ofSetLogLevel(OF_LOG_VERBOSE);
	serial.setup(0, 9600); //open the first device
//	serial.setup("COM3", 9600);
    
    ofAddListener(ofEvents().update, this, &PressureMonitor::onUpdate);
}

void PressureMonitor::onUpdate(ofEventArgs &e)
{
    if (ofGetElapsedTimeMillis() - time >= delay){
        time = ofGetElapsedTimeMillis();
		serial.writeByte(screenId);
		int pressure = serial.readByte();
		if (pressure > 0){
			ofLogNotice("sensor " + ofToString(screenId) + " : pressure = " + ofToString(pressure));
		}
    }
}