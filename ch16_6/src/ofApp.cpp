#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    vpX = ofGetWidth()/2;
    vpY = ofGetHeight()/2;
    points[0] = new Point3D( -50, -250, 100);
    points[1] = new Point3D(  50, -250, 100);
    points[2] = new Point3D( 200,  250, 100);
    points[3] = new Point3D( 100,  250, 100);
    points[4] = new Point3D(  50,  100, 100);
    points[5] = new Point3D( -50,  100, 100);
    points[6] = new Point3D(-100,  250, 100);
    points[7] = new Point3D(-200,  250, 100);
    points[8] = new Point3D(   0, -150, 100);
    points[9] = new Point3D(  50,    0, 100);
    points[10] = new Point3D(-50,    0, 100);

    for(int i=0; i<numPoints; i++) {
        points[i]->setVanishingPoint(vpX, vpY);
        points[i]->setCenter(0, 0, 200);
    }
    triangles[0] =  new TriangleObj(points[0], points[1], points[8], ofColor(255, 204, 204));
    triangles[1] =  new TriangleObj(points[1], points[9], points[8], ofColor(255, 204, 204));
    triangles[2] =  new TriangleObj(points[1], points[2], points[9], ofColor(255, 204, 204));;
    triangles[3] =  new TriangleObj(points[2], points[4], points[9], ofColor(255, 204, 204));
    triangles[4] =  new TriangleObj(points[2], points[3], points[4], ofColor(255, 204, 204));
    triangles[5] =  new TriangleObj(points[4], points[5], points[9], ofColor(255, 204, 204));
    triangles[6] =  new TriangleObj(points[9], points[5], points[10], ofColor(255, 204, 204));
    triangles[7] =  new TriangleObj(points[5], points[6], points[7], ofColor(255, 204, 204));
    triangles[8] =  new TriangleObj(points[5], points[7], points[10], ofColor(255, 204, 204));
    triangles[9] =  new TriangleObj(points[0], points[10],points[7], ofColor(255, 204, 204));
    triangles[10] = new TriangleObj(points[0], points[8], points[10], ofColor(255, 204, 204));

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
    for(int i=0; i<numPoints; i++) {
        triangles[i]->update();
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
