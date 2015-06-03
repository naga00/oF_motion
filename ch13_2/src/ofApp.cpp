#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    segment0 = new Segment(100, 20);
    segment0->x = 200;
    segment0->y = 100;
    
    segment1 = new Segment(100, 20);
    segment1->x = segment0->getPin()->x;
    segment1->y = segment0->getPin()->y;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0);
    ofNoFill();
    cycle += 0.05;
    float angle0 = sin(cycle) * 45 + 90;
    float angle1 = sin(cycle) * 45 + 45;
    segment0->rotation = angle0;
    segment1->rotation = segment0->rotation + angle1;
    segment1->x = segment0->getPin()->x;
    segment1->y = segment0->getPin()->y;
    segment0->update();
    segment1->update();
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
