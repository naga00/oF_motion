#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    for(int i=0; i<numDots; i++) {
        dots[i] = new Ball(1);
        dots[i]->x = ofRandom(ofGetWidth());
        dots[i]->y = ofRandom(ofGetHeight());
        dots[i]->vx = 0;
        dots[i]->vy = 0;
        dots[i]->setFillColor(ofColor(0));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<numDots; i++) {
        Ball* dot = dots[i];
        dot->vx += ofRandom(0.2) - 0.1;
        dot->vy += ofRandom(0.2) - 0.1;
        dot->x += dot->vx;
        dot->y += dot->vy;
        dot->vx *= friction;
        dot->vy *= friction;
        
        if(dot->x > ofGetWidth()) {
            dot->x = 0;
        }else if(dot->x < 0) {
            dot->x = ofGetWidth();
        }
        if(dot->y > ofGetHeight()) {
            dot->y = 0;
        }else if(dot->y < 0) {
            dot->y = ofGetHeight();
        }
        dot->update();
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
