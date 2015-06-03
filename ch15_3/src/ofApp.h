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
    float vx = 0;
    float vy = 0;
    float vz = 0;
    float friction = 0.98;
    float fl = 250;
    float vpX = 0;
    float vpY = 0;
};
