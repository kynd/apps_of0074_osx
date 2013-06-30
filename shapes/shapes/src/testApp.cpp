#include "testApp.h"

#define STRINGIFY(A) #A
//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
    initShader();
    
    glEnable(GL_DEPTH_TEST);
    
    Shape* s;
    DisplayObject* d;
    
    s = new Cuboid();
    disps.push_back(new DisplayObject(s));
    s = new Grid();
    disps.push_back(new DisplayObject(s));
    s = new Icosphere();
    disps.push_back(new DisplayObject(s));
    
    float span = ofGetWidth() / (disps.size() + 1);
    for (int i = 0; i < disps.size(); i ++) {
        disps[i]->x = (i + 1) * span - ofGetWidth() / 2;
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    float lightAngle = ofGetElapsedTimef();
    float lightDir[3] = {cos(lightAngle), 0.3, sin(lightAngle)};
    float ambientColor[4] = {0.2, 0.2, 0.2, 1.0};
    float diffuseColor[4] = {0.5, 0.5, 0.5, 1.0};
    float specularColor[4] = {1.0, 1.0, 1.0, 1.0};
    shader.begin();
    shader.setUniform3fv("lightDir", lightDir);
    shader.setUniform4fv("ambientColor", ambientColor);
    shader.setUniform4fv("diffuseColor", diffuseColor);
    shader.setUniform4fv("specularColor", specularColor);
    
    for (int i = 0; i < disps.size(); i ++) {
        ofPushMatrix();
        ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
        disps[i]->yr = float (ofGetFrameNum()) * 0.11;
        disps[i]->xr = float (ofGetFrameNum()) * 0.14;
        disps[i]->draw();
        ofPopMatrix();
    }
    shader.end();
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
void testApp::initShader() {
    
    string vert = STRINGIFY(
                            varying vec3 normal;
                            
                            void main(void)
                            {
                                normal = normalize(gl_NormalMatrix * gl_Normal).xyz;
                                gl_Position = ftransform();
                            }
                            );
    string frag = STRINGIFY(
                            
                            varying vec3 normal;
                            uniform vec3 lightDir;
                            uniform vec4 ambientColor;
                            uniform vec4 diffuseColor;
                            uniform vec4 specularColor;
                            
                            void main(void)
                            {
                                float diffuse = max(0.0, dot(normalize(normal), normalize(lightDir)));
                                vec4 flagColor = diffuse * diffuseColor;
                                flagColor += ambientColor;
                                vec3 vReflection = normalize(reflect(-normalize(lightDir), normalize(normal)));
                                float specular = pow(max(0.0, dot(normalize(normal), vReflection)), 128.0);
                                flagColor += specular * specularColor;
                                gl_FragColor = flagColor;
                            }
                            
                            );
    shader.setupShaderFromSource(GL_VERTEX_SHADER, vert);
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, frag);
    shader.linkProgram();
    
}