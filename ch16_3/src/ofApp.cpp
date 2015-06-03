#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    vpX = ofGetWidth()/2;
    vpY = ofGetHeight()/2;
    points[0] = new Point3D(-100, -100,  100);
    points[1] = new Point3D( 100, -100,  100);
    points[2] = new Point3D( 100,  100,  100);
    points[3] = new Point3D(-100,  100,  100);
    for(int i=0; i<numPoints; i++) {
        points[i]->setVanishingPoint(vpX, vpY);
    }
    ofSetColor(ofColor(0));
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    float angleX = (mouseY - vpY) * 0.001;
    float angleY = (mouseX - vpX) * 0.001;
    for(int i=0; i<numPoints; i++) {
        Point3D* point = points[i];
        point->rotateX(angleX);
        point->rotateY(angleY);
    }
 
    for(int i = 1; i < numPoints; i++) {
        ofLine(points[i-1]->screenX(), points[i-1]->screenY(), points[i]->screenX(), points[i]->screenY());
    }
    
    ofLine(points[numPoints - 1]->screenX(), points[numPoints - 1]->screenY(), points[0]->screenX(), points[0]->screenY());
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
