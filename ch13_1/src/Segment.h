#pragma once

#include "ofMain.h"
#include "Sprite.h"

class Segment : public Sprite{
public:
    Segment(float segmentWidth, float segmentHeight);
    ~Segment(){};
    void draw();
    ofPoint* getPin();
    void roundedRect(float x, float y, float w, float h, float r);
    void quadraticBezierVertex(float cpx, float cpy, float x, float y, float prevX, float prevY);
    float segmentWidth, segmentHeight;
    float vx, vy;
};