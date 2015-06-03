#pragma once

#include "ofMain.h"
#include "Sprite.h"

class Ball : public Sprite{
public:
    Ball(float radius);
    void draw();
    float radius;
    float vx, vy;
};