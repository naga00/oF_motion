#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);

    for(int i=0; i<COUNT; i++) {
        balls[i].x = ofGetWidth()/2;
        balls[i].y = ofGetHeight();
        balls[i].vx = ofRandom(2) - 1;
        balls[i].vy = ofRandom(-10) - 10;
        balls[i].setFillColor(ofColor(ofRandom(255), ofRandom(255), ofRandom(255)));
        balls[i].radius = 2;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<COUNT; i++) {
        Ball &ball = balls[i];
        ball.vy += gravity;
        ball.x += ball.vx;
        ball.y += ball.vy;
        if(ball.x - ball.radius > ofGetWidth() || ball.x + ball.radius < 0 || ball.y - ball.radius > ofGetHeight() || ball.y + ball.radius < 0) {
            ball.x = ofGetWidth() / 2;
            ball.y = ofGetHeight();
            ball.vx = ofRandom(2) - 1;
            ball.vy = ofRandom(-10) - 10;
        }
        ball.update(); 
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
};

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
