//
// Created by coder on 25.10.22.
//
#include "Point3D.h"
#ifndef UNTITLED3_BOX3D_H
#define UNTITLED3_BOX3D_H


class Box3D {
    Point3D _center;
    double _length;
    double _height;
    double _width;
public:
    Box3D(Point3D center, double length, double height, double width);
    Box3D(Point3D a, Point3D b);

    bool HasIntersection(const Box3D& other) const;
    Point3D GetCenter() const { return _center; }
    double GetWidth() const { return _width; }
    double GetHeight() const { return _height; }
    double GetLength() const { return _length; }

    virtual Box3D ConvertToBox() const { return *this; }
};


#endif //UNTITLED3_BOX3D_H