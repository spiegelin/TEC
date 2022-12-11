#include <iostream>
#include "Triangle.cpp"
using namespace std;

int main() {
    // Pasado por omisión
    Triangle triangulo1;
    cout << "Perímetro Triángulo 1: " << triangulo1.perimeter() << endl;
    cout << "Área Triángulo 1: " << triangulo1.area() << endl;

    // Definido
    Triangle triangulo2(Point(20,100), Point(180,60), Point(38,12));
    cout << "Perímetro Triángulo 2: " << triangulo2.perimeter() << endl;
    cout << "Área Triángulo 2: " << triangulo2.area() << endl;

    return 0;
}