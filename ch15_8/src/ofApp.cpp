#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    vpX = ofGetWidth()/2;
    vpY = ofGetHeight()/2;
    
    for(int i=0; i<numTrees; i++) {
        trees[i] = new Tree();
        trees[i]->xpos = ofRandom(-1000, 1000);
        trees[i]->ypos = floor;
        trees[i]->zpos = ofRandom(10000);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<numTrees; i++) {
        Tree* tree = trees[i];
        move(tree);
    }
    vz *= friction;
    sortZ();
}

void ofApp::move(Tree* tree) {
    tree->zpos += vz;
    if(tree->zpos < -fl) {
        tree->zpos += 10000;
    }
    if(tree->zpos > 10000 - fl) {
        tree->zpos -= 10000;
    }
    float scale = fl / (fl + tree->zpos);
    tree->scaleX = tree->scaleY = scale;
    tree->x = vpX + tree->xpos * scale;
    tree->y = vpY + tree->ypos * scale;
    tree->setStrokeColor(ofColor(255, 255, 255));
    tree->setStrokeColor(ofColor(255, 255, 255, 200 + 55*scale));
}

void ofApp::sortZ() {
    for(int i=0; i<numTrees - 1; i++) {
        for(int j=numTrees-1; j>i; j--) {
            if(trees[j]->zpos > trees[j-1]->zpos) {
                Tree* t = trees[j];
                trees[j] = trees[j-1];
                trees[j-1] = t;
            }
        }
    }
    
    for(int i=0; i<numTrees; i++) {
        Tree* tree = trees[i];
        tree->update();
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
