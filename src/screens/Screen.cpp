
#include "Screen.h"

Screen::Screen(int id)
{
	this->id = id;
	camera = new Camera(id);
	camera->start();
	texture.allocate(Camera::WIDTH, Camera::HEIGHT, GL_RGB);
	pixels = new unsigned char[Camera::WIDTH * Camera::HEIGHT * 3];
    ofAddListener(AppEvent::PRESSURE, this, &Screen::onPressureEvent);
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
    ofSetColor(255, 255, 255);
	if (cameraReady){
		texture.draw(SETTINGS::SCREEN_WIDTH * this->id, 0, SETTINGS::SCREEN_WIDTH, Camera::HEIGHT);
	}
    // draw indication of pressure //
    if (this->active){
        ofSetColor(0, 255, 0);
    }   else{
        ofSetColor(255, 0, 0);
    }
	ofCircle((id * SETTINGS::SCREEN_WIDTH) + 15, 15, 10);
//	camera->draw();
//	texture.draw(1200 * this->id, 0, SETTINGS::SCREEN_WIDTH, Camera::HEIGHT);
}
//
void Screen::onPressureEvent(AppEvent::PressureData &e)
{
    if (e.id == this->id){
        active = e.pressure != 0;
        ofLogNotice("sensor " + ofToString(e.id) + " : pressure = " + ofToString(e.pressure));
    }
}
