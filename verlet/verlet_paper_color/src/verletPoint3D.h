#ifndef __VERLET_POINT_3D__
#define __VERLET_POINT_3D__

#include "ofMain.h"

class VerletPoint3D {
public:
    VerletPoint3D( float, float, float );
    ~VerletPoint3D();
	
    virtual void update();
	virtual void render();
	virtual void constrain( float, float, float, float, float, float );
	void setVx( float );
	void setVy( float );
	void setVz( float );
	float getVx();
	float getVy();
	float getVz();
	float distance(VerletPoint3D*);
	void setPos( float, float, float );
	float x, y, z;
	
private:
	float ox, oy, oz;
};


#endif