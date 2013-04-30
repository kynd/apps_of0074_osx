#include "testApp.h"

#define STRINGIFY(A) #A
//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetFrameRate(30);
    initShader();
    glEnable(GL_DEPTH_TEST);
    bg.loadImage("bg.png");
    //scenes.push_back(new Scene());
    interval = 90;
    count = 0;
    
    hue = ofRandom(0, 360);
    scenes.push_back(new Scene(hue));
    hue += ofRandom(30,60);
    scenes.push_back(new Scene(hue));
    scenes[0]->life += interval;
}

//--------------------------------------------------------------
void testApp::update(){
    count ++;
    if (count > interval) {
        if (interval > 20) {
            
            count = 0;
            hue += ofRandom(30,60);
            if (hue > 360) {
                hue -= 360;
            }
            scenes.push_back(new Scene(hue));
            interval -= 3;
        } else {
            if (count > 200) {
                std::exit(1);
            }
        }
        
        
    }
    for (int i = 0; i < scenes.size(); i ++) {
        if (scenes[i]->life > interval) {
            scenes[i]->update();
        } else {
            scenes[i]->life ++;
        }
    }
    
    
    int idx = -1;
    
    
    for (int i = 0; i < scenes.size(); i ++) {
        if (scenes[i]->life > 400) {
            idx = i;
        }
    }
    
    if (idx >= 0) {
        vector<Scene*>::iterator it = scenes.begin();
        it += idx;
        it = scenes.erase(it);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    float lightAngle = ofGetElapsedTimef();
    //float lightDir[3] = {cos(lightAngle), 0.3, sin(lightAngle)};
    float lightDir[3] = {0.3, 0.3, -0.8};
    
    ofPushMatrix();
    shaders[0].begin();
    shaders[0].setUniform3fv("lightDir", lightDir);
    
    for (int i = 0; i < scenes.size(); i ++) {
        shaders[0].setUniform4fv("ambientColor", scenes[i]->ambientColor);
        shaders[0].setUniform4fv("diffuseColor", scenes[i]->diffuseColor);
        shaders[0].setUniform4fv("specularColor", scenes[i]->specularColor);
        scenes[i]->draw();
    }
    
    shaders[0].end();
    ofPopMatrix();
    
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    bg.draw(0, 0);
    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
    
    
    v.save();
    
    
	if (ofGetFrameNum() > 3000) {
        std::exit(1);
	}
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
                                float diffuse2 = max(0.0, dot(-normalize(normal), normalize(lightDir)));
                                vec4 flagColor = diffuse * diffuseColor + diffuse2 * diffuseColor;
                                flagColor += ambientColor;
                                vec3 vReflection = normalize(reflect(-normalize(lightDir), normalize(normal)));
                                float specular = pow(max(0.0, dot(normalize(normal), vReflection)), 128.0);
                                flagColor += specular * specularColor;
                                //flagColor = vec4(1.0);
                                gl_FragColor = flagColor;
                            }
                            
                            );
    shaders[0].setupShaderFromSource(GL_VERTEX_SHADER, vert);
    shaders[0].setupShaderFromSource(GL_FRAGMENT_SHADER, frag);
    shaders[0].linkProgram();
    
    vert = STRINGIFY(
                     varying vec4 color;
                     
                     uniform vec3 lightDir;
                     uniform vec4 ambientColor;
                     uniform vec4 diffuseColor;
                     uniform vec4 specularColor;
                     
                     void main(void)
                     {
                         vec3 normal = normalize(gl_NormalMatrix * gl_Normal).xyz;
                         float diffuse = max(0.0, dot(normalize(normal), normalize(lightDir)));
                         vec4 vertColor = diffuse * diffuseColor;
                         vertColor += ambientColor;
                         vec3 vReflection = normalize(reflect(-normalize(lightDir), normalize(normal)));
                         //float specular = pow(max(0.0, dot(normalize(normal), vReflection)), 128.0);
                         vertColor += specular * specularColor;
                         color = vertColor;
                         gl_Position = ftransform();
                     }
                     );
    frag = STRINGIFY(
                     varying vec4 color;
                     
                     void main(void)
                     {
                         gl_FragColor = color;
                     }
                     
                     );
    shaders[1].setupShaderFromSource(GL_VERTEX_SHADER, vert);
    shaders[1].setupShaderFromSource(GL_FRAGMENT_SHADER, frag);
    shaders[1].linkProgram();
}

