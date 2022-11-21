//
// Created by coder on 25.10.22.
//

#ifndef UNTITLED3_POINT3D_H
#define UNTITLED3_POINT3D_H


class Point3D {
    int _x;
    int _y;
    int _z;
public:
    Point3D(int x, int y, int z);

    Point3D operator+(const Point3D& other) const;
    Point3D operator-(const Point3D& other) const;
    Point3D operator*(double scalar) const;
    Point3D operator/(double scalar) const;
    void operator+=(const Point3D& other) { *this = *this + other; };
    void operator-=(const Point3D& other) { *this = *this - other; };
    bool operator==(const Point3D& other) const;
    bool operator!=(const Point3D& other) const;

    double GetDistance(Point3D point) const;
    Point3D Rotate(double theta, double phi) const;
    double GetX() const { return _x; }
    double GetY() const { return _y; }
    double GetZ() const { return _z; }
    //Point3D Cross(Point3D point) const;
};


#endif //UNTITLED3_POINT3D_H
