#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    segment0 = new Segment(100, 30);
    segment0->x = 200;
    segment0->y = 100;
    
    segment1 = new Segment(100, 20);
    segment1->x = segment0->getPin()->x;
    segment1->y = segment0->getPin()->y;
    
    segment2 = new Segment(100, 30);
    segment2->x = 200;
    segment2->y = 100;
    
    segment3 = new Segment(100, 20);
    segment3->x = segment2->getPin()->x;
    segment3->y = segment2->getPin()->y;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0);
    ofNoFill();
    walk(segment0, segment1, cycle);
    walk(segment2, segment3, cycle + PI);
    cycle += 0.05;
    segment0->update();
    segment1->update();
    segment2->update();
    segment3->update();
}

void ofApp::walk(Segment* segA, Segment* segB, float cyc) {
    float angleA = sin(cyc) * 45 + 90;
    float angleB = sin(cyc + offset) * 45 + 45;
    segA->rotation = angleA;
    segB->rotation = segA->rotation + angleB;
    segB->x = segA->getPin()->x;
    segB->y = segA->getPin()->y;
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
