#pragma once

#include "Effect.h"

class ColorFilterEffect : public Effect {
    
    public:
        ColorFilterEffect(int r, int g, int b) {
            setColor(r, g, b);
        }
    
        void predraw() {
            ofSetColor(r, g, b);
        }
    
        void clear() {
            ofSetColor(255, 255, 255);
        }
    
        void setColor(int r, int g, int b) {
            this->r = r;
            this->g = g;
            this->b = b;
        }
    
    private:
        int r, g, b;
    
};
