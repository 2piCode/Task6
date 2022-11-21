//
// Created by coder on 14.11.22.
//

#ifndef UNTITLED3_TETRA3D_H
#define UNTITLED3_TETRA3D_H
#include "Point3D.h"
#include "Box3D.h"
#include <iostream>
class Tetra3D : public Box3D {
    Point3D _a;
    Point3D _b;
    Point3D _c;
    Point3D _d;
public:
    Tetra3D(Point3D a, Point3D b, Point3D c, Point3D d);
    Box3D ConvertToBox(Point3D a, Point3D b, Point3D c, Point3D d) const;
};


#endif //UNTITLED3_TETRA3D_H
