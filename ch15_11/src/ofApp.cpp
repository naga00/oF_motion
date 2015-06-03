#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    vpX = ofGetWidth()/2;
    vpY = ofGetHeight()/2;
    ball = new Ball3D(50);
    ball->setFillColor(ofColor(255, 0, 0));
    ball->setStrokeColor(ofColor(0, 0, 0));
    tx = ofRandom(-250, 250);
    ty = ofRandom(-250, 250);
    tz = ofRandom(500);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    float dx = tx - ball->xpos;
    float dy = ty - ball->ypos;
    float dz = tz - ball->zpos;
    ball->vx += dx * spring;
    ball->vy += dy * spring;
    ball->vz += dz * spring;
    ball->xpos += ball->vx;
    ball->ypos += ball->vy;
    ball->zpos += ball->vz;
    ball->vx *= friction;
    ball->vy *= friction;
    ball->vz *= friction;
    
    if(ball->zpos > -fl) {
        float scale = fl / (fl + ball->zpos);
        ball->scaleX = ball->scaleY = scale;
        ball->x = vpX + ball->xpos * scale;
        ball->y = vpY + ball->ypos * scale;
        ball->visible = true;
    }else{
        ball->visible = false;
    }
    ball->update();
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
    tx = ofRandom(-250, 250);
    ty = ofRandom(-250, 250);
    tz = ofRandom(500);
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
