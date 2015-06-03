#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    for(int i=0; i<numParticles; i++) {
        particles[i] = new Ball(5);
        particles[i]->x = ofRandom(ofGetWidth());
        particles[i]->y = ofRandom(ofGetHeight());
        particles[i]->mass = 1;
        particles[i]->setFillColor(ofColor(255, 0, 0));
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
        particle->update();
    }
    
    for(int i=0; i<numParticles; i++){
        Ball* partA = particles[i];
        for(int j=i+1; j<numParticles; j++){
            Ball* partB = particles[j];
            gravitate(partA, partB);
        }
    }
}

void ofApp::gravitate(Ball* partA, Ball* partB) {
    float dx = partB->x - partA->x;
    float dy = partB->y - partA->y;
    float distSQ = dx*dx + dy*dy;
    float dist = sqrt(distSQ);
    float force = partA->mass * partB->mass / distSQ;
    float ax = force * dx / dist;
    float ay = force * dy / dist;
    partA->vx += ax;
    partA->vy += ay;
    partB->vx -= ax;
    partB->vy -= ay;
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
