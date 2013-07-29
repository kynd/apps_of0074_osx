
#include "particle.h"


Particle::Particle() {
    pos.x = ofRandom(-400,400);
    pos.y = ofRandom(-300,800);
    pos.z = ofRandom(-300,300);
    vel.x = ofRandom(-3,3);
    vel.y = ofRandom(-3,3);
    vel.z = ofRandom(-3,3);
}

//--------------------------------------------------------------

Particle::~Particle() {
    
}

//--------------------------------------------------------------

void Particle::update() {
    //gravitate to the center
    ofVec3f center = ofVec3f(0, 0, 0);
    if (ofGetFrameNum() < 750) {vel = vel + (center - pos) * 0.0001;} else {
        vel = vel - (center - pos) * 0.0001;
    };
    pos += vel;
}

//--------------------------------------------------------------

void Particle::draw() {
    
}
