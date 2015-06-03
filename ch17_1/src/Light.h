#pragma once

#include "ofMain.h"
#include "Sprite.h"

class Light : public Sprite{
public:
    Light(float x, float y, float z, float brightness);
    ~Light(){};
    void setBrightness(float b);
    float x, y, z;
    float brightness;
};