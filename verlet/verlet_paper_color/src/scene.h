
#pragma once

#include "ofMain.h"
#include "ofVboIcosphere.h"
#include "verletPoint3D.h"
#include "verletStick3D.h"
#include "verletSystem.h"

class Scene {
public:
    Scene(float _h);
    ~Scene();
    void update();
    void draw();
    
    void RGBtoHSV(float r, float g, float b, float &h, float &s, float &v);
    void HSVtoRGB(float h, float s, float v, float &r, float &g, float &b);
    
    
    VerletSystem system;
    ofVboIcosphere* sphere;
    ofImage bg;
    int life;
    int cx, cy;
    float ambientColor[4];
    float diffuseColor[4];
    float specularColor[4];
};
