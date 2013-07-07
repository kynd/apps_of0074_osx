
#include "rectMap.h"


RectMap::RectMap(float x, float y, float w, float h):
ofRectangle(x, y, w, h)
{
    color.r = ofRandom(0, 255);
    color.g = ofRandom(0, 255);
    color.b = ofRandom(0, 255);
    //color.r = color.g = color.b = 0;
    n = 0;
    phase = 0;
}
RectMap::~RectMap() {
    if (children.size() == 0) return;
    for (float i = children.size() - 1; i >= 0; i --) {
        delete(children[i]);
        children[i] = NULL;
    }
    children.clear();
}

void RectMap::draw() {
    ofPushStyle();
    color.a = 200;
    ofSetColor(color);
    ofRectangle r = ofRectangle(x + 1, y + 1, width - 2, height - 2);
    ofRect(r);
    ofPopStyle();
    
    ofPushMatrix();
    ofTranslate(x, y);
    for (float i = 0; i < children.size(); i ++) {
        children[i]->draw();
    }
    ofPopMatrix();
}

void RectMap::addChild(RectMap* r) {
    children.push_back(r);
}

void RectMap::addRandomChild(ofColor c) {
    if (width < 30 || height < 30) { return; };
    float _x, _y, _h, _w;
    int flag = false;
    int count = 0;
    while(!flag && count < 5) {
        _w = ofRandom(5, max(10.f, width / 3));
        _h = ofRandom(5, max(10.f, height / 3));
        _x = ofRandom(0, width - _w);
        _y = ofRandom(0, height - _h);
        RectMap* r = new RectMap(_x, _y, _w, _h);
        c.setHue(c.getHue() + ofRandom(-10, 10));
        c.setSaturation(c.getSaturation() + ofRandom(-10, 10));
        c.setBrightness(c.getBrightness() + ofRandom(-10, 10));
        r->color = c;
        flag = true;
        for (float j = 0; j < children.size(); j ++) {
            if (children[j]->intersects(*r)) {
                flag = false;
                count ++;
                delete r;
                break;
            }
        }
        if (flag) addChild(r);
    }
}

void RectMap::addRandomChildren(float n) {
    for (float i = 0; i < n; i ++) {
        addRandomChild(color);
    }
}

bool RectMap::expandChildren() {
    switch (phase) {
        case 0:
            addRandomChildren();
            if (children.size() != 0) {
                phase = 1;
            }
            return false;
            break;
        case 1:
            if (ofRandom(0,1) < 0.5) {
                expandTop(n);expandBottom(n);
                expandLeft(n);expandRight(n);
            } else {
                expandLeft(n);expandRight(n);
                expandTop(n);expandBottom(n);
            }
            n ++;
            if (n >= children.size()) {
                n = 0;
                phase = 2;
                return false;
            }
            break;
        default:
            if (!children[n]->expandChildren()) {
                n ++;
            }
            if (n >= children.size()) {
                n = 0;
                return false;
            }
    }
    return true;
}

void RectMap::expandTop(int i) {
    RectMap* r = children[i];
    r->height += r->y;
    r->y = 0;
    float _h = r->height;
    for (float j = 0; j < children.size(); j ++) {
        if (i != j && children[j]->intersects(*r)) {
            r->y = children[j]->getBottom();
            r->height = _h - r->y;
        }
    }
}

void RectMap::expandBottom(int i) {
    RectMap* r = children[i];
    r->height = height - r->y;
    for (float j = 0; j < children.size(); j ++) {
        if (i != j && children[j]->intersects(*r)) {
            r->height = children[j]->getTop() - r->y;
        }
    }
}

void RectMap::expandLeft(int i) {
    RectMap* r = children[i];
    r->width += r->x;
    r->x = 0;
    float _w = r->width;
    for (float j = 0; j < children.size(); j ++) {
        if (i != j && children[j]->intersects(*r)) {
            r->x = children[j]->getRight();
            r->width = _w - r->x;
        }
    }
}

void RectMap::expandRight(int i) {
    RectMap* r = children[i];
    r->width = width - r->x;
    for (float j = 0; j < children.size(); j ++) {
        if (i != j && children[j]->intersects(*r)) {
            r->width = children[j]->getLeft() - r->x;
        }
    }
}


ofColor color;
vector<RectMap*> children;