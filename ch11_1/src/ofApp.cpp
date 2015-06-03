#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    ball0 = new Ball(40);
    ball0->mass = 2;
    ball0->x = 50;
    ball0->y = ofGetHeight()/2;
    ball0->vx = 1;
    ball0->setFillColor(ofColor(255, 0, 0));
    
    ball1 = new Ball(25);
    ball1->mass = 1;
    ball1->x = 300;
    ball1->y = ofGetHeight()/2;
    ball1->vx = -1;
    ball1->setFillColor(ofColor(255, 0, 0));
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ball0->x += ball0->vx;
    ball1->x += ball1->vx;
    float dist = ball1->x - ball0->x;
    if(abs(dist) < ball0->radius + ball1->radius) {
        float vx0Final = ((ball0->mass - ball1->mass) * ball0->vx + 2 * ball1->mass * ball1->vx) / (ball0->mass + ball1->mass);
        float vx1Final = ((ball1->mass - ball0->mass) * ball1->vx + 2 * ball0->mass * ball0->vx) / (ball0->mass + ball1->mass);
        ball0->vx = vx0Final;
        ball1->vx = vx1Final;
        ball0->x += ball0->vx;
        ball1->x += ball1->vx;
    }
    ball0->update();
    ball1->update();
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
