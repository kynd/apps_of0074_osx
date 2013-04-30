#ifndef __verlet__VerletTriangle__
#define __verlet__VerletTriangle__


#include "ofMain.h"
#include "verletPoint3D.h"

class VerletTriangle {
public:
    VerletTriangle(VerletPoint3D* p0, VerletPoint3D* p1, VerletPoint3D* p2);
    ~VerletTriangle();
    ofVec3f getNormal();
    vector<VerletPoint3D*> points;
};

#endif