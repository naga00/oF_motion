#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    vpX = ofGetWidth()/2;
    vpY = ofGetHeight()/2;
    
    for(int i=0; i<numBalls; i++) {
        balls[i] = new Ball3D(3.0);
        balls[i]->ypos = -100;
        balls[i]->vx = ofRandom(-3, 3);
        balls[i]->vy = ofRandom(-3, 3);
        balls[i]->vz = ofRandom(-3, 3);
        balls[i]->setFillColor(ofColor(ofRandom(255), ofRandom(255), ofRandom(255)));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<numBalls; i++) {
        Ball3D* ball = balls[i];
        move(ball);
    }
    sortZ();
}

void ofApp::move(Ball3D* ball) {
    float radius =  ball->radius;
    ball->vy += gravity;
    ball->xpos += ball->vx;
    ball->ypos += ball->vy;
    ball->zpos += ball->vz;
    
    if(ball->ypos > floor) {
        ball->ypos = floor;
        ball->vy *= bounce;
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
}

void ofApp::sortZ() {
    for(int i=0; i<numBalls - 1; i++) {
        for(int j=numBalls-1; j>i; j--) {
            if(balls[j]->zpos > balls[j-1]->zpos) {
                Ball3D* t = balls[j];
                balls[j] = balls[j-1];
                balls[j-1] = t;
            }
        }
    }
    for(int i=0; i<numBalls; i++) {
        Ball3D* ball = balls[i];
        ball->update();
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
