#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    for(int i=0; i<numSegments; i++) {
        segments[i] = new Segment(50, 10);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0);
    ofNoFill();
    drag(segments[0], mouseX, mouseY);
    for(int i=1; i<numSegments; i++){
        Segment* segmentA = segments[i];
        Segment* segmentB = segments[i - 1];
        drag(segmentA, segmentB->x, segmentB->y);
    }
    for(int i=0; i<numSegments; i++){
        segments[i]->update();
    }
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
