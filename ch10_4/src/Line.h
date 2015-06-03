#pragma once

#include "ofMain.h"
#include "sprite.h"
#include "Rectangle.h"

class Line : public Sprite{
public:
    Line();
    Rectangle getBounds();
    void lineTo(float toX, float toY);
    void draw();
    
    float toX, toY;
};