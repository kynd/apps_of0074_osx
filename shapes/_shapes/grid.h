
#ifndef __GRID__
#define __GRID__

#include "ofMain.h"
#include "poly_triangle.h"
#include "poly_vertex.h"
#include "polygonShape.h"
#include "shape.h"

class Grid : public Shape {
public:
    Grid(float width = 100, float height = 100, int wSlices = 5.f, int hSlices = 5);
    ~Grid();
    void draw();
	PolygonShape polygon;
    
};


#endif