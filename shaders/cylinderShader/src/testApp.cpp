#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofBackground(50, 50, 50);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
	
	cylinderShader.setGeometryInputType(GL_LINES);
	cylinderShader.setGeometryOutputType(GL_TRIANGLE_STRIP);
	cylinderShader.setGeometryOutputCount(9*2);
	cylinderShader.load("shaders/vert.glsl", "shaders/frag.glsl", "shaders/geom_cylinder.glsl");
	
    sphereShader.setGeometryInputType(GL_LINES);
	sphereShader.setGeometryOutputType(GL_TRIANGLE_STRIP);
	sphereShader.setGeometryOutputCount(6 * 13 * 2);
	sphereShader.load("shaders/vert.glsl", "shaders/frag.glsl", "shaders/geom_sphere.glsl");
	
	printf("Maximum number of output vertices support is: %i\n", cylinderShader.getGeometryMaxOutputCount());
	
    
	float r = ofGetHeight()/2;
	for(int i=0; i<100; i++) {
        mesh.addVertex(ofVec3f(ofRandom(0,1) * r - r / 2, ofRandom(0,1) * r - r / 2, ofRandom(0,1) * r - r / 2));
	}
    
	doShader = true;	
	glEnable(GL_DEPTH_TEST);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);
	ofRotateX(mouseY);
	ofRotateY(mouseX);
    
    if(doShader) {
        sphereShader.begin();
        mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
        mesh.draw();
        sphereShader.end();
		
        cylinderShader.begin();
        mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
        mesh.draw();
        cylinderShader.end();
		
	} else {
        mesh.draw();
    }
    
	ofPopMatrix();
	
	ofDrawBitmapString("fps: " + ofToString((int)ofGetFrameRate()) + "\nPress 's' to toggle cylinderShader: " + (doShader ? "ON" : "OFF"), 20, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	if( key == 's' ){
		doShader = !doShader;
	}	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
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

