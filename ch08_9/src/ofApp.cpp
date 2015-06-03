#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    for(int i=0; i<numBalls; i++) {
        balls[i].radius = 20;
        balls[i].setFillColor(ofColor(255, 0, 0));
    }
    balls[0].x = ofGetWidth()/2;
    balls[0].y = ofGetHeight()/2;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    ofSetColor(0, 0, 0);
    ofLine(mouseX, mouseY, balls[0].x, balls[0].y);
    for(int i=1; i<numBalls; i++) {
        Ball &ballA = balls[i-1];
        Ball &ballB = balls[i];
        ofLine(ballA.x, ballA.y, ballB.x, ballB.y);
    }
    
    ofFill();
    moveBall(balls[0], mouseX, mouseY);
    for(int i=1; i<numBalls; i++) {
        Ball &ballA = balls[i-1];
        Ball &ballB = balls[i];
        moveBall(ballB, ballA.x, ballA.y);
    }
}

void ofApp::moveBall(Ball &ball, float targetX, float targetY){
    ball.update();
    ball.vx += (targetX - ball.x) * spring;
    ball.vy += (targetY - ball.y) * spring;
    ball.vy += gravity;
    ball.vx *= friction;
    ball.vy *= friction;
    ball.x += ball.vx;
    ball.y += ball.vy;
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
