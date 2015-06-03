#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofEnableAntiAliasing();
    ofSetFrameRate(60);

    ball = new Ball(40);
    ball->x = 100;
    ball->y = 100;
    ball->setFillColor(ofColor(255, 0, 0));
    
    lineObj = new Line();
    lineObj->setStrokeColor(ofColor(0, 0, 0));
    lineObj->lineTo(300, 0);
    lineObj->x = 50;
    lineObj->y = 200;
    lineObj->rotation = 30;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    lineObj->rotation = (ofGetWidth()/ 2 - mouseX) * 0.1;
    
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
    
    Rectangle bounds = lineObj->getBounds();
    if(ball->x > bounds.left && ball->x < bounds.right) {
        float angle = lineObj->rotation * PI / 180;
        float cosine = cos(angle);
        float sine = sin(angle);
        float x1 = ball->x - lineObj->x;
        float y1 = ball->y - lineObj->y;
        float y2 = cosine * y1 - sine * x1;
        
        if(y2 > -ball->height / 2){
            float x2 = cosine * x1 + sine * y1;
            float vx1 = cosine * ball->vx + sine * ball->vy;
            float vy1 = cosine * ball->vy - sine * ball->vx;
            y2 = -ball->height / 2;
            vy1 *= bounce;
            x1 = cosine * x2 - sine * y2;
            y1 = cosine * y2 + sine * x2;
            ball->vx = cosine * vx1 - sine * vy1;
            ball->vy = cosine * vy1 + sine * vx1;
            ball->x = lineObj->x + x1;
            ball->y = lineObj->y + y1;
        }
    }
    
    ofNoFill();
    lineObj->update();
    ofFill();
    ball->update();}

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
