
#include "scene.h"

Scene::Scene(float _h) {
    life = 0;
    
    int size = 25;
    int mx = ofGetWidth() / size;
    int my = ofGetHeight() / size;
    int cx = ofRandom(ofGetWidth() / 1.5, ofGetWidth() - ofGetWidth() / 1.5);
    int cy = ofRandom(ofGetHeight() / 1.5, ofGetHeight() - ofGetHeight() / 1.5);
    
    for (int j = 0; j < my; j ++) {
        for (int i = 0; i < mx; i ++) {
            float x1 = (float) ofGetWidth() / mx * i * 1.2 - ofGetWidth() * 0.1;
            float x2 = (float) ofGetWidth() / mx * (i + 1) * 1.2 - ofGetWidth() * 0.1;
            float y1 = (float) ofGetHeight() / my * j * 1.2 - ofGetHeight() * 0.1;
            float y2 = (float) ofGetHeight() / my * (j + 1) * 1.2 - ofGetHeight() * 0.1;
            
            abs(-1);
            x1 = pow(abs((x1 - ofGetWidth() / 2) / (ofGetWidth() / 2)), 1.3f) * ((x1 < ofGetWidth() / 2) ? -1 : 1)
                * ofGetWidth() / 2 + ofGetWidth() / 2;
            x2 = pow(abs((x2 - ofGetWidth() / 2) / (ofGetWidth() / 2)), 1.3f) * ((x2 < ofGetWidth() / 2) ? -1 : 1)
                * ofGetWidth() / 2 + ofGetWidth() / 2;
            y1 = pow(abs((y1 - ofGetHeight() / 2) / (ofGetHeight() / 2)), 1.3f) * ((y1 < ofGetHeight() / 2) ? -1 : 1)
                * ofGetHeight() / 2 + ofGetHeight() / 2;
            y2 = pow(abs((y2 - ofGetHeight() / 2) / (ofGetHeight() / 2)), 1.3f) * ((y2 < ofGetHeight() / 2) ? -1 : 1)
                * ofGetHeight() / 2 + ofGetHeight() / 2;
            
            VerletPoint3D* vp1 = new VerletPoint3D(x1, y1, 0);
            VerletPoint3D* vp2 = new VerletPoint3D(x2, y1, 0);
            VerletPoint3D* vp3 = new VerletPoint3D(x1, y2, 0);
            VerletPoint3D* vp4 = new VerletPoint3D(x2, y2, 0);
            system.addPoint(vp1);
            system.addPoint(vp2);
            system.addPoint(vp3);
            system.addPoint(vp4);
            
            system.addStick(new VerletStick3D(vp1, vp2));
            system.addStick(new VerletStick3D(vp2, vp4));
            system.addStick(new VerletStick3D(vp4, vp3));
            system.addStick(new VerletStick3D(vp3, vp1));
            
            system.addTriangle(new VerletTriangle(vp1, vp2, vp3));
            system.addTriangle(new VerletTriangle(vp2, vp4, vp3));
        }
    }
    
    for (int i = 0; i < system.sticks.size(); i ++) {
        for (int j = i; j < system.sticks.size(); j ++) {
            if (system.sticks[i]->isIdentical(system.sticks[j])) {
                system.addFragileJoint(new VerletFragileJoint(system.sticks[i], system.sticks[j]));
                system.fJoints[system.fJoints.size() - 1]->threshold = ofRandom(3,14);
            }
        }
    }
    
    float h = _h;//ofRandom(0, 360);
    float s = ofRandom(0.8, 1.0);
    float v = ofRandom(0.7, 0.9);
    float r, g, b;
    HSVtoRGB(h, s, v, r, g, b);
    r /= 256;
    g /= 256;
    b /= 256;
    cout << r << "|" << g << "|" << b << "\n";
    
    ambientColor[0] = r * 0.4;
    ambientColor[1] = g * 0.4;
    ambientColor[2] = b * 0.4;
    ambientColor[3] = 1.0;
    diffuseColor[0] = r * 0.6;
    diffuseColor[1] = g * 0.6;
    diffuseColor[2] = b * 0.6;
    diffuseColor[3] = 1.0;
    specularColor[0] = r;
    specularColor[1] = g;
    specularColor[2] = b;
    specularColor[3] = 1.0;
}


Scene::~Scene() {
}


void Scene::update() {
    life ++;
    for (int i = 0; i < system.points.size(); i ++) {
        float dx = system.points[i]->x - ofGetWidth() / 2;
        float dy = system.points[i]->y - ofGetHeight() / 2;
        float dz = system.points[i]->z + 200 - life;
        float dist = sqrt(dx * dx + dy * dy + dz * dz);
        
        if (dist != 0) {
            system.points[i]->x += dx / (dist * dist) * 15;
            system.points[i]->y += dy / (dist * dist) * 15;
            system.points[i]->z += dz / (dist * dist) * 15;
        }
    }
    system.update();
    
}

void Scene::draw() {
    system.draw();
}


//--------------------------------------------------------------
void Scene::RGBtoHSV(float r, float g, float b, float &h, float &s, float &v){
    r = max(0.f, min(1.f, r / 255));
    g = max(0.f, min(1.f, g / 255));
    b = max(0.f, min(1.f, b / 255));
    
    float mx, mn;
    mx = max(r, max(g, b));
    mn = min(r, min(g, b));
    
    if (mx == r) {
        h = 60.0 * (g - b) / (mx - mn);
    } else if (mx == g) {
        h = 60.0 * (b - r) / (mx - mn) + 120.0;
    } else {
        h = 60.0 * (r - g) / (mx - mn) + 240.0;
    }
    
    
    s = (mx - mn) / mx;
    v = mx;
}



//--------------------------------------------------------------
void Scene::HSVtoRGB(float h, float s, float v, float &r, float &g, float &b){
    int hi = int(h / 60.0);
    float f = h / 60.0 - float(hi);
    float p = v * (1.0 - s);
    float q = v * (1.0 - f * s);
    float t = v * (1.0 - (1.0 - f) * s);
    if (hi == 0) {
        r = v; g = t; b = p;
    } else if (hi == 1) {
        r = q; g = v; b = p;
    } else if (hi == 2) {
        r = p; g = v ; b = t;
    } else if (hi == 3) {
        r = p; g = q; b = v;
    } else if (hi == 4) {
        r = t; g = p; b = v;
    } else {
        r = v; g = p; b = q;
    }
    r *= 255;
    g *= 255;
    b *= 255;
}

