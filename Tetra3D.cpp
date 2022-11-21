//
// Created by coder on 14.11.22.
//

#include "Tetra3D.h"

Tetra3D::Tetra3D(Point3D a, Point3D b, Point3D c, Point3D d):
        _a(a), _b(b), _c(c), _d(d), Box3D(ConvertToBox(a, b, c, d)){}

Box3D Tetra3D::ConvertToBox(Point3D a, Point3D b, Point3D c, Point3D d) const {
    double firstX = std::min(std::min(a.GetX(), b.GetX()), std::min(c.GetX(), d.GetX()));
    double firstY = std::min(std::min(a.GetY(), b.GetY()), std::min(c.GetY(), d.GetY()));
    double firstZ = std::min(std::min(a.GetZ(), b.GetZ()), std::min(c.GetZ(), d.GetZ()));

    double secondX = std::max(std::max(a.GetX(), b.GetX()), std::max(c.GetX(), d.GetX()));
    double secondY = std::max(std::max(a.GetY(), b.GetY()), std::max(c.GetY(), d.GetY()));
    double secondZ = std::max(std::max(a.GetZ(), b.GetZ()), std::max(c.GetZ(), d.GetZ()));
    return Box3D(Point3D(firstX, firstY, firstZ), Point3D(secondX, secondY, secondZ));
}
