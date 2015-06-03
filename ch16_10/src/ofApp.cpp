#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    vpX = ofGetWidth()/2;
    vpY = ofGetHeight()/2;
    int index = 0;
    for(int i=0; i<numFaces; i++) {
        float angle = PI * 2 / numFaces * i;
        float xpos = cos(angle) * 200;
        float ypos = sin(angle) * 200;
        points[index] = new Point3D(xpos, ypos, -100);
        points[index + 1] = new Point3D(xpos, ypos,  100);
        index += 2;
    }
    for(int i=0; i<numFaces*2; i++) {
        points[i]->setVanishingPoint(vpX, vpY);
        points[i]->setCenter(0, 0, 200);
    }
    index = 0;
    for(int i=0; i<numFaces-1; i++) {
        triangles[index] = new TriangleObj(points[index], points[index + 3], points[index + 1], ofColor(102, 102, 204, 127));
        triangles[index + 1] = new TriangleObj(points[index], points[index + 2], points[index + 3], ofColor(102, 102, 204, 127));
        index += 2;
    }
    triangles[index] = new TriangleObj(points[index], points[1], points[index + 1], ofColor(102, 102, 204, 127));
    triangles[index+1] = new TriangleObj(points[index], points[0], points[1], ofColor(102, 102, 204, 127));
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    float angleX = (mouseY - vpY) * 0.001;
    float angleY = (mouseX - vpX) * 0.001;
    for(int i=0; i<numFaces*2; i++) {
        Point3D* point = points[i];
        point->rotateX(angleX);
        point->rotateY(angleY);
    }
    for(int i=0; i<numFaces*2; i++) {
        triangles[i]->update();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
