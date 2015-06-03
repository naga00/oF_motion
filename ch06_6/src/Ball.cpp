#include "Ball.h"

Ball::Ball(){
}

void Ball::draw(){
    ofEllipse(0, 0, radius*2, radius*2);
}
