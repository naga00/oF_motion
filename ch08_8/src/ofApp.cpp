#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    ofColor col = ofColor(255, 0, 0);
    ball0.radius = 20;
    ball0.setFillColor(col);
    ball1.radius = 20;
    ball1.setFillColor(col);
    ball2.radius = 20;
    ball2.setFillColor(col);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    moveBall(ball0, mouseX, mouseY);
    moveBall(ball1, ball0.x, ball0.y);
    moveBall(ball2, ball1.x, ball1.y);
    
    ofNoFill();
    ofSetColor(0, 0, 0);
    ofLine(mouseX, mouseY, ball0.x, ball0.y);
    ofLine(ball0.x, ball0.y, ball1.x, ball1.y);
    ofLine(ball1.x, ball1.y, ball2.x, ball2.y);
    
    ofFill();
    ball0.update();
    ball1.update();
    ball2.update();
}

void ofApp::moveBall(Ball &ball, float targetX, float targetY){
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
