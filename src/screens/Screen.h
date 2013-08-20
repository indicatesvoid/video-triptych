
#pragma once
#include "Camera.h"

class Screen
{
	public:
    
		Screen(int id);
		int						id;
    
		Camera*                 camera;
		bool					cameraReady;

		void					draw();
		void					update();

		unsigned char * 		pixels;
		unsigned char * 		overlay;
		ofTexture				texture;

		unsigned char*			getPixels();
		void                    setPixels(unsigned char* pixels);

};

