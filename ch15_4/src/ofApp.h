#pragma once

#include "ofMain.h"
#include "Ball.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    Ball* ball;
    float xpos = 0;
    float ypos = 0;
    float zpos = 0;
    float vx = ofRandom(10) - 5;
    float vy = ofRandom(10) - 5;
    float vz = ofRandom(10) - 5;
    float fl = 250;
    float vpX = 0;
    float vpY = 0;
    float top = -100;
    float bottom = 100;
    float left = -100;
    float right = 100;
    float front = 100;
    float back = -100;
};
