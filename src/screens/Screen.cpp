
#include "Screen.h"
//#include <array>

Screen::Screen(int id)
{
	this->id = id;
	camera = new Camera(id);
	camera->start();
	texture.allocate(Camera::WIDTH, Camera::HEIGHT, GL_RGB);
	pixels = new unsigned char[Camera::WIDTH * Camera::HEIGHT * 3];
}

void Screen::update()
{
	if (camera->video.isFrameNew()) {
		cameraReady = true;
		pixels = camera->video.getPixels();
		texture.loadData(pixels, Camera::WIDTH, Camera::HEIGHT, GL_RGB);
	}
}

unsigned char * Screen::getPixels()
{
	return camera->video.getPixels();
}

void Screen::setPixels(unsigned char* np)
{
// this will draw video feed one onto screen #2....
	int totalPixels = Camera::WIDTH * Camera::HEIGHT *3;
	for (int i = 0; i < totalPixels / 2; i++){
		pixels[i] = 255 - np[i];
	}
	texture.loadData(pixels, Camera::WIDTH, Camera::HEIGHT, GL_RGB);
}

void Screen::draw()
{
	if (cameraReady){
		texture.draw(1200 * this->id, 0, 1200, Camera::HEIGHT);
	}
//	camera->draw();
//	texture.draw(1200 * this->id, 0, 1200, Camera::HEIGHT);
}


