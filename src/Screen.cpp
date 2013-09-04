
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
    
    setDisplaySize(Camera::WIDTH, Camera::HEIGHT);
    this->hOffset = Screen::display.width * this->id;
}

Screen::Screen(int id, int cameraId, vector< Effect* > effects)
{
	this->id = id;
    this->effects = effects;
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

ofImage Screen::getVideoFrame() {
    ofImage img;
    img.setFromPixels(camera->video.getPixelsRef());
    return img;
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

void Screen::predrawEffects() {
    for(int effect = 0; effect < effects.size(); effect++) effects[effect]->predraw();
}

void Screen::drawEffects() {
    for(int effect = 0; effect < effects.size(); effect++) effects[effect]->draw();
}

void Screen::clearEffects() {
    for(int effect = 0; effect < effects.size(); effect++) effects[effect]->clear();
}

void Screen::addEffects(vector< Effect* > newEffects) {
    for(int effect = 0; effect < newEffects.size(); effect++) {
        effects.push_back(newEffects[effect]);
    }
}

int Screen::getHorizontalOffset() {
    return hOffset;
}

void Screen::draw()
{
    ofSetColor(255, 255, 255);
    
    if(this->active) predrawEffects();
    
	if (cameraReady){
		texture.draw(hOffset, 0, Screen::display.width, Screen::display.height);
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
    
    if(this->active) drawEffects();
    else clearEffects();
}
//
void Screen::onPressureEvent(AppEvent::PressureData &e)
{
    if (e.id == this->id){
        active = e.pressure > 0;
//        if (active) ofLogNotice("sensor " + ofToString(e.id) + " : pressure = " + ofToString(e.pressure));
    }
}
