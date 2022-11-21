//
// Created by coder on 25.10.22.
//
#include <valarray>
#include "Point3D.h"

Point3D::Point3D(int x, int y, int z) {
    _x = x;
    _y = y;
    _z = z;
}

Point3D Point3D::operator+(const Point3D &other) const {
    Point3D resPoint(_x + other._x, _y + other._y, _z + other._z);
    return resPoint;
}

Point3D Point3D::operator-(const Point3D &other) const {
    Point3D resPoint(_x - other._x, _y - other._y, _z - other._z);
    return resPoint;
}

Point3D Point3D::operator*(double coefficient) const {
    Point3D resPoint(_x * coefficient, _y * coefficient, _z * coefficient);
    return resPoint;
}

Point3D Point3D::operator/(double coefficient) const {
    Point3D resPoint(_x / coefficient, _y / coefficient, _z / coefficient);
    return resPoint;
}

bool Point3D::operator==(const Point3D &other) const {
    return this->_x == other._x && this->_y == other._y && this->_z == other._z;
}

bool Point3D::operator!=(const Point3D &other) const {
    return !(*this == other);
}

double Point3D::GetDistance(Point3D point) const
{
    return sqrt(pow(_x - point._x, 2) +
        pow(_y - point._y, 2) + pow(_z - point._z, 2));
}

Point3D Point3D::Rotate(double theta, double phi) const
{
    double x = GetX() * (cos(theta) * cos(phi)) + GetY() * (cos(theta) * sin(phi)) -
                GetZ() * sin(theta);
    double y = GetX() * -sin(phi) + GetY() * cos(phi);
    double z = GetX() * (sin(theta) * cos(phi)) + GetY() * (sin(theta) * sin(phi)) +
                GetZ() * cos(theta);
    return Point3D(x, y, z);
}

//Point3D Point3D::Cross(Point3D point) const {
//    Point3D resPoint(GetY() * point.GetZ() - GetZ() * point.GetY(),
//                     GetZ() * point.GetX() - GetX() * point.GetZ(),
//                     GetX() * point.GetY() - GetY() * point.GetX());
//    return resPoint;
//}
//
//Point3D CrossProduct(Point3D a, Point3D b)
//{
//    return a.Cross(b);
//}