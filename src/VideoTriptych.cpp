
#include "VideoTriptych.h"

void VideoTriptych::setup()
{
	ofSetVerticalSync(true);
    ofSetWindowPosition(0, 1000);
    screens.push_back(new Screen(0));
    screens.push_back(new Screen(1));
//	ofSetWindowShape(screens.size() * 1440, 1920);
}

void VideoTriptych::update()
{
    for (int i = 0; i < screens.size(); i++) screens[i]->update();
	screens[1]->setPixels(screens[0]->getPixels());
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
