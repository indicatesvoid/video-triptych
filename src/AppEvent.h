
#pragma once
#include "ofMain.h"

class AppEvent : public ofEventArgs
{
	public:
    
    struct PressureData {
        int id;
        int pressure;
    };
    
    static ofEvent<unsigned long>   TIMER;
    static ofEvent<PressureData>    PRESSURE;

};