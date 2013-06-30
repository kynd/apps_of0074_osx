#ifndef _DISPLAYOBJECT_
#define _DISPLAYOBJECT_


#include "ofMain.h"
#include "shape.h"

class DisplayObject {
public:
    DisplayObject( Shape*, GLfloat _x = 0.f, GLfloat _y = 0.f, GLfloat _z = 0.f, GLfloat _xr = 0.f, GLfloat _yr = 0.f, GLfloat _zr = 0.f );
    ~DisplayObject();
	void update();
    virtual void draw();
	GLfloat x, y, z, vx, vy, vz, xr, yr, zr;
	string extra;
	Shape* shape;
};


#endif
