

#ifndef __ICOSHERE__
#define __ICOSHERE__

#include "ofMain.h"
#include "poly_triangle.h"
#include "poly_vertex.h"
#include "polygonShape.h"
#include "shape.h"

class Icosphere : public Shape {
public:
    Icosphere(float = 50.f,int = 3);
    ~Icosphere();
    void draw();
	PolygonShape polygon;
protected:
	int addVertex(float, float, float);
	int getMiddlePoint(int i1, int i2);
	vector<PolyVertex*> vertices;
	vector<PolyTriangle*> triangles;
	float radius;
	int recursion;
	map<int, int> cache;
};


#endif