#include "TriangleObj.h"

TriangleObj::TriangleObj(Point3D* a, Point3D* b, Point3D* c, int cn){
    pointA = a;
    pointB = b;
    pointC = c;
    this->cn = cn;
}

void TriangleObj::draw(){
    setDepth();
    if(isBackFace()) {
        return;
    }
    red = cn >> 16;
    green = cn >> 8 & 0xff;
    blue = cn & 0xff;
    float lightFactor = getLightFactor();
    red *= lightFactor;
    green *= lightFactor;
    blue *= lightFactor;
    ofSetColor(ofColor(red, green, blue));
    ofBeginShape();
    ofVertex(pointA->screenX(), pointA->screenY());
    ofVertex(pointB->screenX(), pointB->screenY());
    ofVertex(pointC->screenX(), pointC->screenY());
    ofVertex(pointA->screenX(), pointA->screenY());
    ofEndShape();
}

float TriangleObj::getLightFactor() {
    Point3D* ab = new Point3D(0, 0, 0);
    ab->x = pointA->x - pointB->x;
    ab->y = pointA->y - pointB->y;
    ab->z = pointA->z - pointB->z;
    
    Point3D* bc = new Point3D(0, 0, 0);
    bc->x = pointB->x - pointC->x;
    bc->y = pointB->y - pointC->y;
    bc->z = pointB->z - pointC->z;
    
    Point3D* norm = new Point3D(0, 0, 0);
    norm->x = (ab->y * bc->z) - (ab->z * bc->y);
    norm->y = -((ab->x * bc->z) - (ab->z * bc->x));
    norm->z = (ab->x * bc->y) - (ab->y * bc->x);
    
    float dotProd = norm->x * light->x + norm->y * light->y + norm->z * light->z;
    float normMag = sqrt(norm->x * norm->x + norm->y * norm->y + norm->z * norm->z);
    float lightMag = sqrt(light->x * light->x + light->y * light->y + light->z * light->z);
    
    return (acos(dotProd / (normMag * lightMag)) / PI) * light->brightness;
}

bool TriangleObj::isBackFace() {
    float cax = pointC->screenX() - pointA->screenX();
    float cay= pointC->screenY() - pointA->screenY();
    float bcx = pointB->screenX() - pointC->screenX();
    float bcy = pointB->screenY() - pointC->screenY();
    return cax * bcy > cay * bcx;
}

void TriangleObj::setDepth() {
    zpos = min(pointA->z, pointB->z);
    zpos = min(zpos, pointC->z);
}