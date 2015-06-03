#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    ball.x = 0;
    ball.y = 0;
    ball.radius = 20;
    ball.setFillColor(ofColor(255, 0, 0));
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    float dx = ball.x - mouseX;
    float dy = ball.y - mouseY;
    float angle = atan2(dy, dx);
    float targetX = mouseX + cos(angle) * springLength;
    float targetY = mouseY + sin(angle) * springLength;
    vx += (targetX - ball.x) * spring;
    vy += (targetY - ball.y) * spring;
    vx *= friction;
    vy *= friction;
    ball.x += vx;
    ball.y += vy;
    
    ofNoFill();
    ofSetColor(0, 0, 0);
    ofLine(ball.x, ball.y, mouseX, mouseY);
    
    ofFill();
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
