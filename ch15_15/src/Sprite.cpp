#include "Sprite.h"

Sprite::Sprite(){
    x = 0.0;
    y = 0.0;
    scaleX = 1.0;
    scaleY = 1.0;
    rotation = 0.0;
    strokeColor = ofColor(0);
    fillColor = ofColor(0);
    isStroke = false;
    isFill = false;
    isRollOver = false;
    locked = false;
    visible = true;
}

void Sprite::update(){
    if(! visible) return;
  
    ofPushMatrix();
    if(locked){
        x = ofGetMouseX() - xoff;
        y = ofGetMouseY() - yoff;
    }
    ofTranslate(x, y);
    ofScale(scaleX, scaleY);
    ofRotate(rotation);

    if(isFill){
        ofFill();
        ofSetColor(fillColor);
    }
    draw();
    
    if(isStroke) {
        ofNoFill();
        ofSetColor(strokeColor);
    }
    draw();
    
    ofPopMatrix();
}

void Sprite::setStrokeColor(ofColor strokeColor){
    this->strokeColor = strokeColor;
    isStroke = true;
}

void Sprite::setFillColor(ofColor fillColor){
    this->fillColor = fillColor;
    isFill = true;
}

void Sprite::startDrag() {
    if(isRollOver){
        locked = true;
        xoff = ofGetMouseX() - x;
        yoff = ofGetMouseY() - y;
    }
}

void Sprite::stopDrag() {
    locked = false;
}

void Sprite::draw(){
}
