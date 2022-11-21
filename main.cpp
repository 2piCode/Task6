#include <iostream>
#include "Box3D.h"
#include "Cube3D.h"
#include "Sphere3D.h"
#include "Tetra3D.h"
#include <cassert>
#include <cmath>

void TestPoint3D()
{
    // Конструктор Point3D
    Point3D a(2, 0, 0);

    // Операции с объектом Point3D
    assert(a == Point3D(2, 0, 0));
    assert(a != Point3D(1, 0, 0));
    assert(a + Point3D(1, 1, 1) == Point3D(3, 1, 1));
    assert(a - Point3D(1, 1, 1) == Point3D(1, -1, -1));
    assert(a * 2 == Point3D(4, 0, 0));
    assert(a / 2 == Point3D(1, 0, 0));
    assert(a.Rotate(0, -M_PI_2) == Point3D(0, 2, 0));
}

void TestBox3D()
{
    //Конструкторы Box3D
    Box3D b1(Point3D(0.5, 0.5, 0.5), 1, 1, 1);
    Box3D b2(Point3D(1, 1, 1), 2, 2, 2);

    //Пересечение с самим собой
    assert(b1.HasIntersection(b1));
    //Пересечение 2-ух Box3D
    assert(b1.HasIntersection(b2) && b2.HasIntersection(b1));

    b2 = Box3D(Point3D(2.5, 2.5, 2.5), 1, 1, 1);
    //Проверка не пересекающихся Box3D
    assert(!b1.HasIntersection(b2) && !b2.HasIntersection(b1));
}

void TestCube3D()
{
    //Конструкторы Cube3D
    Cube3D c1(Point3D(0, 0, 0), 1);
    Cube3D c2(Point3D(0, 0, 0), 1, 0, 0);

    //Пересечение 2-ух Cube3D
    assert(c1.HasIntersection(c2) && c2.HasIntersection(c1));
    //Поворот c2
    c2 = Cube3D(Point3D(0, 0, 0), 1, 45, 37);
    //Повторная проверка на пересечение
    assert(c1.HasIntersection(c2) && c2.HasIntersection(c1));
}

void TestSphere3D()
{
    //Конструкторы Sphere3D
    Sphere3D s1(Point3D(0, 0, 0), 1);
    Sphere3D s2(Point3D(1, 1, 1), 2);
    //Пересечение с самим собой
    assert(s1.HasIntersection(s1) && s2.HasIntersection(s2));
    //Пересечение 2-ух Sphere3D
    assert(s1.HasIntersection(s2) && s2.HasIntersection(s1));
}

void TestTetra3D()
{
    //Конструкторы Tetra3D
    Tetra3D t1(Point3D(0, 0, 0), Point3D(1, 0, 0), Point3D(0, 1, 0), Point3D(0, 0, 1));
    Tetra3D t2(Point3D(0, 0, 0), Point3D(2, 0, 0), Point3D(0, 2, 0), Point3D(0, 0, 1));
    //Пересечение 2-ух Tetra3D
    assert(t1.HasIntersection(t2) && t2.HasIntersection(t1));
}

void RunTest()
{
    TestPoint3D();
    std::cout << "Test Point3D passed" << std::endl;

    TestBox3D();
    std::cout << "Test Box3D passed" << std::endl;

    TestSphere3D();
    std::cout << "Test Sphere3D passed" << std::endl;

    TestCube3D();
    std::cout << "Test Cube3D passed" << std::endl;

    TestTetra3D();
    std::cout << "Test Tetra3D passed" << std::endl;

    std::cout << "All tests passed" << std::endl;
}



int main()
{
    RunTest();
}