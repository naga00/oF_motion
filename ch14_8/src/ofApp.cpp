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
    float dx = mouseX - segment1->x;
    float dy = mouseY - segment1->y;
    float dist = sqrt(dx * dx + dy * dy);
    
    float a = 100;
    float b = 100;
    float c = min(dist, a + b);
    
    float B = acos((b * b - a * a - c * c) / (-2 * a * c));
    float C = acos((c * c - a * a - b * b) / (-2 * a * b));
    float D = atan2(dy, dx);
    float E = D + B + PI + C;
    
    segment1->rotation = (D + B) * 180 / PI;
    segment0->x = segment1->getPin()->x;
    segment0->y = segment1->getPin()->y;
    segment0->rotation = E * 180 / PI;
    
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
