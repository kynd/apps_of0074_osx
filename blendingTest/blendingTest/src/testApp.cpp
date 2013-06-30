#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    fbo.allocate(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofClear(255, 255, 255, 255);
    ofEnableAlphaBlending();
    drawBoxes();
    
    fbo.begin();
    ofClear(255, 255, 255, 255);
    drawBoxes();
    fbo.end();
    
    
    ofSetColor(255,255,255,255);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    fbo.draw(500, 0);
}

void testApp::drawBoxes() {
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    ofSetColor(128, 200, 128, 128);
    ofRect(50, 100, 100, 100);
    
    ofSetColor(200, 128, 128, 128);
    ofRect(100, 150, 100, 100);

    glBlendFunc(GL_ZERO, GL_SRC_COLOR);
    ofSetColor(128, 200, 128, 128);
    ofRect(250, 100, 100, 100);
    
    ofSetColor(200, 128, 128, 128);
    ofRect(300, 150, 100, 100);
    
    glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE);
    ofSetColor(128, 200, 128, 128);
    ofRect(50, 300, 100, 100);
    
    ofSetColor(200, 128, 128, 128);
    ofRect(100, 350, 100, 100);
    
    glBlendFuncSeparate(GL_ZERO, GL_SRC_COLOR, GL_ONE, GL_ONE);
    ofSetColor(128, 200, 128, 128);
    ofRect(250, 300, 100, 100);
    
    ofSetColor(200, 128, 128, 128);
    ofRect(300, 350, 100, 100);
    
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