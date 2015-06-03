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
    void springTo(Ball &ballA, Ball &ballB);
    
    Ball ball0;
    Ball ball1;
    bool ball0Dragging = false;
    bool ball1Dragging = false;
    float spring = 0.1;
    float friction = 0.9;
    int springLength = 100;
};
