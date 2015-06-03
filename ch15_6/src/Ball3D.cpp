#include "Ball3D.h"

Ball3D::Ball3D(float radius){
    this->radius = radius;
}

void Ball3D::draw(){
    if(ofDist(ofGetMouseX(), ofGetMouseY(), x, y) < radius) {
        isRollOver = true;
    }else{
        isRollOver = false;
    }
    ofEllipse(0, 0, radius*2, radius*2);
}
