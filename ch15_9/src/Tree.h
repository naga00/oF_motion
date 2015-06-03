#pragma once

#include "ofMain.h"
#include "Sprite.h"

class Tree : public Sprite{
public:
    Tree();
    void draw();
    float xpos = 0;
    float ypos = 0;
    float zpos = 0;
    float x0, y0, x1, y1, x2, y2, x3, y3, x4, y4;
};