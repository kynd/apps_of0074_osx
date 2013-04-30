#include "verletTriangle.h"

VerletTriangle::VerletTriangle(VerletPoint3D* p0, VerletPoint3D* p1, VerletPoint3D* p2){
    points.push_back(p0);
    points.push_back(p1);
    points.push_back(p2);
}

VerletTriangle::~VerletTriangle() {
    points.clear();
}

ofVec3f VerletTriangle::getNormal() {
    ofVec3f v0 = ofVec3f(points[1]->x - points[0]->x, points[1]->y - points[0]->y, points[1]->z - points[0]->z);
    ofVec3f v1 = ofVec3f(points[2]->x - points[0]->x, points[2]->y - points[0]->y, points[2]->z - points[0]->z);
    ofVec3f cross = v0.cross(v1);
    cross.normalize();
    return cross;
}