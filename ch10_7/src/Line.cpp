#include "Line.h"

Line::Line() {
}

Rectangle Line::getBounds() {
    return *new Rectangle(x, y, width, height);
}

void Line::lineTo(float toX, float toY) {
    this->toX = toX;
    this->toY = toY;
    width = toX;
    height = toY;
}

void Line::draw() {
    ofLine(0, 0, toX, toY);
}