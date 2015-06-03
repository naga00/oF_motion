#include "Arrow.h"

Arrow::Arrow(){
}

void Arrow::draw(){
    ofFill();
    ofSetColor(255, 255, 0);
    setArrow();
    ofNoFill();
    ofSetColor(0, 0, 0);
    setArrow();
}

void Arrow::setArrow(){
    ofBeginShape();
    ofVertex(-50, -25);
    ofVertex(0, -25);
    ofVertex(0, -50);
    ofVertex(50, 0);
    ofVertex(0, 50);
    ofVertex(0, 25);
    ofVertex(-50, 25);
    ofVertex(-50, -25);
    ofEndShape();
}