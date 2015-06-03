#pragma once

#include "ofMain.h"
#include "Sprite.h"

class Ball3D : public Sprite{
public:
    Ball3D(float radius);
    void draw();
    float radius;
    float xpos = 0;
    float ypos = 0;
    float zpos = 0;
    float vx = 0;
    float vy = 0;
    float vz = 0;
    float mass = 1;
};