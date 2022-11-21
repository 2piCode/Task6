//
// Created by coder on 25.10.22.
//

#include "Sphere3D.h"

Sphere3D::Sphere3D(Point3D center, double radius) :
    _radius(radius), Box3D(ConvertToBox(center)) {
}

bool Sphere3D::HasIntersection(Sphere3D sphere) const {
    return GetCenter().GetDistance(sphere.GetCenter()) < GetRadius() + sphere.GetRadius();
}

Box3D Sphere3D::ConvertToBox(Point3D center) const {
    return Box3D(center, GetRadius() * 2, GetRadius() * 2, GetRadius() * 2);
}
