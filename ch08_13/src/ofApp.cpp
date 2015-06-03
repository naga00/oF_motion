#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
  
    ball0.x = ofRandom(ofGetWidth());
    ball0.y = ofRandom(ofGetHeight());
    ball0.radius = 20;
    ball0.setFillColor(ofColor(255, 0, 0));
    
    ball1.x = ofRandom(ofGetWidth());
    ball1.y = ofRandom(ofGetHeight());
    ball1.radius = 20;
    ball1.setFillColor(ofColor(255, 0, 0));
    
    ball2.x = ofRandom(ofGetWidth());
    ball2.y = ofRandom(ofGetHeight());
    ball2.radius = 20;
    ball2.setFillColor(ofColor(255, 0, 0));
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(!ball0Dragging) {
        springTo(ball0, ball1);
        springTo(ball0, ball2);
    }
    
    if(!ball1Dragging) {
        springTo(ball1, ball0);
        springTo(ball1, ball2);
    }
    
    if(!ball2Dragging) {
        springTo(ball2, ball0);
        springTo(ball2, ball1);
    }
    
    ofNoFill();
    ofSetColor(0, 0, 0);
    ofLine(ball0.x, ball0.y, ball1.x, ball1.y);
    ofLine(ball1.x, ball1.y, ball2.x, ball2.y);
    ofLine(ball2.x, ball2.y, ball0.x, ball0.y);
    
    ofFill();
    ball0.update();
    ball1.update();
    ball2.update();
}

void ofApp::springTo(Ball &ballA, Ball &ballB) {
    float dx = ballB.x - ballA.x;
    float dy = ballB.y - ballA.y;
    float angle = atan2(dy, dx);
    float targetX = ballB.x - cos(angle) * springLength;
    float targetY = ballB.y - sin(angle) * springLength;
    ballA.vx += (targetX - ballA.x) * spring;
    ballA.vy += (targetY - ballA.y) * spring;
    ballA.vx *= friction;
    ballA.vy *= friction;
    ballA.x += ballA.vx;
    ballA.y += ballA.vy;
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
    ball0.startDrag();
    ball1.startDrag();
    ball2.startDrag();
    if(ball0.isRollOver) {
        ball0Dragging = true;
    }
    if(ball1.isRollOver) {
        ball1Dragging = true;
    }
    if(ball2.isRollOver) {
        ball2Dragging = true;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    ball0.stopDrag();
    ball1.stopDrag();
    ball2.stopDrag();
    ball0Dragging = false;
    ball1Dragging = false;
    ball2Dragging = false;
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
