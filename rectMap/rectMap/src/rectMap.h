
#ifndef __emptyExample__rectMap__
#define __emptyExample__rectMap__


#include "ofMain.h"
class RectMap: public ofRectangle {
    
public:
    RectMap(float x = 0, float y = 0, float w = 0, float h = 0);
    ~RectMap();
    void draw();
    void addChild(RectMap* r);
    void addRandomChild(ofColor c);
    void addRandomChildren(float n = 5);
    bool expandChildren();
    void expandTop(int i);
    void expandBottom(int i);
    void expandLeft(int i);
    void expandRight(int i);
    ofColor color;
    vector<RectMap*> children;
    float n;
    int phase;
};


#endif /* defined(__emptyExample__rectMap__) */
