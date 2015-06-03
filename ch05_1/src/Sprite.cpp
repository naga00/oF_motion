#include "Sprite.h"

Sprite::Sprite(){
    x = 0.0;
    y = 0.0;
    scaleX = 1.0;
    scaleY = 1.0;
    rotation = 0.0;
    isStroke = false;
    isFill = false;
    visible = true;
}

void Sprite::update(){
    if(! visible) return;
  
    ofPushMatrix();
    ofTranslate(x, y);
    ofScale(scaleX, scaleY);
    ofRotate(rotation);
    draw();
    ofPopMatrix();
}

void Sprite::draw(){
}
