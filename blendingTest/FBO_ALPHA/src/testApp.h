#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void drawBoxes();
    void applyShader(ofShader& shader, ofFbo& fbo);
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void initShaders();
    
    ofShader shaders[1];
    ofFbo fbos[2];
};
