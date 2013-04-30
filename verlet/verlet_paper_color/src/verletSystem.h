#ifndef __verlet__VerletSystem__
#define __verlet__VerletSystem__


#include "ofMain.h"
#include "verletPoint3D.h"
#include "verletStick3D.h"
#include "verletTriangle.h"
#include "verletFragileJoint.h"

class VerletSystem {
public:
    VerletSystem();
    ~VerletSystem();
	void update();
    void draw(bool wireframe = false);
    void addPoint(VerletPoint3D* p);
    void addStick(VerletStick3D* s);
    void addTriangle(VerletTriangle* t);
    void addFragileJoint(VerletFragileJoint* j);
	vector<VerletPoint3D*> points;
	vector<VerletStick3D*> sticks;
	vector<VerletTriangle*> triangles;
	vector<VerletFragileJoint*> fJoints;
    ofVboMesh mesh;
};

#endif