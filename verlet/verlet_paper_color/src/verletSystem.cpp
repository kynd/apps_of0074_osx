#include "verletSystem.h"

VerletSystem::VerletSystem() {
    
}

VerletSystem::~VerletSystem() {
    for (int i = 0; i < points.size(); i ++) {
        delete points[i];
        points[i] = NULL;
    }
	for (int i = 0; i < sticks.size(); i ++) {
		delete sticks[i];
        sticks[i] = NULL;
	}
    for (int i = 0; i < fJoints.size(); i ++) {
		delete fJoints[i];
        fJoints[i] = NULL;
	}
    for (int i = 0; i < triangles.size(); i ++) {
		delete triangles[i];
        triangles[i] = NULL;
	}
    points.clear();
    sticks.clear();
    fJoints.clear();
}

void VerletSystem::update() {
    for (int i = 0; i < points.size(); i ++) {
        points[i]->update();
    }
	for (int i = 0; i < sticks.size(); i ++) {
		sticks[i]->update();
	}
    for (int i = 0; i < fJoints.size(); i ++) {
		fJoints[i]->update();
	}
    for (int i = 0; i < fJoints.size(); i ++) {
		fJoints[i]->update();
	}
}

void VerletSystem::draw(bool wireframe) {
    if (triangles.size() > 0) {
        mesh.clear();
        for (int i = 0; i < triangles.size(); i ++) {
            mesh.addVertex(ofVec3f(triangles[i]->points[0]->x, triangles[i]->points[0]->y, triangles[i]->points[0]->z));
            mesh.addVertex(ofVec3f(triangles[i]->points[1]->x, triangles[i]->points[1]->y, triangles[i]->points[1]->z));
            mesh.addVertex(ofVec3f(triangles[i]->points[2]->x, triangles[i]->points[2]->y, triangles[i]->points[2]->z));
            ofVec3f cross = triangles[i]->getNormal();
            
            mesh.addNormal(cross);
            mesh.addNormal(cross);
            mesh.addNormal(cross);
            
            mesh.addIndex(i * 3);
            mesh.addIndex(i * 3 + 1);
            mesh.addIndex(i * 3 + 2);
            
            mesh.draw();
        }
    } else {
        for (int i = 0; i < sticks.size(); i ++) {
            sticks[i]->draw();
        }
    }
}

void VerletSystem::addPoint(VerletPoint3D* p) {
    points.push_back(p);
}

void VerletSystem::addStick(VerletStick3D* s) {
    sticks.push_back(s);
}


void VerletSystem::addTriangle(VerletTriangle* t) {
    triangles.push_back(t);
}

void VerletSystem::addFragileJoint(VerletFragileJoint* j) {
    fJoints.push_back(j);
}