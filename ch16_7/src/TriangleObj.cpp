#include "TriangleObj.h"

TriangleObj::TriangleObj(Point3D* a, Point3D* b, Point3D* c, ofColor cl){
    pointA = a;
    pointB = b;
    pointC = c;
    this->cl = cl;
}

void TriangleObj::draw(){
    ofSetColor(cl);
    ofBeginShape();
    ofVertex(pointA->screenX(), pointA->screenY());
    ofVertex(pointB->screenX(), pointB->screenY());
    ofVertex(pointC->screenX(), pointC->screenY());
    ofVertex(pointA->screenX(), pointA->screenY());
    ofEndShape();
}