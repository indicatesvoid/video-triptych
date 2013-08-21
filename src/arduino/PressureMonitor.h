
#pragma once
#include "ofMain.h"
#include "AppEvent.h"

class PressureMonitor{
    
    public:
        PressureMonitor();
    
    private:
        int             time;
        int             delay;
		int				screenId;
        bool            serialReady;
        void            onUpdate(ofEventArgs &e);
    
        ofSerial        serial;
};