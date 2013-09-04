#pragma once

// Effect superclass gets passed to Screen object

class Effect {
    
    public:
        virtual void draw() { };
        virtual void clear() { };
};
