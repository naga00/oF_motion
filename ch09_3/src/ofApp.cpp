#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    centerBall = new Ball(100);
    centerBall->x = ofGetWidth()/2;
    centerBall->y = ofGetHeight()/2;
    centerBall->setFillColor(ofColor(200, 200, 200));
    
    for(int i=0; i<numBalls; i++) {
        float radius = ofRandom(40) + 5;
        balls[i] = new Ball(radius);
        balls[i]->x = ofRandom(ofGetWidth());
        balls[i]->y = ofRandom(ofGetHeight());
        balls[i]->vx = ofRandom(6) - 3;
        balls[i]->vy = ofRandom(6) - 3;
        balls[i]->setFillColor(ofColor(ofRandom(255), ofRandom(255), ofRandom(255)));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<numBalls; i++){
        Ball *ball = balls[i];
        move(ball);
        float dx = ball->x - centerBall->x;
        float dy = ball->y - centerBall->y;
        float dist = sqrt(dx * dx + dy * dy);
        float minDist = ball->radius + centerBall->radius;
        if(dist < minDist) {
            float angle = atan2(dy, dx);
            float tx = centerBall->x + cos(angle) * minDist;
            float ty = centerBall->y + sin(angle) * minDist;
            ball->vx += (tx - ball->x) * spring;
            ball->vy += (ty - ball->y) * spring;
        }
        ball->update();
    }
    centerBall->update();
}

void ofApp::move(Ball *ball) {
    ball->x += ball->vx;
    ball->y += ball->vy;
    
    if(ball->x + ball->radius > ofGetWidth()){
        ball->x = ofGetWidth() - ball->radius;
        ball->vx *= bounce;
    }else if(ball->x - ball->radius < 0){
        ball->x = ball->radius;
        ball->vx *= bounce;
    }
    
    if(ball->y + ball->radius > ofGetHeight()){
        ball->y = ofGetHeight() - ball->radius;
        ball->vy *= bounce;
    }else if(ball->y - ball->radius < 0){
        ball->y = ball->radius;
        ball->vy *= bounce;
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
