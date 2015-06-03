#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    vpX = ofGetWidth()/2;
    vpY = ofGetHeight()/2;
    points[0] =  new Point3D(-150, -250, 100);
    points[1] =  new Point3D( 150, -250, 100);
    points[2] =  new Point3D( 150, -150, 100);
    points[3] =  new Point3D( -50, -150, 100);
    points[4] =  new Point3D( -50,  -50, 100);
    points[5] =  new Point3D(  50,  -50, 100);
    points[6] =  new Point3D(  50,   50, 100);
    points[7] =  new Point3D( -50,   50, 100);
    points[8] =  new Point3D( -50,  150, 100);
    points[9] =  new Point3D( 150,  150, 100);
    points[10] = new Point3D( 150,  250, 100);
    points[11] = new Point3D(-150,  250, 100);
    for(int i=0; i<numPoints; i++) {
        points[i]->setVanishingPoint(vpX, vpY);
        points[i]->setCenter(0, 0, 200);
    }
    ofSetColor(ofColor(0));
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    float angleX = (mouseY - vpY) * 0.001;
    float angleY = (mouseX - vpX) * 0.001;
    for(int i=0; i<numPoints; i++) {
        Point3D* point = points[i];
        point->rotateX(angleX);
        point->rotateY(angleY);
    }
    for(int i = 1; i < numPoints; i++) {
        ofLine(points[i-1]->screenX(), points[i-1]->screenY(), points[i]->screenX(), points[i]->screenY());
    }
    ofLine(points[numPoints - 1]->screenX(), points[numPoints - 1]->screenY(), points[0]->screenX(), points[0]->screenY());
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
