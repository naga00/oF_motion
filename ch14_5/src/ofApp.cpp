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
    ofPoint* target = reach(segment0, mouseX, mouseY);
    reach(segment1, target->x, target->y);
    segment0->x = segment1->getPin()->x;
    segment0->y = segment1->getPin()->y;
    
    segment0->update();
    segment1->update();
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
