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
    }
    for(int i=0; i<numBalls - 1; i++) {
        Ball3D* ballA = balls[i];
        for(int j=i+1; j<numBalls; j++) {
            Ball3D* ballB = balls[j];
            float dx = ballA->xpos - ballB->xpos;
            float dy = ballA->ypos - ballB->ypos;
            float dz = ballA->zpos - ballB->zpos;
            float dist = sqrt(dx * dx + dy * dy + dz * dz);
            if(dist < ballA->radius + ballB->radius) {
                ballA->setFillColor(ofColor(0, 0, 255));
                ballB->setFillColor(ofColor(0, 0, 255));
            }
        }
    }
    sortZ();
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
