
#pragma once
#include "Camera.h"
#include "AppEvent.h"
#include "../Settings.h"

class Screen
{
	public:
    
		Screen(int id);
		int						id;
        bool                    active;
    
		Camera*                 camera;
		bool					cameraReady;

		void					draw();
		void					update();

		unsigned char*          pixels;
		unsigned char*          overlay;
		ofTexture				texture;

		unsigned char*			getPixels();
		void                    setPixels(unsigned char* pixels);
    
    private:
        void                    onPressureEvent(AppEvent::PressureData &e);

};

