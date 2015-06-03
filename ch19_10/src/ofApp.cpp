#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    ball = new Ball(50);
    ball->x = ofGetWidth()/2;
    ball->y = ofGetHeight()/2;
    vx = 300;
    vy = -300;
    ball->setFillColor(ofColor(255, 0, 0));
    time = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    float elapsed = ofGetElapsedTimeMillis() - time;
    time = ofGetElapsedTimeMillis();
    vy += gravity * elapsed / 1000;
    ball->x += vx * elapsed / 1000;
    ball->y += vy * elapsed / 1000;
    float left = 0;
    float right = ofGetWidth();
    float top = 0;
    float bottom = ofGetHeight();
    
    if(ball->x + ball->radius > right) {
        ball->x = right - ball->radius;
        vx *= bounce;
    }else if(ball->x - ball->radius < left) {
        ball->x = left + ball->radius;
        vx *= bounce;
    }
    if(ball->y + ball->radius > bottom) {
        ball->y = bottom - ball->radius;
        vy *= bounce;
    }else if(ball->y - ball->radius < top){
        ball->y = top + ball->radius;
        vy *= bounce;
    }
    
    ball->update();
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
