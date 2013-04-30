
#include "verletFragileJoint.h"

VerletFragileJoint::VerletFragileJoint(VerletStick3D* _s1, VerletStick3D* _s2, float th) {
    s1 = _s1;
    s2 = _s2;
    bFlip = s1->p1 != s2->p1;
    bValid = true;
    threshold = th;
}

VerletFragileJoint::~VerletFragileJoint() {
    delete s1;
    delete s2;
}

void VerletFragileJoint::update() {
    if (bValid) {
        VerletPoint3D* p1 = s1->p1;
        VerletPoint3D* p2 = s1->p2;
        VerletPoint3D* p3 = (bFlip) ? s2->p2 : s2->p1;
        VerletPoint3D* p4 = (bFlip) ? s2->p1 : s2->p2;
        
        float dist1 = p1->distance(p3);
        float dist2 = p2->distance(p4);
        
        if (dist1 + dist2 < threshold) {
            p1->x = p3->x = (p1->x + p3->x) / 2;
            p1->y = p3->y = (p1->y + p3->y) / 2;
            p1->z = p3->z = (p1->z + p3->z) / 2;
            p2->x = p4->x = (p2->x + p4->x) / 2;
            p2->y = p4->y = (p2->y + p4->y) / 2;
            p2->z = p4->z = (p2->z + p4->z) / 2;
        } else {
            //cout << dist1 << " | " << dist2 << " | " << threshold << "\n";
            bValid = false;
        }
    }
}