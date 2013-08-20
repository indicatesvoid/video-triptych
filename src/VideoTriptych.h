
#pragma once

#include "ofMain.h"
#include "Settings.h"
#include "Screen.h"
#include "PressureMonitor.h"

class VideoTriptych : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
    
    private:
        PressureMonitor     pm;
        vector<Screen*>     screens;

};
