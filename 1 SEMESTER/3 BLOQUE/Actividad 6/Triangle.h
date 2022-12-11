#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include "Point.cpp"
using namespace std;

class Triangle {
    private:
        Point vertex1, vertex2, vertex3;
    public:
        Triangle();
        Triangle(Point, Point, Point);
        void setV1(Point);
        void setV2(Point);
        void setV3(Point);
        Point getV1();
        Point getV2();
        Point getV3();
        double perimeter();
        double area();
};
#endif