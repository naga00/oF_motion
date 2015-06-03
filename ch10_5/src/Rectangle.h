#pragma once

#include "ofMain.h"

class Rectangle{
public:
    Rectangle(float x, float y, float width, float height);
    float x, y;
    float width, height;
    float top, bottom;
    float left, right;
    ofPoint *topLeft, *bottomRight;
    ofPoint *size;
};