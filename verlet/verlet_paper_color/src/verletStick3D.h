#ifndef __VERLET_STICK_3D__
#define __VERLET_STICK_3D__

#include "ofMain.h"
#include "verletPoint3D.h"

class VerletStick3D {
public:
    VerletStick3D( VerletPoint3D*, VerletPoint3D*, float len = 0.f );
    ~VerletStick3D();
	
    virtual void update();
	virtual void draw();
	virtual bool isIdentical(VerletStick3D*);
	
	VerletPoint3D* p1;
	VerletPoint3D* p2;
	float _length;
};

#endif
