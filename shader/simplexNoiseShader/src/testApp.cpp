#include "testApp.h"


#define STRINGIFY(A) #A

//--------------------------------------------------------------
void testApp::setup(){
    initShaders();
    fbos[0].allocate(1280, 720, GL_RGBA32F);
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
    shaders[1].begin();
    shaders[1].setUniform1f("time", ofGetFrameNum() * 0.001);
    fbos[0].draw(0,0);
    shaders[1].end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}


//--------------------------------------------------------------
void testApp::initShaders() {
    string shaderProgram;
    shaders[0].load("shader.vert", "shader00.frag");
    shaders[1].load("shader.vert", "shader01.frag");
}