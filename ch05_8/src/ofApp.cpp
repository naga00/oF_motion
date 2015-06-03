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
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    vx += ax;
    vy += ay;
    ball.x += vx;
    ball.y += vy;
    ball.update();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case OF_KEY_LEFT:
            ax = -0.2;
            break;
        case OF_KEY_RIGHT:
            ax = 0.2;
            break;
        case OF_KEY_UP:
            ay = -0.2;
            break;
        case OF_KEY_DOWN:
            ay = 0.2;
            break;
        default:
            break;
    }
};

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    ax = 0;
    ay = 0;
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
