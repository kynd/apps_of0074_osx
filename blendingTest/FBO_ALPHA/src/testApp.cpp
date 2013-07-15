#include "testApp.h"


#define STRINGIFY(A) #A

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(128, 128, 128);
    ofEnableAlphaBlending();
    initShaders();
    fbos[0].allocate(640, 360, GL_RGBA32F);
    fbos[1].allocate(640, 360, GL_RGBA32F);
    
    ofPushStyle();
    fbos[0].begin();
    ofClear(0, 0, 0, 0);
    drawBoxes();
    fbos[0].end();
    
    ofPushStyle();
    fbos[1].begin();
    ofClear(128, 128, 128, 255);
    drawBoxes();
    fbos[1].end();
}

//--------------------------------------------------------------
void testApp::update(){
}
//--------------------------------------------------------------
void testApp::drawBoxes(){
    ofPushStyle();
    ofSetColor(255, 60, 0, 255);
    ofRect(20, 30, 120, 100);
    ofSetColor(0, 60, 255, 255);
    ofRect(80, 50, 120, 100);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    ofSetColor(255, 60, 0, 128);
    ofRect(340, 30, 120, 100);
    ofSetColor(0, 60, 255, 128);
    ofRect(400, 50, 120, 100);
    glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE);
    ofSetColor(255, 60, 0, 128);
    ofRect(20, 170, 120, 100);
    ofSetColor(0, 60, 255, 128);
    ofRect(80, 190, 120, 100);
    
    ofSetColor(255,255,255);
    ofDrawBitmapString("No Alpha", 20,40);
    
    ofDrawBitmapString("Alpha 0.5", 340,40);
    ofDrawBitmapString("glBlendFunc(GL_SRC_ALPHA,", 340,55);
    ofDrawBitmapString("GL_ONE_MINUS_SRC_ALPHA)", 340,70);
    
    ofDrawBitmapString("Alpha 0.5", 20,180);
    ofDrawBitmapString("glBlendFuncSeparate(GL_SRC_ALPHA, ", 20,195);
    ofDrawBitmapString("GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE)", 20,210);
    
    ofPopStyle();
}


//--------------------------------------------------------------
void testApp::draw(){
    /*
    for (int i = 0; i < ofGetHeight(); i += 80) {
        ofPushStyle();
        ofSetColor(0, 0, 0);
        ofRect(0, i, 1280, 40);
        ofPopStyle();
    }
    */
    drawBoxes();
    fbos[0].draw(640, 0);
    fbos[1].draw(0, 360);
    shaders[0].begin();
    fbos[0].draw(640, 360);
    shaders[0].end();
    
    ofPushStyle();
    ofSetColor(255,255,255);
    ofDrawBitmapString("0) No FBO", 20, 20);
    ofDrawBitmapString("1) FBO with Transparent Background", 660, 20);
    ofDrawBitmapString("2) FBO with Non-Transparent Background", 20, 370);
    ofDrawBitmapString("3) Alpha Value in FBO 1)", 660, 370);
    
    ofPopStyle();
    
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
    shaders[0].load("shader.vert", "alpha.frag");
}