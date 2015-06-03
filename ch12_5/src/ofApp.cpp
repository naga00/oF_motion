#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    for(int i=0; i<numParticles; i++) {
        particles[i] = new Ball(5);
        particles[i]->x = ofRandom(ofGetWidth());
        particles[i]->y = ofRandom(ofGetHeight());
        particles[i]->vx = ofRandom(-3, 3);
        particles[i]->vy = ofRandom(-3, 3);
        particles[i]->setFillColor(ofColor(255, 255, 255));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<numParticles; i++){
        Ball* particle = particles[i];
        particle->x += particle->vx;
        particle->y += particle->vy;
        if(particle->x > ofGetWidth()){
            particle->x = 0;
        }else if(particle->x < 0){
            particle->x = ofGetWidth();
        }
        if(particle->y > ofGetHeight()){
            particle->y = 0;
        }else if(particle->y < 0){
            particle->y = ofGetHeight();
        }
        particle->update();
    }
    
    for(int i=0; i<numParticles; i++){
        Ball* partA = particles[i];
        for(int j=i+1; j<numParticles; j++){
            Ball* partB = particles[j];
            spring(partA, partB);
        }
    }
}

void ofApp::spring(Ball* partA, Ball* partB) {
    float dx = partB->x - partA->x;
    float dy = partB->y - partA->y;
    float dist = sqrt(dx * dx + dy * dy);
    if(dist < minDist) {
        float ax = dx * springAmount;
        float ay = dy * springAmount;
        partA->vx += ax;
        partA->vy += ay;
        partB->vx -= ax;
        partB->vy -= ay;
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
