#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    for(int i=0; i<COUNT; i++){
        Ball ball;
        ball.x = ofRandom(ofGetWidth());
        ball.y = ofRandom(ofGetHeight());
        ball.vx = ofRandom(2) - 1;
        ball.vy = ofRandom(2) - 1;
        ball.radius = 10;
        balls.push_back(ball);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<balls.size(); i++) {
        Ball &ball = balls[i];
        ball.x += ball.vx;
        ball.y += ball.vy;
        if(ball.x - ball.radius > ofGetWidth() || ball.x + ball.radius < 0 || ball.y - ball.radius > ofGetHeight() || ball.y + ball.radius < 0) {
            ball.visible = false;
            balls.erase(balls.begin() + i);
        }
        ball.update();
    }
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
