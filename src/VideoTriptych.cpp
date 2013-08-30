
#include "VideoTriptych.h"

// NOTE: could use ofxFenster (https://github.com/underdoeg/ofxFenster) for screen splitting but waiting until its GLFW branch is more stable

void VideoTriptych::setup()
{
    ofEnableSmoothing();
    ofSetVerticalSync(true);
    ofSetWindowPosition(0, 1000);
    sensors = new SensorMonitor(2);
    vector< Effect* > effects;
    effects.push_back(new ColorFilterEffect(255,0,0));
    
    screens.push_back(new Screen(0, 0, effects));
    screens.push_back(new Screen(1, 1, effects));
//    screens.push_back(new Screen(1, 2));
	ofSetWindowShape(screens.size() * screens[0]->getDisplayWidth(), screens[0]->getDisplayHeight());
}

void VideoTriptych::update()
{
    for (int i = 0; i < screens.size(); i++) screens[i]->update();
//	screens[1]->setPixels(screens[0]->getPixels());
}

void VideoTriptych::draw()
{
    for (int i = 0; i < screens.size(); i++) screens[i]->draw();
}

void VideoTriptych::keyPressed(int key)
{

}

void VideoTriptych::keyReleased(int key)
{

}
