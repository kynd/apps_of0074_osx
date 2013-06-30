#include "polygonShape.h"

PolygonShape::PolygonShape() {
}
PolygonShape::~PolygonShape() {
}
	
void PolygonShape::draw() {
    mesh.draw();
}

void PolygonShape::addVertex(PolyVertex* v) {
	vertices.push_back(v);
}
void PolygonShape::addTriangle(PolyTriangle* t) {
	triangles.push_back(t);
	vertices[t->indices[0]]->addTriangle(t);
	vertices[t->indices[1]]->addTriangle(t);
	vertices[t->indices[2]]->addTriangle(t);
}

bool PolygonShape::init() {
    mesh.clear();
    
    for (int i = 0; i < vertices.size(); i ++) {
		mesh.addVertex(vertices[i]->coord);
        mesh.addTexCoord(vertices[i]->texCoord);
	}
    
	
	for (int i = 0; i < vertices.size(); i ++) {
        ofVec3f sum = ofVec3f(0,0,0);
		for (int j = 0; j < vertices[i]->triangles.size(); j ++) {
			PolyTriangle* t = vertices[i]->triangles[j];
            ofVec3f v0 = (vertices[t->indices[0]]->coord - vertices[t->indices[1]]->coord);
            ofVec3f v1 = (vertices[t->indices[2]]->coord - vertices[t->indices[0]]->coord);
            sum += v0.cross(v1).normalize();
		}
        sum.normalize();
		mesh.addNormal(sum);
	}
	
	for (int i = 0; i < triangles.size(); i ++) {
		mesh.addIndex(triangles[i]->indices[0]);
        mesh.addIndex(triangles[i]->indices[1]);
        mesh.addIndex(triangles[i]->indices[2]);
	}
}
