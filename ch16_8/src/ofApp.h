#pragma once

#include "ofMain.h"
#include "Point3D.h"
#include "TriangleObj.h"

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
    
    static const int numPoints = 5;
    static const int numTriangles = 6;
    Point3D* points[numPoints];
    TriangleObj* triangles[numTriangles];
    float fl = 250;
    float vpX = 0;
    float vpY = 0;
};
