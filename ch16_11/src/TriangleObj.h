#pragma once

#include "ofMain.h"
#include "Sprite.h"
#include "Point3D.h"

class TriangleObj : public Sprite{
public:
    TriangleObj(Point3D* a, Point3D* b, Point3D* c, ofColor cl);
    ~TriangleObj(){};
    void draw();
    
    Point3D* pointA;
    Point3D* pointB;
    Point3D* pointC;
    ofColor cl;
};