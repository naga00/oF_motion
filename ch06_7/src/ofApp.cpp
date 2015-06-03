#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);

    ball.x = ofGetWidth()/2;
    ball.y = ofGetHeight()/2;
    vx = ofRandom(10) - 5;
    vy = ofRandom(10) - 5;
    ball.radius = 40;
    ball.setFillColor(ofColor(255, 0, 0));
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ball.x += vx;
    ball.y += vy;
    
    float speed = sqrt(vx * vx + vy * vy);
    float angle = atan2(vy, vx);
    if (speed > friction){
        speed -= friction;
    }else{
        speed = 0;
    }
    vx = cos(angle) * speed;
    vy = sin(angle) * speed;
    ball.x += vx;
    ball.y += vy;
    ball.update();
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
