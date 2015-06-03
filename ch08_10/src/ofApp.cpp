#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    ball.radius = 20;
    ball.setFillColor(ofColor(255, 0, 0));
    
    for(int i=0; i<numHandles; i++) {
        handles[i].radius = 10;
        handles[i].setFillColor(ofColor(0, 0, 255));
        handles[i].x = ofRandom(ofGetWidth());
        handles[i].y = ofRandom(ofGetHeight());
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < numHandles; i++){
        Ball &handle = handles[i];
        float dx = handle.x - ball.x;
        float dy = handle.y - ball.y;
        ball.vx += dx * spring;
        ball.vy += dy * spring;
    }
    ball.vx *= friction;
    ball.vy *= friction;
    ball.x += ball.vx;
    ball.y += ball.vy;
    
    ofSetColor(0, 0, 0);
    for(int i=0; i<numHandles; i++) {
        ofLine(ball.x, ball.y, handles[i].x, handles[i].y);
    }
    
    ofFill();
    for(int i = 0; i < numHandles; i++){
        Ball &handle = handles[i];
        handle.update();  
    }
    ball.update();
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
