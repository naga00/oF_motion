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
    ball->xpos += dx * easing;
    ball->ypos += dy * easing;
    ball->zpos += dz * easing;
    
    float dist = sqrt(dx*dx + dy*dy + dz*dz);
    if(dist < 1) {
        tx = ofRandom(-250, 250);
        ty = ofRandom(-250, 250);
        tz = ofRandom(500);
    }
    
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
