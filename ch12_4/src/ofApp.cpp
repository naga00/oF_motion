#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);

    Ball* sun = new Ball(100);
    sun->x = ofGetWidth()/2;
    sun->y = ofGetHeight()/2;
    sun->vx = 0;
    sun->vy = 0;
    sun->mass = 10000;
    sun->setFillColor(ofColor(255, 255, 0));
    particles.push_back(sun);
    
    Ball* planet = new Ball(10);
    planet->x = ofGetWidth()/2 + 200;
    planet->y = ofGetHeight()/2;
    planet->vy = 7;
    planet->mass = 1;
    planet->setFillColor(ofColor(0, 255, 0));
    particles.push_back(planet);
    
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
    
    for(int i=0; i<numParticles - 1; i++){
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
    partA->vx += ax / partA->mass;
    partA->vy += ay / partA->mass;
    partB->vx -= ax / partB->mass;
    partB->vy -= ay / partB->mass;
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
