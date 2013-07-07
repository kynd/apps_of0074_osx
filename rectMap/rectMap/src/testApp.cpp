#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    r = new RectMap(0,0,ofGetWidth(),ofGetHeight());
    r->addRandomChildren(35);
    r->phase = 1;
    /*
    for (int i = 0; i < 15; i ++) {
        r->addRandomChild(ofColor(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255)));
        r->phase = 1;                               
    }
     */
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
    
    r->expandChildren();
}

//--------------------------------------------------------------
void testApp::draw(){
    r->draw();
    /*
    ofPushStyle();
    ofNoFill();
    ofSetColor(255, 0, 0);
    if (r->n < r->children.size()) {
        ofRect(r->children[r->n]->x - 5, r->children[r->n]->y - 5, r->children[r->n]->width + 10, r->children[r->n]->height + 10);
    }
    ofPopStyle();
     */
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
    v.save();
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