#include "Rectangle.h"

Rectangle::Rectangle(float x, float y, float width, float height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    top = y;
    bottom = y + height;
    left = x;
    right = x + width;
    topLeft = new ofPoint(x, y);
    bottomRight = new ofPoint(right, bottom);
    size = new ofPoint(width, height);
}