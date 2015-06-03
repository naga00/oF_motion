#pragma once

#include "ofMain.h"
#include "Segment.h"
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
    ofPoint* reach(Segment* segment, float xpos, float ypos);
    void position(Segment* segmentA, Segment* segmentB);
    void moveBall();
    void checkHit();
    
    static const int numSegments = 6;
    Segment* segments[numSegments];
    float gravity = 0.5;
    float bounce = -0.9;
    Ball* ball;
};
