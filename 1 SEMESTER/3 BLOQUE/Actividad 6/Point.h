#ifndef PUNTO_H
#define PUNTO_H
#include <iostream>

class Point{
    public:
        // Constructores
        Point();
        Point(double, double);
        // Acceso
        double getX();
        double getY();
        // Modificadores
        void setX(double);
        void setY(double);
        // Adicionales
        void imprime();
        double distancia(Point&);
    private:
        double x;
        double y;

};

#endif