#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    ship.x = ofGetWidth()/2;
    ship.y = ofGetHeight()/2;
    ship.setStrokeColor(ofColor(255, 0, 0));
    ship.setFillColor(ofColor(255, 255, 255));
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ship.rotation += vr;
    float angle = ship.rotation * PI / 180;
    float ax = cos(angle) * thrust;
    float ay = sin(angle) * thrust;
    vx += ax;
    vy += ay;
    vx *= friction;
    vy *= friction;
    ship.x += vx;
    ship.y += vy;
    float left = 0;
    float right = ofGetWidth();
    float top = 0;
    float bottom = ofGetHeight();
    
    if(ship.x - ship.width / 2 > right){
        ship.x = left - ship.width / 2;
    }else if (ship.x + ship.width / 2 < left){
        ship.x = right + ship.width / 2;
    }
    
    if(ship.y - ship.height / 2 > bottom){
        ship.y = top - ship.height / 2;
    }else if (ship.y < top - ship.height / 2){
        ship.y = bottom + ship.height / 2;
    }  
    
    ship.update();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case OF_KEY_LEFT:
            vr = -5;
            break;
        case OF_KEY_RIGHT:
            vr = 5;
            break;
        case OF_KEY_UP:
            thrust = 0.2;
            ship.gun(true);
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    vr = 0;
    thrust = 0;
    ship.gun(false);
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
