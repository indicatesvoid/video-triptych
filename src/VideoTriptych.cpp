
#include "VideoTriptych.h"

void VideoTriptych::setup()
{
	ofSetVerticalSync(true);
    ofSetWindowPosition(0, 0);
    screens.push_back(new Screen(0));
    screens.push_back(new Screen(1));
}

void VideoTriptych::update()
{
    for (int i = 0; i < screens.size(); i++) screens[i]->update();
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
