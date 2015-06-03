#include "Segment.h"

Segment::Segment(float segmentWidth, float segmentHeight){
    this->segmentWidth = segmentWidth;
    this->segmentHeight = segmentHeight;
}

void Segment::draw() {
    roundedRect(-segmentHeight / 2,  -segmentHeight / 2, segmentWidth + segmentHeight, segmentHeight, segmentHeight/2);
    ofEllipse(0, 0, 2, 2);
    ofEllipse(segmentWidth, 0, 2, 2);
}

ofPoint* Segment::getPin() {
    float angle = rotation * PI / 180;
    float xPos = x + cos(angle) * segmentWidth;
    float yPos = y + sin(angle) * segmentWidth;
    return new ofPoint(xPos, yPos);
}

void Segment::roundedRect(float x, float y, float w, float h, float r) {
    ofBeginShape();
    ofVertex(x+r, y);
    ofVertex(x+w-r, y);
    quadraticBezierVertex(x+w, y, x+w, y+r, x+w-r, y);
    ofVertex(x+w, y+h-r);
    quadraticBezierVertex(x+w, y+h, x+w-r, y+h, x+w, y+h-r);
    ofVertex(x+r, y+h);
    quadraticBezierVertex(x, y+h, x, y+h-r, x+r, y+h);
    ofVertex(x, y+r);
    quadraticBezierVertex(x, y, x+r, y, x, y+r);
    ofEndShape();
}

void Segment::quadraticBezierVertex(float cpx, float cpy, float x, float y, float prevX, float prevY) {
    float cp1x = prevX + 2.0/3.0*(cpx - prevX);
    float cp1y = prevY + 2.0/3.0*(cpy - prevY);
    float cp2x = cp1x + (x - prevX)/3.0;
    float cp2y = cp1y + (y - prevY)/3.0;
    ofBezierVertex(cp1x, cp1y, cp2x, cp2y, x, y);
};