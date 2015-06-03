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
    triangles[0] =new TriangleObj(points[0],   points[1],  points[8],  0xcccccc);
    triangles[1] =new TriangleObj(points[1],   points[9],  points[8],  0xcccccc);
    triangles[2] =new TriangleObj(points[1],   points[2],  points[9],  0xcccccc);
    triangles[3] =new TriangleObj(points[2],   points[4],  points[9],  0xcccccc);
    triangles[4] =new TriangleObj(points[2],   points[3],  points[4],  0xcccccc);
    triangles[5] =new TriangleObj(points[4],   points[5],  points[9],  0xcccccc);
    triangles[6] =new TriangleObj(points[9],   points[5],  points[10], 0xcccccc);
    triangles[7] =new TriangleObj(points[5],   points[6],  points[7],  0xcccccc);
    triangles[8] =new TriangleObj(points[5],   points[7],  points[10], 0xcccccc);
    triangles[9] =new TriangleObj(points[0],   points[10], points[7],  0xcccccc);
    triangles[10] = new TriangleObj(points[0], points[8],  points[10], 0xcccccc);
    
    triangles[11] = new TriangleObj(points[11], points[19], points[12], 0xcccccc);
    triangles[12] = new TriangleObj(points[12], points[19], points[20], 0xcccccc);
    triangles[13] = new TriangleObj(points[12], points[20], points[13], 0xcccccc);
    triangles[14] = new TriangleObj(points[13], points[20], points[15], 0xcccccc);
    triangles[15] = new TriangleObj(points[13], points[15], points[14], 0xcccccc);
    triangles[16] = new TriangleObj(points[15], points[20], points[16], 0xcccccc);
    triangles[17] = new TriangleObj(points[20], points[21], points[16], 0xcccccc);
    triangles[18] = new TriangleObj(points[16], points[18], points[17], 0xcccccc);
    triangles[19] = new TriangleObj(points[16], points[21], points[18], 0xcccccc);
    triangles[20] = new TriangleObj(points[11], points[18], points[21], 0xcccccc);
    triangles[21] = new TriangleObj(points[11], points[21], points[19], 0xcccccc);
    
    triangles[22] = new TriangleObj(points[0],  points[11], points[1],  0xcccccc);
    triangles[23] = new TriangleObj(points[11], points[12], points[1],  0xcccccc);
    triangles[24] = new TriangleObj(points[1],  points[12], points[2],  0xcccccc);
    triangles[25] = new TriangleObj(points[12], points[13], points[2],  0xcccccc);
    triangles[26] = new TriangleObj(points[3],  points[2],  points[14], 0xcccccc);
    triangles[27] = new TriangleObj(points[2],  points[13], points[14], 0xcccccc);
    triangles[28] = new TriangleObj(points[4],  points[3],  points[15], 0xcccccc);
    triangles[29] = new TriangleObj(points[3],  points[14], points[15], 0xcccccc);
    triangles[30] = new TriangleObj(points[5],  points[4],  points[16], 0xcccccc);
    triangles[31] = new TriangleObj(points[4],  points[15], points[16], 0xcccccc);
    triangles[32] = new TriangleObj(points[6],  points[5],  points[17], 0xcccccc);
    triangles[33] = new TriangleObj(points[5],  points[16], points[17], 0xcccccc);
    triangles[34] = new TriangleObj(points[7],  points[6],  points[18], 0xcccccc);
    triangles[35] = new TriangleObj(points[6],  points[17], points[18], 0xcccccc);
    triangles[36] = new TriangleObj(points[0],  points[7],  points[11], 0xcccccc);
    triangles[37] = new TriangleObj(points[7],  points[18], points[11], 0xcccccc);
    
    triangles[38] = new TriangleObj(points[8],  points[9],  points[19], 0xcccccc);
    triangles[39] = new TriangleObj(points[9],  points[20], points[19], 0xcccccc);
    triangles[40] = new TriangleObj(points[9],  points[10], points[20], 0xcccccc);
    triangles[41] = new TriangleObj(points[10], points[21], points[20], 0xcccccc);
    triangles[42] = new TriangleObj(points[10], points[8],  points[21], 0xcccccc);
    triangles[43] = new TriangleObj(points[8],  points[19], points[21], 0xcccccc);
    
    Light* light = new Light(-100, -100, -100, 1);
    for(int i=0; i<numTriangles; i++) {
        triangles[i]->light = light;
    }
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
    sortZ();
    for(int i=0; i<numTriangles; i++) {
        triangles[i]->update();
    }
}

void ofApp::sortZ() {
    for(int i=0; i<numTriangles-1; i++) {
        for(int j=numTriangles-1; j>i; j--) {
            if(triangles[j]->zpos > triangles[j-1]->zpos) {
                TriangleObj* triangle = triangles[j];
                triangles[j] = triangles[j-1];
                triangles[j-1] = triangle;
            }
        }
    }
    for(int i=0; i<numTriangles; i++) {
        TriangleObj* triangle = triangles[i];
        triangle->update();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case OF_KEY_UP:
            offsetY = -5;
            break;
        case OF_KEY_DOWN:
            offsetY = 5;
            break;
        case OF_KEY_LEFT:
            offsetX = -5;
            break;
        case OF_KEY_RIGHT:
            offsetX = 5;
            break;
        default:
            break;
    }
    for(int i= 0; i < numPoints; i++) {
        points[i]->x += offsetX;
        points[i]->y += offsetY;
    }
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
