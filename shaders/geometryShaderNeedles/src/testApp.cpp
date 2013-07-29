#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofBackground(0,0,0);
	
    sphereShader.setGeometryInputType(GL_POINTS);
	sphereShader.setGeometryOutputType(GL_TRIANGLE_STRIP);
	sphereShader.setGeometryOutputCount(6 * 13 * 2);
	sphereShader.load("shaders/vert.glsl", "shaders/frag.glsl", "shaders/geom_sphere.glsl");
    
	cylinderShader.setGeometryInputType(GL_LINES);
	cylinderShader.setGeometryOutputType(GL_TRIANGLE_STRIP);
	cylinderShader.setGeometryOutputCount((5 + 1) * (4 + 1) * 2);
	cylinderShader.load("shaders/vert.glsl", "shaders/frag.glsl", "shaders/geom_needle.glsl");
	
	printf("Maximum number of output vertices support is: %i\n", cylinderShader.getGeometryMaxOutputCount());
	
    
	float r = ofGetHeight()/2;
	for(int i = 0; i < 50; i++) {
        particles.push_back(new Particle());
	}
    
    //--------------------------------------------------------------
	doShader = true;
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
	glEnable(GL_DEPTH_TEST);
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i = 0; i < particles.size(); i++) {
        particles[i]->update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);
    /*
    mesh.clear();
    for(int i = 0; i < particles.size(); i++) {
        mesh.addVertex(particles[i]->pos);
	}
     */
    
    if(doShader) {
        cylinderShader.begin();
        drawLines();
        cylinderShader.end();
		
	} else {
        drawLines();
    }
    
	ofPopMatrix();
	//v.save();
	//ofDrawBitmapString("fps: " + ofToString((int)ofGetFrameRate()) + "\nPress 's' to toggle shader: " + (doShader ? "ON" : "OFF"), 20, 20);
}

//--------------------------------------------------------------
void testApp::drawLines(){
    
    for(int i = 0; i < particles.size() - 1; i ++) {
        for(int j = 0; j < particles.size(); j ++) {
            float dist = particles[i]->pos.distance(particles[j]->pos);
            if (dist < 200) {
                
                //cylinderShader.setUniform1f("radius", (200 - dist) / 10);
                ofLine(particles[i]->pos, particles[j]->pos);
            }
        }
	}
    
    //mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    //mesh.draw();
}

//--------------------------------------------------------------
void testApp::drawPoints(){
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.draw();
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

