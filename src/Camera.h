
#pragma once
#include "ofMain.h"

class Camera
{
	public:

		Camera(int deviceId);
    
		static const int		WIDTH = 1280;
		static const int		HEIGHT = 720;

		void					start();
		void					stop();
		void					toggle();
		void					draw();
		ofVideoGrabber          video;

	private:

		int						id;
        void                    onUpdate(ofEventArgs &e);
};

