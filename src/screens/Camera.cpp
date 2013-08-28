
#include "Camera.h"

Camera::Camera(int deviceId)
{
	this->id = deviceId;
//    vector< ofVideoDevice > devices = video.listDevices();
//    for(int i=0; i < devices.size(); i++)
//    {
//        ofLogNotice("camera : "+ofToString(devices[i].id) + " : "+ofToString(devices[i].bAvailable));
//    }
    video.setDeviceID(deviceId);
	video.setDesiredFrameRate(60);
}

void Camera::start()
{
	bool ok = video.initGrabber(Camera::WIDTH, Camera::HEIGHT, false);
	ofLogNotice("initializing video :: "+ofToString(this->id));
    ofAddListener(ofEvents().update, this, &Camera::onUpdate);
}

void Camera::stop()
{
	video.close();
    ofRemoveListener(ofEvents().update, this, &Camera::onUpdate);
	ofLogNotice("disabling video :: "+ ofToString(this->id));
}

void Camera::toggle()
{
    video.isInitialized() == true ? stop() : start();
}

void Camera::onUpdate(ofEventArgs &e)
{
	video.update();
}

void Camera::draw()
{
	video.draw(Camera::WIDTH * this->id, 0);
//	ofLogNotice("update :: "+ ofToString(this->id));
}