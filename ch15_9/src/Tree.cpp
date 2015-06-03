#include "Tree.h"

Tree::Tree(){
    x0 = 0;
    y0 = -140 - ofRandom(20);
    x1 = 0;
    y1 = -30 - ofRandom(30);
    x2 = ofRandom(80) - 40;
    y2 = -100 - ofRandom(40);
    x3 = 0;
    y3 = -60 - ofRandom(40);
    x4 = ofRandom(60) - 30;
    y4 = -110 - ofRandom(20);
}

void Tree::draw(){
    ofLine(0, 0, x0, y0);
    ofLine(x1, y1, x2, y2);
    ofLine(x3, y3, x4, y4);
}
