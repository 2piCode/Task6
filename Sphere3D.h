//
// Created by coder on 25.10.22.
//

#ifndef UNTITLED3_SPHERE3D_H
#define UNTITLED3_SPHERE3D_H
#include "Box3D.h"

class Sphere3D : public Box3D {
    double _radius;
public:
    Sphere3D(Point3D center, double radius);

    bool HasIntersection(Sphere3D sphere) const;
    double GetRadius() const { return _radius; }
    Box3D ConvertToBox(Point3D center) const;
};


#endif //UNTITLED3_SPHERE3D_H
