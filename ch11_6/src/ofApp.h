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
    void checkWalls(Ball *ball);
    void checkCollision(Ball *ball0, Ball *ball1);
    ofPoint* rotate(float x, float y, float sine, float cosine, Boolean reverse);
        
    static const int numBalls = 20;
    Ball* balls[numBalls];
    float bounce = -1.0;
};
