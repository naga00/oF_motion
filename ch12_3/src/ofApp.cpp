#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    for(int i=0; i<numParticles; i++) {
        float size = ofRandom(25) + 5;
        particles[i] = new Ball(size);
        particles[i]->x = ofRandom(ofGetWidth());
        particles[i]->y = ofRandom(ofGetHeight());
        particles[i]->mass = size;
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
            checkCollision(partA, partB);
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

void ofApp::checkCollision(Ball *ball0, Ball *ball1) {
    float dx = ball1->x - ball0->x;
    float dy = ball1->y - ball0->y;
    float dist = sqrt(dx*dx + dy*dy);
    
    if(dist < ball0->radius + ball1->radius) {
        float angle = atan2(dy, dx);
        float sine = sin(angle);
        float cosine = cos(angle);
        
        ofPoint* pos0 = new ofPoint(0, 0);
        ofPoint* pos1 = rotate(dx, dy, sine, cosine, true);
        ofPoint* vel0 = rotate(ball0->vx, ball0->vy, sine, cosine, true);
        ofPoint* vel1 = rotate(ball1->vx, ball1->vy, sine, cosine, true);
        
        float vxTotal = vel0->x - vel1->x;
        vel0->x = ((ball0->mass - ball1->mass) * vel0->x + 2 * ball1->mass * vel1->x) / (ball0->mass + ball1->mass);
        vel1->x = vxTotal + vel0->x;
        
        float absV = abs(vel0->x) + abs(vel1->x);
        float overlap = (ball0->radius + ball1->radius)  - abs(pos0->x - pos1->x);
        pos0->x += vel0->x / absV * overlap;
        pos1->x += vel1->x / absV * overlap;
        
        ofPoint* pos0F = rotate(pos0->x, pos0->y, sine, cosine, false);
        ofPoint* pos1F = rotate(pos1->x, pos1->y, sine, cosine, false);
        
        ball1->x = ball0->x + pos1F->x;
        ball1->y = ball0->y + pos1F->y;
        ball0->x = ball0->x + pos0F->x;
        ball0->y = ball0->y + pos0F->y;
        
        ofPoint* vel0F = rotate(vel0->x, vel0->y, sine, cosine, false);
        ofPoint* vel1F = rotate(vel1->x, vel1->y, sine, cosine,false);
        ball0->vx = vel0F->x;
        ball0->vy = vel0F->y;
        ball1->vx = vel1F->x;
        ball1->vy = vel1F->y;
    }
}

ofPoint* ofApp::rotate(float x, float y, float sine, float cosine, Boolean reverse) {
    ofPoint *result = new ofPoint(0, 0);
    if(reverse){
        result->x = x * cosine + y * sine;
        result->y = y * cosine - x * sine;
    }else{
        result->x = x * cosine - y * sine;
        result->y = y * cosine + x * sine;
    }
    return result;
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
