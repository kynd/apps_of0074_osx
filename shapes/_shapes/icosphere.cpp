#include "icosphere.h"


Icosphere::Icosphere(float rad, int rec):
radius(rad),
recursion(rec)
{
	float t = (1.0 + sqrt(5.0)) / 2.0;
	addVertex(-1,  t,  0);
	addVertex( 1,  t,  0);
	addVertex(-1, -t,  0);
	addVertex( 1, -t,  0);
	
	addVertex( 0, -1,  t);
	addVertex( 0,  1,  t);
	addVertex( 0, -1, -t);
	addVertex( 0,  1, -t);
	
	addVertex( t,  0, -1);
	addVertex( t,  0,  1);
	addVertex(-t,  0, -1);
	addVertex(-t,  0,  1);

	
	triangles.push_back(new PolyTriangle(0, 5, 11));
	triangles.push_back(new PolyTriangle(0, 1, 5));
	triangles.push_back(new PolyTriangle(0, 7, 1));
	triangles.push_back(new PolyTriangle(0, 10, 7));
	triangles.push_back(new PolyTriangle(0, 11, 10));
	
	triangles.push_back(new PolyTriangle(1, 9, 5));
	triangles.push_back(new PolyTriangle(5, 4, 11));
	triangles.push_back(new PolyTriangle(11, 2, 10));
	triangles.push_back(new PolyTriangle(10, 6, 7));
	triangles.push_back(new PolyTriangle(7, 8, 1));
	
	triangles.push_back(new PolyTriangle(3, 4, 9));
	triangles.push_back(new PolyTriangle(3, 2, 4));
	triangles.push_back(new PolyTriangle(3, 6, 2));
	triangles.push_back(new PolyTriangle(3, 8, 6));
	triangles.push_back(new PolyTriangle(3, 9, 8));
	
	triangles.push_back(new PolyTriangle(4, 5, 9));
	triangles.push_back(new PolyTriangle(2, 11, 4));
	triangles.push_back(new PolyTriangle(6, 10, 2));
	triangles.push_back(new PolyTriangle(8, 7, 6));
	triangles.push_back(new PolyTriangle(9, 1, 8));

	for (int i = 0; i < recursion; i++) {
		vector<PolyTriangle*> triangles2;
		for (int j = 0; j < triangles.size();j ++) {
			int a = getMiddlePoint(triangles[j]->indices[0],triangles[j]->indices[1]);
			int b = getMiddlePoint(triangles[j]->indices[1],triangles[j]->indices[2]);
			int c = getMiddlePoint(triangles[j]->indices[2],triangles[j]->indices[0]);
			
			triangles2.push_back(new PolyTriangle(triangles[j]->indices[0], a, c));
			triangles2.push_back(new PolyTriangle(triangles[j]->indices[1], b, a));
			triangles2.push_back(new PolyTriangle(triangles[j]->indices[2], c, b));
			triangles2.push_back(new PolyTriangle(a, b, c));
		}
        triangles.clear();
		triangles = triangles2;
	}
	
	PolyTriangle* b = triangles[0];

	
	for (int i = 0; i < vertices.size(); i ++) {
		polygon.addVertex(vertices[i]);
	}
	
	for (int i = 0; i < triangles.size(); i ++) {
		polygon.addTriangle(triangles[i]);
	}
	
	polygon.init();
}

int Icosphere::getMiddlePoint(int i1, int i2) {
	
	Boolean IsFirstSmaller = i1<i2;
	int smallerIndex = IsFirstSmaller ? i1:i2;
	int greaterIndex = IsFirstSmaller ? i2:i1;
	int key = (smallerIndex << 16) + greaterIndex;
	
	if (cache[key]) {
		return cache[key] - 1;
	}
	
	PolyVertex* v1 = vertices[i1];
	PolyVertex* v2 = vertices[i2];
	
	int index = addVertex((v1->coord.x + v2->coord.x) / 2, (v1->coord.y + v2->coord.y) / 2, (v1->coord.z + v2->coord.z) / 2);
    
	cache[key] = index + 1;
	
	return index;
}

int Icosphere::addVertex(float _x, float _y, float _z) {
	int d = vertices.size();
	PolyVertex* v = new PolyVertex(_x,_y,_z);
	v->coord.normalize();
	v->coord *= radius;
	vertices.push_back(v);
	return vertices.size() - 1;
}

Icosphere::~Icosphere() {
}

void Icosphere::draw() {
	polygon.draw();
}
