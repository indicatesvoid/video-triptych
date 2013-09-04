#pragma once

#include "Screen.h"
#include "ofxOpenCv.h"
#include "ofxCvHaarFinder.h"

class FaceSwapEffect : public Effect {
    public:
        FaceSwapEffect(vector< Screen* > screens) {
            this->screens = screens;
            this->classifier = "haarcascade_frontalface_default.xml";
//            for(int screen = 0; screen < screens.size(); screen++) {
//                faces[screens[screen]] = new ofxCvHaarFinder;
//                faces[screens[screen]]->setup(classifier);
//            }
            this->faces = new ofxCvHaarFinder;
            this->faces->setup("haarcascade_frontalface_default.xml");
        }
    
        void findFacesInScreen(Screen* screen) {
            faces->findHaarObjects(screen->getVideoFrame());
        }
    
        void drawFacesInScreen(Screen* screen) {
            
            int hOffset = screen->getHorizontalOffset();
            
            findFacesInScreen(screen);
            
            ofPushStyle();
                ofNoFill();
                for(unsigned int i = 0; i < faces->blobs.size(); i++) {
                    ofRectangle cur = faces->blobs[i].boundingRect;
                    ofRect(cur.x + hOffset, cur.y, cur.width, cur.height);
                }
            ofPopStyle();
        }
    
        void draw() {
//            for(int screen = 0; screen < screens.size(); screen++) drawFacesInScreen(screens[screen]);
            for(int screen = 0; screen < screens.size(); screen++) {
//                findFacesInScreen(screens[screen]);
                drawFacesInScreen(screens[screen]);
//                ofLogNotice("Num faces in screen #" + ofToString(screen) + " :: " + ofToString(faces->blobs.size()));
            }
        }
    
    private:
        std::string classifier;
        vector< Screen* > screens;
//        std::map< Screen*, ofxCvHaarFinder* > faces;
        ofxCvHaarFinder* faces;
};