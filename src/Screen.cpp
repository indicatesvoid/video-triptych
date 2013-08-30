
#include "Screen.h"

//int Screen::displayWidth = 1440;
//int Screen::displayHeight = 1920;

Display Screen::display;

Screen::Screen(int id, int cameraId)
{
	this->id = id;
	camera = new Camera(cameraId);
	camera->start();
	texture.allocate(Camera::WIDTH, Camera::HEIGHT, GL_RGB);
	pixels = new unsigned char[Camera::WIDTH * Camera::HEIGHT * 3];
    ofAddListener(AppEvent::PRESSURE, this, &Screen::onPressureEvent);
    
    setDisplaySize(2560 / 4, 1440 / 4);
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

int Screen::getDisplayWidth() {
    return Screen::display.width;
}

int Screen::getDisplayHeight() {
    return Screen::display.height;
}

Display Screen::getDisplaySize() {
    return Screen::display;
}

void Screen::setDisplaySize(int w, int h) {
    Screen::display.width = w;
    Screen::display.height = h;
}

void Screen::draw()
{
    ofSetColor(255, 255, 255);
	if (cameraReady){
		texture.draw(Screen::display.width * this->id, 0, Screen::display.width, Screen::display.height);
	}
    // draw indication of pressure //
    if (this->active){
        ofSetColor(0, 255, 0);
    }   else{
        ofSetColor(255, 0, 0);
    }
	ofCircle((id * Screen::display.width) + 15, 15, 10);
//	camera->draw();
//	texture.draw(1200 * this->id, 0, SETTINGS::SCREEN_WIDTH, Camera::HEIGHT);
}
//
void Screen::onPressureEvent(AppEvent::PressureData &e)
{
    if (e.id == this->id){
        active = e.pressure > 0;
        if (active) ofLogNotice("sensor " + ofToString(e.id) + " : pressure = " + ofToString(e.pressure));
    }
}
