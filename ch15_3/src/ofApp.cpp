#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    vpX = ofGetWidth()/2;
    vpY = ofGetHeight()/2;
    ball = new Ball(50);
    ball->setFillColor(ofColor(255, 0, 0));
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    xpos += vx;
    ypos += vy;
    zpos += vz;
    
    vx *= friction;
    vy *= friction;
    vz *= friction;
    
    if(zpos > -fl) {
        float scale = fl / (fl + zpos);
        ball->scaleX = ball->scaleY = scale;
        ball->x = vpX + xpos * scale;
        ball->y = vpY + ypos * scale;
        ball->visible = true;
    }else{
        ball->visible = false;
    }  
    ball->update();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case OF_KEY_UP:
            vy -= 1;
            break;
        case OF_KEY_DOWN:
            vy += 1;
            break;
        case OF_KEY_LEFT:
            vx -= 1;
            break;
        case OF_KEY_RIGHT:
            vx += 1;
            break;
        case OF_KEY_ALT:
            vz += 1;
            break;
        case OF_KEY_CONTROL:
            vz -= 1;
            break;
        default:
            break;
    }
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
