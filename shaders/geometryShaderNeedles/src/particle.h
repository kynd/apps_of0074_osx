#ifndef __geometryShader__particle__
#define __geometryShader__particle__

#include "ofMain.h"

class Particle {
	
public:
    Particle();
    ~Particle();
    void update();
    void draw();
    ofVec3f pos, vel, acc;
};

#endif /* defined(__geometryShader__particle__) */
