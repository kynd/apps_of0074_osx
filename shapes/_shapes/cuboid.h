#ifndef __CUBOID__
#define __CUBOID__

#include "ofMain.h"
#include "poly_triangle.h"
#include "poly_vertex.h"
#include "polygonShape.h"
#include "shape.h"

class Cuboid : public Shape {
public:
    Cuboid(float w = 100, float h = 100, float d = 100);
    ~Cuboid();
    void draw();
	PolygonShape polygon;
    
};


#endif