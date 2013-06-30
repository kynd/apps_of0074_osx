#ifndef __POLYGON_SHAPE__
#define __POLYGON_SHAPE__

#include "ofMain.h"
#include "Poly_triangle.h"
#include "poly_vertex.h"
#include "shape.h"

class PolygonShape : public Shape {
public:
    PolygonShape();
    ~PolygonShape();
	
	void addVertex(PolyVertex*);
	void addTriangle(PolyTriangle*);
    bool init();
    virtual void draw();
	
	vector<PolyTriangle*> triangles;
	vector<PolyVertex*> vertices;
    
    ofVboMesh mesh;
};


#endif