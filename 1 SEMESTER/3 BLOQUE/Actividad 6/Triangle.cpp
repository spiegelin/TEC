#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "Triangle.h"
using namespace std;

Triangle::Triangle() {
    vertex1 = Point(0,0);
    vertex2 = Point(50,30);
    vertex3 = Point(25,10);
}
Triangle::Triangle(Point _vertex1, Point _vertex2, Point _vertex3){
    vertex1 = _vertex1;
    vertex2 = _vertex2;
    vertex3 = _vertex3;
}
double Triangle::perimeter() {
    // Usando fórmula de distancia entre dos puntos
    // d = sqrt((x2-x1)^2 + (y2-y1)^2)
    double perimetro = vertex1.distancia(vertex2) + vertex1.distancia(vertex3) + vertex2.distancia(vertex3);
    return perimetro;
}
double Triangle::area() {
    // Usando la fórmula de Herón
    // Area = sqrt(s(s-a)(s-b)(s-c))
    double s = (float)perimeter() / 2;
    double area = sqrt(s*(s-vertex1.distancia(vertex2))*(s-vertex1.distancia(vertex3))*(s-vertex2.distancia(vertex3)));
    return area;
}
void Triangle::setV1(Point _vertex1){
    vertex1 = _vertex1;
}
void Triangle::setV2(Point _vertex2){
    vertex2 = _vertex2;
}
void Triangle::setV3(Point _vertex3){
    vertex3 = _vertex3;
}
Point Triangle::getV1(){
    return vertex1;
}
Point Triangle::getV2(){
    return vertex2;
}
Point Triangle::getV3(){
    return vertex3;
}
