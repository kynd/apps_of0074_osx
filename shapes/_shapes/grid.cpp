

#include "Grid.h"

Grid::Grid(float width, float height, int wSlices, int hSlices) {
    for (int j = 0; j <= hSlices; j ++) {
        for (int i = 0; i <= wSlices; i ++) {
            float x = - width / 2 + width / wSlices * i;
            float y = - height / 2 + height / hSlices * j;
            polygon.addVertex(new PolyVertex(x, y, 0, 1.f / wSlices * i, 1.f / hSlices *j));
            if (i > 0 && j > 0) {
                int v0 = (j - 1) * (wSlices + 1) + i - 1;
                int v1 = (j - 1) * (wSlices + 1) + i;
                int v2 = (j) * (wSlices + 1) + i - 1;
                int v3 = (j) * (wSlices + 1) + i;
                polygon.addTriangle(new PolyTriangle(v0, v2, v1));
                polygon.addTriangle(new PolyTriangle(v1, v2, v3));
            }
            int v3 = (j) * wSlices + i;
        }
    }
	polygon.init();
}

Grid::~Grid() {
}

void Grid::draw() {
    polygon.draw();
}