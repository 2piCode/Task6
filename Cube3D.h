//
// Created by coder on 31.10.22.
//

#ifndef UNTITLED3_CUBE3D_H
#define UNTITLED3_CUBE3D_H
#include "Box3D.h"

class Cube3D : public Box3D{
    Point3D _center;
    double _side;
    double _phi;
    double _theta;
public:
    Cube3D(Point3D center, double side, double theta, double phi);
    Cube3D(Point3D center, double side) : Cube3D(center, side, 0, 0) {}
    Box3D ConvertToBox(Point3D center, double side, double theta, double phi);
};


#endif //UNTITLED3_CUBE3D_H
