#pragma once

#include "ofMain.h"
#include "Sprite.h"

class Ball : public Sprite{
public:
    Ball();
    void draw();
    float radius;
};