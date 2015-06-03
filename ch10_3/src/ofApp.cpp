#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    for(int i=0; i<numBalls; i++) {
        balls[i].x = ofRandom(ofGetWidth());
        balls[i].y = ofRandom(ofGetHeight());
        balls[i].radius = 40;
        balls[i].setFillColor(ofColor(255, 0, 0));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    float angle = (mouseX - ofGetWidth() / 2) * 0.001;
    float cosine = cos(angle);
    float sine = sin(angle);
    
    for(int i=0; i<numBalls; i++){
        Ball &ball = balls[i];
        float x1 = ball.x - ofGetWidth() / 2;
        float y1 = ball.y - ofGetHeight() / 2;
        float x2 = cosine * x1 - sine * y1;
        float y2 = cosine * y1 + sine * x1;
        ball.x = ofGetWidth() / 2 + x2;
        ball.y = ofGetHeight() / 2 + y2;
        ball.update();
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
