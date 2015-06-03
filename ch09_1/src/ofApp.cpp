#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    ball1 = new Ball(40);
    ball1->x = ofGetWidth()/2;
    ball1->y = ofGetHeight()/2;
    ball1->setFillColor(ofColor(255, 0, 0));

    ball2 = new Ball(40);
    ball2->x = 0;
    ball2->y = 0;
    ball2->setFillColor(ofColor(255, 0, 0));
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ball2->x = mouseX;
    ball2->y = mouseY;
    float dx = ball2->x - ball1->x;
    float dy = ball2->y - ball1->y;
    float dist = sqrt(dx * dx + dy * dy);
    if(dist < 80) {
        printf("hit");
    }
    ball1->update();
    ball2->update();
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
