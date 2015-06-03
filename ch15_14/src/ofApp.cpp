#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    vpX = ofGetWidth()/2;
    vpY = ofGetHeight()/2;

    for(int i=0; i<numBalls; i++) {
        balls[i] = new Ball3D(15.0);
        balls[i]->xpos = ofRandom(-100, 100);
        balls[i]->ypos = ofRandom(-100, 100);
        balls[i]->zpos = ofRandom(-100, 100);
        balls[i]->setFillColor(ofColor(255, 0, 0));
        balls[i]->setStrokeColor(ofColor(0, 0, 0));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    float angleX = (mouseY - vpY) * 0.001;
    float angleY = (mouseX - vpX) * 0.001;
    for(int i=0; i<numBalls; i++) {
        Ball3D* ball = balls[i];
        rotateX(ball, angleX);
        rotateY(ball, angleY);
        doPerspective(ball);
    }
    sortZ();
}

void ofApp::rotateX(Ball3D* ball, float angleX) {
    float cosX = cos(angleX);
    float sinX = sin(angleX);
    float y1 = ball->ypos * cosX - ball->zpos * sinX;
    float z1 = ball->zpos * cosX + ball->ypos * sinX;
    ball->ypos = y1;
    ball->zpos = z1;
}

void ofApp::rotateY(Ball3D* ball, float angleY) {
    float cosY = cos(angleY);
    float sinY = sin(angleY);
    float x1 = ball->xpos * cosY - ball->zpos * sinY;
    float z1 = ball->zpos * cosY + ball->xpos * sinY;
    ball->xpos = x1;
    ball->zpos = z1;
}

void ofApp::doPerspective(Ball3D* ball) {
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
