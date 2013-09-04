
#pragma once
#include "ofMain.h"

class Camera
{
	public:

		Camera(int deviceId);
    
		static const int		WIDTH = 340;
		static const int		HEIGHT = 200;

		void					start();
		void					stop();
		void					toggle();
		void					draw();
		ofVideoGrabber          video;

	private:

		int						id;
        void                    onUpdate(ofEventArgs &e);
};

