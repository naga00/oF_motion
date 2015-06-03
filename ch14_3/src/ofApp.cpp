#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    segment0 = new Segment(100, 20);
    segment1 = new Segment(100, 20);
    segment1->x = ofGetWidth()/2;
    segment1->y = ofGetHeight()/2;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0);
    ofNoFill();
    drag(segment0, mouseX, mouseY);
    drag(segment1, segment0->x, segment0->y);
    segment0->update();
    segment1->update();
}

void ofApp::drag(Segment* segment, float xpos, float ypos){
    float dx = xpos - segment->x;
    float dy = ypos - segment->y;
    float angle = atan2(dy, dx);
    segment->rotation = angle * 180 / PI;
    float w = segment->getPin()->x - segment->x;
    float h = segment->getPin()->y - segment->y;
    segment->x = xpos - w;
    segment->y = ypos - h;
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
