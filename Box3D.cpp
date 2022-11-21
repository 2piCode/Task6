//
// Created by coder on 25.10.22.
//

#include <valarray>
#include "Box3D.h"

Box3D::Box3D(Point3D center, double length, double height, double width): _center(center) {
    _length = length;
    _height = height;
    _width = width;
}

Box3D::Box3D(Point3D a, Point3D b) : Box3D(
        (a + b) / 2,
        abs(b.GetX() - a.GetX()),
        abs(b.GetY() - a.GetY()),
        abs(b.GetZ() - a.GetZ())) {}

bool Box3D::HasIntersection(const Box3D& other) const
{
    double LeftX = _center.GetX() - _width / 2;
    double RightX = _center.GetX() + _width / 2;
    double LeftY = _center.GetY() - _height / 2;
    double RightY = _center.GetY() + _height / 2;
    double LeftZ = _center.GetZ() - _length / 2;
    double RightZ = _center.GetZ() + _length / 2;

    double otherLeftX = other.GetCenter().GetX() - other.GetWidth() / 2;
    double otherRightX = other.GetCenter().GetX() + other.GetWidth() / 2;
    double otherLeftY = other.GetCenter().GetY() - other.GetHeight() / 2;
    double otherRightY = other.GetCenter().GetY() + other.GetHeight() / 2;
    double otherLeftZ = other.GetCenter().GetZ() - other.GetLength() / 2;
    double otherRightZ = other.GetCenter().GetZ() + other.GetLength() / 2;

    return (LeftX <= otherRightX && RightX >= otherLeftX) &&
           (LeftY <= otherRightY && RightY >= otherLeftY) &&
           (LeftZ <= otherRightZ && RightZ >= otherLeftZ);
}
