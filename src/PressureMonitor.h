
#pragma once
#include "ofMain.h"

class PressureMonitor{
    
    public:
        PressureMonitor();
    
    private:
        int             time;
        int             delay;
        void            onUpdate(ofEventArgs &e);
        ofSerial        serial;
    
        char            bytesRead[3];				// data from serial, we will be trying to read 3
        char            bytesReadString[4];			// a string needs a null terminator, so we need 3 + 1 bytes
        int             nBytesRead;					// how much did we read?
        int             nTimesRead;					// how many times did we read?
    
};