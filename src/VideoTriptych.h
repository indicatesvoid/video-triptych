
#pragma once

#include "ofMain.h"
#include "Screen.h"
#include "Effect.h"
#include "ColorFilterEffect.h"
#include "SensorMonitor.h"

class VideoTriptych : public ofBaseApp{

	public:
    
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
    
    private:
        SensorMonitor*       sensors;
        vector<Screen*>     screens;
        vector<Camera*>     cameras;

};
