#pragma once

#include "ofMain.h"
#include "Sprite.h"

class Ship : public Sprite{
public:
    Ship();
    void draw();
    void gun(bool isGun);
    bool isGun;
};