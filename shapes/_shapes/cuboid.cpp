
#include "cuboid.h"


Cuboid::Cuboid(float w, float h, float d) {
    polygon.addVertex(new PolyVertex(-w / 2, -h / 2, d / 2));
    polygon.addVertex(new PolyVertex(w / 2, -h / 2, d / 2));
    polygon.addVertex(new PolyVertex(-w / 2, h / 2, d / 2));
    polygon.addVertex(new PolyVertex(w / 2, h / 2, d / 2));
    polygon.addTriangle(new PolyTriangle(0, 3, 1));
    polygon.addTriangle(new PolyTriangle(0, 2, 3));
    
    
    polygon.addVertex(new PolyVertex(-w / 2, h / 2, d / 2));
    polygon.addVertex(new PolyVertex(w / 2, h / 2, d / 2));
    polygon.addVertex(new PolyVertex(-w / 2, h / 2, -d / 2));
    polygon.addVertex(new PolyVertex(w / 2, h / 2, -d / 2));
    polygon.addTriangle(new PolyTriangle(4, 7, 5));
    polygon.addTriangle(new PolyTriangle(4, 6, 7));
    
    
    polygon.addVertex(new PolyVertex(-w / 2, h / 2, -d / 2));
    polygon.addVertex(new PolyVertex(w / 2, h / 2, -d / 2));
    polygon.addVertex(new PolyVertex(-w / 2, -h / 2, -d / 2));
    polygon.addVertex(new PolyVertex(w / 2, -h / 2, -d / 2));
    polygon.addTriangle(new PolyTriangle(8, 11, 9));
    polygon.addTriangle(new PolyTriangle(8, 10, 11));
    
    
    polygon.addVertex(new PolyVertex(-w / 2, -h / 2, -d / 2));
    polygon.addVertex(new PolyVertex(w / 2, -h / 2, -d / 2));
    polygon.addVertex(new PolyVertex(-w / 2, -h / 2, d / 2));
    polygon.addVertex(new PolyVertex(w / 2, -h / 2, d / 2));
    polygon.addTriangle(new PolyTriangle(12, 15, 13));
    polygon.addTriangle(new PolyTriangle(12, 14, 15));
    
    
    polygon.addVertex(new PolyVertex(-w / 2, -h / 2, -d / 2));
    polygon.addVertex(new PolyVertex(-w / 2, -h / 2, d / 2));
    polygon.addVertex(new PolyVertex(-w / 2, h / 2, -d / 2));
    polygon.addVertex(new PolyVertex(-w / 2, h / 2, d / 2));
    polygon.addTriangle(new PolyTriangle(16, 19, 17));
    polygon.addTriangle(new PolyTriangle(16, 18, 19));
    
    polygon.addVertex(new PolyVertex(w / 2, -h / 2, d / 2));
    polygon.addVertex(new PolyVertex(w / 2, -h / 2, -d / 2));
    polygon.addVertex(new PolyVertex(w / 2, h / 2, d / 2));
    polygon.addVertex(new PolyVertex(w / 2, h / 2, -d / 2));
    polygon.addTriangle(new PolyTriangle(20, 23, 21));
    polygon.addTriangle(new PolyTriangle(20, 22, 23));
    
    polygon.init();
}

Cuboid::~Cuboid() {
    
}

void Cuboid::draw() {
    polygon.draw();
}
