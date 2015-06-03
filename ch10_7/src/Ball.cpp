#include "Ball.h"

Ball::Ball(float radius){
    this->radius = radius;
    width = radius*2;
    height = radius*2;
}

void Ball::draw(){
    if(ofDist(ofGetMouseX(), ofGetMouseY(), x, y) < radius) {
        isRollOver = true;
    }else{
        isRollOver = false;
    }
    ofEllipse(0, 0, radius*2, radius*2);
}
