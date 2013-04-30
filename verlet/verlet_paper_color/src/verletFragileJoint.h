#ifndef __verlet__verletFragileJoint__
#define __verlet__verletFragileJoint__

#include "ofMain.h"
#include "verletPoint3D.h"
#include "verletStick3D.h"

class VerletFragileJoint {
public:
    VerletFragileJoint( VerletStick3D*, VerletStick3D*, float th = 10.f );
    ~VerletFragileJoint();
	
    virtual void update();
	
	VerletStick3D* s1;
	VerletStick3D* s2;
	float threshold;
    bool bValid;
    bool bFlip;
};

#endif
