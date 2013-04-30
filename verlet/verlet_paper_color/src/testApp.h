#pragma once

#include "ofMain.h"
#include "ofVboIcosphere.h"
#include "verletPoint3D.h"
#include "verletStick3D.h"
#include "verletSystem.h"
#include "videoSaver.h"
#include "scene.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void initShader();
    VerletSystem system;
    ofVboIcosphere* sphere;
    ofShader shaders[2];
    ofImage bg;
    VideoSaver v;
    vector<Scene*> scenes;
    int interval;
    int count;
    float hue;
};
