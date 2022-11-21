//
// Created by coder on 31.10.22.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "Cube3D.h"


Cube3D::Cube3D(Point3D center, double side, double theta, double phi)
    : _center(center), _side(side), _theta(theta), _phi(phi),
        Box3D(ConvertToBox(center, side, theta, phi)) {}

Box3D Cube3D::ConvertToBox(Point3D center, double side, double theta, double phi) {
    std::vector<Point3D> points;
    points.push_back(center + Point3D(side / 2, side / 2, side / 2));
    points.push_back(center + Point3D(side / 2, side / 2, -side / 2));
    points.push_back(center + Point3D(side / 2, -side / 2, side / 2));
    points.push_back(center + Point3D(side / 2, -side / 2, -side / 2));
    points.push_back(center + Point3D(-side / 2, side / 2, side / 2));
    points.push_back(center + Point3D(-side / 2, side / 2, -side / 2));
    points.push_back(center + Point3D(-side / 2, -side / 2, side / 2));
    points.push_back(center + Point3D(-side / 2, -side / 2, -side / 2));
    for (int i = 0; i < sizeof(points); i++)
    {
        points[i] = points[i].Rotate(theta, phi);
    }

    auto minmaxX = std::minmax_element(points.begin(), points.end(), [](Point3D a, Point3D b)
    {
        return a.GetX() < b.GetX();
    });
    auto minmaxY = std::minmax_element(points.begin(), points.end(), [](Point3D a, Point3D b)
    {
        return a.GetY() < b.GetY();
    });
    auto minmaxZ = std::minmax_element(points.begin(), points.end(), [](Point3D a, Point3D b)
    {
        return a.GetZ() < b.GetZ();
    });

    return Box3D(Point3D((*minmaxX.first).GetX(), (*minmaxY.first).GetY(), (*minmaxZ.first).GetZ()),
                 Point3D((*minmaxX.second).GetX(), (*minmaxY.second).GetY(), (*minmaxZ.second).GetZ()));
}
