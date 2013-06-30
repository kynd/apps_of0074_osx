#ifndef __POLY_VERTEX__
#define __POLY_VERTEX__

#include "ofMain.h"
#include "poly_triangle.h"

class PolyVertex {
public:
    PolyVertex(float x, float y, float z, float s = 0.0, float t = 0.0);
	void addTriangle(PolyTriangle*);
	void loadCoord();
	void saveCoord();
    ofVec3f coord;
    ofVec3f oCoord;
    ofVec2f texCoord;
    
	vector<PolyTriangle*> triangles;
};


#endif