#pragma once

#include "ofMain.h"

class Sprite {
public:
    Sprite();
    virtual ~Sprite(){};
    virtual void update();
    virtual void draw();
    
    float x, y;
    float scaleX, scaleY;
    float width, height;
    float rotation;
    bool visible;
    bool isStroke;
    bool isFill;
};