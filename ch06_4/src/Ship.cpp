#include "Ship.h"

Ship::Ship(){
}

void Ship::gun(bool isGun) {
    this->isGun = isGun;
}

void Ship::draw(){
    ofNoFill();
    ofSetColor(255, 0, 0);
    
    if(isGun) {
        ofBeginShape();
        ofVertex(-7.5, -5);
        ofVertex(-15, 0);
        ofVertex(-7.5, 5);
        ofEndShape();
    }
    ofBeginShape();
    ofVertex(10, 0);
    ofVertex(-10, 10);
    ofVertex(-5, 0);
    ofVertex(-10, -10);
    ofVertex(10, 0);
    ofEndShape();
}
