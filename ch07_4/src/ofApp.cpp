#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);

    ball.x = ofGetWidth()/2;
    ball.y = ofGetHeight()/2;
    ball.radius = 40;
    vx = ofRandom(10) - 5;
    vy = -10;
    ball.setFillColor(ofColor(255, 0, 0));
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    vy += gravity;
    ball.x += vx;
    ball.y += vy;
    
    if(isThrow){
        trackVelocity();
    }
    
    int left = 0;
    int right = ofGetWidth();
    int top = 0;
    int bottom = ofGetHeight();
    
    if(ball.x + ball.radius > right){
        ball.x = right - ball.radius;
        vx *= bounce;
    }else if(ball.x - ball.radius < left){
        ball.x = left + ball.radius;
        vx *= bounce;
    }
    
    if(ball.y + ball.radius > bottom){
        ball.y = bottom - ball.radius;
        vy *= bounce;
    }else if(ball.y - ball.radius < top){
        ball.y = top + ball.radius;
        vy *= bounce;
    }
    
    ball.update();
}

void ofApp::trackVelocity() {
    vx = ball.x - oldX;
    vy = ball.y - oldY;
    oldX = ball.x;
    oldY = ball.y;
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
    oldX = ball.x;
    oldY = ball.y;
    ball.startDrag();
    isThrow = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    ball.stopDrag();
    isThrow = false;
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
