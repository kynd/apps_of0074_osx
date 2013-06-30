#include "poly_vertex.h"

PolyVertex::PolyVertex(float _x, float _y, float _z, float _s, float _t) {
    coord.x = _x;
	coord.y = _y;
	coord.z = _z;
	texCoord.x = _s;
    texCoord.y = _t;
    saveCoord();
}

void PolyVertex::saveCoord() {
	oCoord = coord;
}

void PolyVertex::loadCoord() {
	coord = oCoord;
}

void PolyVertex::addTriangle(PolyTriangle* t) {
	Boolean flag = false;
	for (int i = 0; i < triangles.size(); i++) {
		if (triangles[i] == t) {
			return;
		}
	}
	triangles.push_back(t);
}