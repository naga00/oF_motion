#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    for(int i=0; i<numBalls; i++) {
        float radius = 30;
        balls[i] = new Ball(radius);
        balls[i]->mass = radius;
        balls[i]->x = ofRandom(ofGetWidth());
        balls[i]->y = ofRandom(ofGetHeight());
        balls[i]->vx = ofRandom(-5, 5);
        balls[i]->vy = ofRandom(-5, 5);
        balls[i]->setFillColor(ofColor(255, 0, 0));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<numBalls; i++){
        Ball* ball = balls[i];
        ball->x += ball->vx;
        ball->y += ball->vy;
        checkWalls(ball);
        ball->update();
    }
    
    for(int i=0; i<numBalls - 1; i++){
        Ball* ballA = balls[i];
        for(int j=i+1; j<numBalls; j++){
            Ball* ballB = balls[j];
            checkCollision(ballA, ballB);
        }
    }
}

void ofApp::checkWalls(Ball *ball) {
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
