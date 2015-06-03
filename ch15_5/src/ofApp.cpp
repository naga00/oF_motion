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
        balls[i]->vx = ofRandom(-5, 5);
        balls[i]->vy = ofRandom(-5, 5);
        balls[i]->vz = ofRandom(-5, 5);
        balls[i]->setFillColor(ofColor(255, 0, 0));
        balls[i]->setStrokeColor(ofColor(0, 0, 0));
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
        ball->update();
    }
}

void ofApp::move(Ball3D* ball) {
    float radius =  ball->radius;
    ball->xpos += ball->vx;
    ball->ypos += ball->vy;
    ball->zpos += ball->vz;
    if(ball->xpos + radius > right) {
        ball->xpos = right - radius;
        ball->vx *= -1;
    }else if(ball->xpos - radius < left) {
        ball->xpos = left + radius;
        ball->vx *= -1;
    }
    if(ball->ypos + radius > bottom) {
        ball->ypos = bottom - radius;
        ball->vy *= -1;
    }else if(ball->ypos - radius < top) {
        ball->ypos = top + radius;
        ball->vy *= -1;
    }
    if(ball->zpos + radius > front) {
        ball->zpos = front - radius;
        ball->vz *= -1;
    }else if(ball->zpos - radius < back) {
        ball->zpos = back + radius;
        ball->vz *= -1;
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
