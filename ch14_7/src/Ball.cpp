#include "Ball.h"

Ball::Ball(float radius){
    this->radius = radius;
}

void Ball::draw(){
    if(ofDist(ofGetMouseX(), ofGetMouseY(), x, y) < radius) {
        isRollOver = true;
    }else{
        isRollOver = false;
    }
    ofEllipse(0, 0, radius*2, radius*2);
}
