
#pragma once
#include "Camera.h"
#include "AppEvent.h"

struct Display {
    int width;
    int height;
};

class Screen
{
	public:
    
		Screen(int id, int cameraId);
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
    
        int                     getDisplayWidth();
        int                     getDisplayHeight();
        Display                 getDisplaySize();
        void                     setDisplaySize(int w, int h);
    
    private:
        void                    onPressureEvent(AppEvent::PressureData &e);
    
        static struct Display display;
    
//        static int              displayWidth;
//        static int              displayHeight;

};

