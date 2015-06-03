#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    vpX = ofGetWidth()/2;
    vpY = ofGetHeight()/2;
    points[0] = new Point3D( -50, -250,  -50);
    points[1] = new Point3D(  50, -250,  -50);
    points[2] = new Point3D( 200,  250,  -50);
    points[3] = new Point3D( 100,  250,  -50);
    points[4] = new Point3D(  50,  100,  -50);
    points[5] = new Point3D( -50,  100,  -50);
    points[6] = new Point3D(-100,  250,  -50);
    points[7] = new Point3D(-200,  250,  -50);
    points[8] = new Point3D(   0, -150,  -50);
    points[9] = new Point3D(  50,    0,  -50);
    points[10] = new Point3D( -50,   0,  -50);
    
    points[11] = new Point3D( -50, -250,  50);
    points[12] = new Point3D(  50, -250,  50);
    points[13] = new Point3D( 200,  250,  50);
    points[14] = new Point3D( 100,  250,  50);
    points[15] = new Point3D(  50,  100,  50);
    points[16] = new Point3D( -50,  100,  50);
    points[17] = new Point3D(-100,  250,  50);
    points[18] = new Point3D(-200,  250,  50);
    points[19] = new Point3D(   0, -150,  50);
    points[20] = new Point3D(  50,    0,  50);
    points[21] = new Point3D( -50,    0,  50);
    for(int i=0; i<numPoints; i++) {
        points[i]->setVanishingPoint(vpX, vpY);
        points[i]->setCenter(0, 0, 200);
    }
    triangles[0] = new TriangleObj(points[0],   points[1],  points[8],  ofColor(102, 102, 204, 127));
    triangles[1] = new TriangleObj(points[1],   points[9],  points[8],  ofColor(102, 102, 204, 127));
    triangles[2] = new TriangleObj(points[1],   points[2],  points[9],  ofColor(102, 102, 204, 127));
    triangles[3] = new TriangleObj(points[2],   points[4],  points[9],  ofColor(102, 102, 204, 127));
    triangles[4] = new TriangleObj(points[2],   points[3],  points[4],  ofColor(102, 102, 204, 127));
    triangles[5] = new TriangleObj(points[4],   points[5],  points[9],  ofColor(102, 102, 204, 127));
    triangles[6] = new TriangleObj(points[9],   points[5],  points[10], ofColor(102, 102, 204, 127));
    triangles[7] = new TriangleObj(points[5],   points[6],  points[7],  ofColor(102, 102, 204, 127));
    triangles[8] = new TriangleObj(points[5],   points[7],  points[10], ofColor(102, 102, 204, 127));
    triangles[9] = new TriangleObj(points[0],   points[10], points[7],  ofColor(102, 102, 204, 127));
    triangles[10] =  new TriangleObj(points[0], points[8],  points[10], ofColor(102, 102, 204, 127));
    
    triangles[11] =  new TriangleObj(points[11], points[19], points[12], ofColor(204, 102, 102, 127));
    triangles[12] =  new TriangleObj(points[12], points[19], points[20], ofColor(204, 102, 102, 127));
    triangles[13] =  new TriangleObj(points[12], points[20], points[13], ofColor(204, 102, 102, 127));
    triangles[14] =  new TriangleObj(points[13], points[20], points[15], ofColor(204, 102, 102, 127));
    triangles[15] =  new TriangleObj(points[13], points[15], points[14], ofColor(204, 102, 102, 127));
    triangles[16] =  new TriangleObj(points[15], points[20], points[16], ofColor(204, 102, 102, 127));
    triangles[17] =  new TriangleObj(points[20], points[21], points[16], ofColor(204, 102, 102, 127));
    triangles[18] =  new TriangleObj(points[16], points[18], points[17], ofColor(204, 102, 102, 127));
    triangles[19] =  new TriangleObj(points[16], points[21], points[18], ofColor(204, 102, 102, 127));
    triangles[20] =  new TriangleObj(points[11], points[18], points[21], ofColor(204, 102, 102, 127));
    triangles[21] =  new TriangleObj(points[11], points[21], points[19], ofColor(204, 102, 102, 127));
    
    triangles[22] =  new TriangleObj(points[0],  points[11], points[1],  ofColor(204, 204, 102, 127));
    triangles[23] =  new TriangleObj(points[11], points[12], points[1],  ofColor(204, 204, 102, 127));
    triangles[24] =  new TriangleObj(points[1],  points[12], points[2],  ofColor(204, 204, 102, 127));
    triangles[25] =  new TriangleObj(points[12], points[13], points[2],  ofColor(204, 204, 102, 127));
    triangles[26] =  new TriangleObj(points[3],  points[2],  points[14], ofColor(204, 204, 102, 127));
    triangles[27] =  new TriangleObj(points[2],  points[13], points[14], ofColor(204, 204, 102, 127));
    triangles[28] =  new TriangleObj(points[4],  points[3],  points[15], ofColor(204, 204, 102, 127));
    triangles[29] =  new TriangleObj(points[3],  points[14], points[15], ofColor(204, 204, 102, 127));
    triangles[30] =  new TriangleObj(points[5],  points[4],  points[16], ofColor(204, 204, 102, 127));
    triangles[31] =  new TriangleObj(points[4],  points[15], points[16], ofColor(204, 204, 102, 127));
    triangles[32] =  new TriangleObj(points[6],  points[5],  points[17], ofColor(204, 204, 102, 127));
    triangles[33] =  new TriangleObj(points[5],  points[16], points[17], ofColor(204, 204, 102, 127));
    triangles[34] =  new TriangleObj(points[7],  points[6],  points[18], ofColor(204, 204, 102, 127));
    triangles[35] =  new TriangleObj(points[6],  points[17], points[18], ofColor(204, 204, 102, 127));
    triangles[36] =  new TriangleObj(points[0],  points[7],  points[11], ofColor(204, 204, 102, 127));
    triangles[37] =  new TriangleObj(points[7],  points[18], points[11], ofColor(204, 204, 102, 127));
    
    triangles[38] =  new TriangleObj(points[8],  points[9],  points[19], ofColor(204, 204, 102, 127));
    triangles[39] =  new TriangleObj(points[9],  points[20], points[19], ofColor(204, 204, 102, 127));
    triangles[40] =  new TriangleObj(points[9],  points[10], points[20], ofColor(204, 204, 102, 127));
    triangles[41] =  new TriangleObj(points[10], points[21], points[20], ofColor(204, 204, 102, 127));
    triangles[42] =  new TriangleObj(points[10], points[8],  points[21], ofColor(204, 204, 102, 127));
    triangles[43] =  new TriangleObj(points[8],  points[19], points[21], ofColor(204, 204, 102, 127));
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
    for(int i=0; i<numTriangles; i++) {
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
