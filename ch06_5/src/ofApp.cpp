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
    
    int left = 0;
    int right = ofGetWidth();
    int top = 0;
    int bottom = ofGetHeight();
    
    if(ball.x + ball.radius > right){
        ball.x = right - ball.radius;
        vx *= -1;
    }else if(ball.x - ball.radius < left){
        ball.x = left + ball.radius;
        vx *= -1;
    }
    
    if(ball.y + ball.radius > bottom){
        ball.y = bottom - ball.radius;
        vy *= -1;
    }else if(ball.y - ball.radius < top){
        ball.y = top + ball.radius;
        vy *= -1;
    }
    
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
