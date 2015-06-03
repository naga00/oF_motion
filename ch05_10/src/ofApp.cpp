#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    ship.x = ofGetWidth()/2;
    ship.y = ofGetHeight()/2;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ship.rotation += vr;
    float angle = ship.rotation * PI / 180;
    float ax = cos(angle) * thrust;
    float ay = sin(angle) * thrust;
    vx += ax;
    vy += ay;
    ship.x += vx;
    ship.y += vy;
    ship.update();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case OF_KEY_LEFT:
            vr = -5;
            break;
        case OF_KEY_RIGHT:
            vr = 5;
            break;
        case OF_KEY_UP:
            thrust = 0.2;
            ship.gun(true);
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    vr = 0;
    thrust = 0;
    ship.gun(false);
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
