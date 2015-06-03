#pragma once

#include "ofMain.h"

class Sprite {
public:
    Sprite();
    virtual ~Sprite(){};
    virtual void update();
    virtual void draw();
    virtual void setStrokeColor(ofColor strokeColor);
    virtual void setFillColor(ofColor fillColor);
    virtual void startDrag();
    virtual void stopDrag();
    
    float x, y;
    float scaleX, scaleY;
    float width, height;
    float rotation;
    bool visible;
    bool isStroke;
    bool isFill;
    bool isRollOver;
    bool locked;
    float xoff, yoff;
    
    ofColor strokeColor;
    ofColor fillColor;
};