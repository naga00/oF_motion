#pragma once

#include "ofMain.h"
#include "Tree.h"

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
    void move(Tree* tree);
    void sortZ();
    
    static const int numTrees = 100;
    Tree* trees[numTrees];
    float fl = 250;
    float vpX = 0;
    float vpY = 0;
    float floor = 50;
    float vz = 0;
    float friction = 0.98;
};
