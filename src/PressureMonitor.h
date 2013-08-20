
#pragma once
#include "ofMain.h"

class PressureMonitor{
    
    public:
        PressureMonitor();
    
    private:
        int             time;
        int             delay;
		int				screenId;
        void            onUpdate(ofEventArgs &e);
        ofSerial        serial;
};