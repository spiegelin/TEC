#include <cmath>
#include "Point.h"
using namespace std;

// Constructor por omisión
Point::Point(){
    x = 0;
    y = 0;
}
// Constructor por parámetros
Point::Point(double _x, double _y) {
    x = _x;
    y = _y;
}
// Métodos de Acceso
double Point::getX(){
    return x;
}
double Point::getY(){
    return y;
}
// Modificación
void Point::setX(double _x){
    x = _x;
}
void Point::setY(double _y){
    y = _y;
}
// Extra
void Point::imprime(){
    cout << "X: " << x << " - Y: " << y << endl;
}
double Point::distancia(Point& p) {
    double resultado = sqrt(pow((p.x - x), 2) + pow((p.y - y), 2));
    return resultado;
}