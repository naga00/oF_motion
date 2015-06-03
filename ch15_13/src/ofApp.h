#pragma once

#include "ofMain.h"
#include "Ball3D.h"

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
    void rotateY(Ball3D* ball, float angleY);
    void sortZ();
    
    static const int numBalls = 50;
    Ball3D* balls[numBalls];
    float fl = 250;
    float vpX = 0;
    float vpY = 0;
};
