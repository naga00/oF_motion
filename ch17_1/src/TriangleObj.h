#pragma once

#include "ofMain.h"
#include "Sprite.h"
#include "Point3D.h"
#include "Light.h"

class TriangleObj : public Sprite{
public:
    TriangleObj(Point3D* a, Point3D* b, Point3D* c, int cn);
    ~TriangleObj(){};
    void draw();
    float getLightFactor();
    bool isBackFace();
    void setDepth();
    
    Point3D* pointA;
    Point3D* pointB;
    Point3D* pointC;
    int cn;
    Light* light;
    float zpos;
    int red, green, blue;
};