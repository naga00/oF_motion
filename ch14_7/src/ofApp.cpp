#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    ball = new Ball(20);
    ball->vx = 10;
    ball->setFillColor(ofColor(255, 0, 0));
    
    for(int i=0; i<numSegments; i++) {
        segments[i] = new Segment(50, 10);
        segments[i]->setStrokeColor(ofColor(0, 0, 0));
    }
    segments[numSegments-1]->x = ofGetWidth()/2;
    segments[numSegments-1]->y = ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0);
    
    moveBall();
    ofPoint* target = reach(segments[0], ball->x, ball->y);
    for(int i=1; i<numSegments; i++){
        Segment* segment = segments[i];
        target = reach(segment, target->x, target->y);
    }
    
    for(int i=numSegments - 1; i>0; i--){
        Segment* segmentA = segments[i];
        Segment* segmentB = segments[i - 1];
        position(segmentB, segmentA);
    }
    
    checkHit();
    ofNoFill();
    ofSetColor(0, 255, 0);
    for(int i=0; i<numSegments; i++){
        segments[i]->update();
    }
    
    ofFill();
    ball->update();
}

ofPoint* ofApp::reach(Segment* segment, float xpos, float ypos) {
    float dx = xpos - segment->x;
    float dy = ypos - segment->y;
    float angle = atan2(dy, dx);
    segment->rotation = angle * 180 / PI;
    float w = segment->getPin()->x - segment->x;
    float h = segment->getPin()->y - segment->y;
    float tx = xpos - w;
    float ty = ypos - h;
    return new ofPoint(tx, ty);
}

void ofApp::position(Segment* segmentA, Segment* segmentB) {
    segmentA->x = segmentB->getPin()->x;
    segmentA->y = segmentB->getPin()->y;
}

void ofApp::moveBall() {
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

void ofApp::checkHit() {
    Segment* segment = segments[0];
    float dx = segment->getPin()->x - ball->x;
    float dy = segment->getPin()->y - ball->y;
    float dist = sqrt(dx * dx + dy * dy);
    if(dist < ball->radius){
        ball->vx += ofRandom(-1, 1);
        ball->vy -= 1;
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
