#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    for(int i=0; i<numBalls; i++) {
        float radius = ofRandom(30) + 20;
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
    for(int i=0; i<numBalls-1; i++){
        Ball *ball0 = balls[i];
        for(int j=i+1; j<numBalls; j++){
            Ball *ball1 = balls[j];
            float dx = ball1->x - ball0->x;
            float dy = ball1->y - ball0->y;
            float dist = sqrt(dx * dx + dy * dy);
            float minDist = ball0->radius + ball1->radius;
            if(dist < minDist){
                float angle = atan2(dy, dx);
                float tx = ball0->x + dx / dist * minDist;
                float ty = ball0->y + dy / dist * minDist;
                float ax = (tx - ball1->x) * spring;
                float ay = (ty - ball1->y) * spring;
                ball0->vx -= ax;
                ball0->vy -= ay;
                ball1->vx += ax;
                ball1->vy += ay;
            }
        }
    }
    
    for(int i=0; i<numBalls; i++) {
        Ball *ball = balls[i];
        move(ball);
        ball->update();
    }
}

void ofApp::move(Ball *ball) {
    ball->vy += gravity;
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
