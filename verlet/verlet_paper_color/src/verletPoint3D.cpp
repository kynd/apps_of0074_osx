#include "verletPoint3D.h"
#include <algorithm>

VerletPoint3D::VerletPoint3D( float _x, float _y, float _z ){
	setPos(_x, _y, _z);
}

VerletPoint3D::~VerletPoint3D() {

};
	
void VerletPoint3D::update() {
	float tx = x;
	float ty = y;
	float tz = z;
	x += getVx();
	y += getVy();
	z += getVz();
	ox = tx;
	oy = ty;
	oz = tz;
}

void VerletPoint3D::render() {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glEnable(GL_LINE_SMOOTH);	
	glColor3f(1.f, 1.f, 1.f);
	glPointSize(6.0);
	glBegin(GL_POINTS);	
	glVertex3f(x, y, z);
	glEnd();
	glPopAttrib();
}

void VerletPoint3D::constrain( float xmin, float ymin, float zmin, float xmax, float ymax, float zmax ) {
	x = max(xmin, min(xmax, x));
	y = max(ymin, min(ymax, y));
	z = max(zmin, min(zmax, z));
}

void VerletPoint3D::setVx( float n ) {
	ox = x - n;
}
void VerletPoint3D::setVy( float n ) {
	oy = y - n;
}
void VerletPoint3D::setVz( float n ) {
	oz = z - n;
}

float VerletPoint3D::getVx() {
	return x - ox;
}
float VerletPoint3D::getVy() {
	return y - oy;
}
float VerletPoint3D::getVz() {
	return z - oz;
}

void VerletPoint3D::setPos( float _x, float _y, float _z ) {
	ox = x = _x;
	oy = y = _y;
	oz = z = _z;
}

float VerletPoint3D::distance(VerletPoint3D* p) {
    float dx = x - p->x;
    float dy = y - p->y;
    float dz = z - p->z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}
