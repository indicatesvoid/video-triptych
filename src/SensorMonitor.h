
#pragma once
#include "ofMain.h"
#include "AppEvent.h"

class SensorMonitor{
    
    public:
        SensorMonitor(int num);
    
        int getNumSensors();
    
    private:
        int             time;
        int             delay;
		int				sensorId;
        bool            serialReady;
        void            onUpdate(ofEventArgs &e);
    
        static int numSensors;
    
        ofSerial        serial;
};