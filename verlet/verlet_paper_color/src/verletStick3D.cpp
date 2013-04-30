
#include "verletStick3D.h"

VerletStick3D::VerletStick3D( VerletPoint3D* _p1, VerletPoint3D* _p2, float len ) {
	p1 = _p1;
	p2 = _p2;
	if (len == 0.f) {
		float dx = p2->x - p1->x;
		float dy = p2->y - p1->y;
		float dz = p2->z - p1->z;
		float d = sqrt(dx * dx + dy * dy + dz * dz);
		_length = d;
	} else {
		_length = len;
	}
	_length;
}

VerletStick3D::~VerletStick3D() {
    delete p1;
    delete p2;
}
	
void VerletStick3D::update() {
	float dx = p2->x - p1->x;
	float dy = p2->y - p1->y;
	float dz = p2->z - p1->z;
	float d = sqrt(dx * dx + dy * dy + dz * dz);
    if (d == 0) {
        return;
    }
    
	float diff = _length - d;
	float offsetX = (diff * dx / d) / 2;
	float offsetY = (diff * dy / d) / 2;
	float offsetZ = (diff * dz / d) / 2;
	p1->x -= offsetX;
	p1->y -= offsetY;
	p1->z -= offsetZ;
	p2->x += offsetX;
	p2->y += offsetY;
	p2->z += offsetZ;
}

void VerletStick3D::draw() {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glEnable(GL_LINE_SMOOTH);	
	glColor3f(1.f, 1.f, 1.f);
	glLineWidth(3.f);
	glBegin(GL_LINES);
	glVertex3f(p1->x, p1->y, p1->z);
	glVertex3f(p2->x, p2->y, p2->z);
	glEnd();
	glPopAttrib();
}

bool VerletStick3D::isIdentical(VerletStick3D* s) {
    return (p1->distance(s->p1) == 0 && p2->distance(s->p2) == 0) || (p2->distance(s->p1) == 0 && p1->distance(s->p2) == 0);
}

