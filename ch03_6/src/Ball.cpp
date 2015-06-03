#include "Ball.h"

Ball::Ball(){
}

void Ball::draw(){
    ofFill();
    ofSetColor(255, 0, 0);
    ofEllipse(0, 0, radius*2, radius*2);
}
