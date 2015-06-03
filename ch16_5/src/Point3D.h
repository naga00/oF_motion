#pragma once

#include "ofMain.h"
#include "Sprite.h"

class Point3D : public Sprite{
public:
    Point3D(float x, float y, float z);
    void setVanishingPoint(float vpX, float vpY);
    void setCenter(float cX, float cY, float cZ);
    float screenX();
    float screenY();
    void rotateX(float angleX);
    void rotateY(float angleY);
    void rotateZ(float angleZ);
    
    float fl = 250;
    float vpX = 0;
    float vpY = 0;
    float cX = 0;
    float cY = 0;
    float cZ = 0;
    float x = 0;
    float y = 0;
    float z = 0;
};