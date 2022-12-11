#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Producto{
    protected:
        string nombre;
        double preciounitario;
        double preciotot;
        int cantidad;
    public:
        Producto();
        Producto(string, double, double,int);
        ~Producto();
        string getNombreProducto();
        double getPrecioUnitario();
        double getPrecioTotal();
        int getCantidadProducto();

        void setNombre(string);
        void setPrecioUnitario(double);
        void setPrecioTotal(double);
        void setCantidad(int);
};

// Constructor
Producto::Producto() {

}

Producto::Producto(string _nombre, double _precio,double _preciotot, int _cantidad){
    nombre = _nombre;
    preciounitario = _precio;
    preciotot = _preciotot;
    cantidad = _cantidad;
}

// Destructor
Producto::~Producto(){

}

//METODOS GET
string Producto::getNombreProducto(){
    return nombre;
}
double Producto::getPrecioUnitario(){
    return preciounitario;
}
double Producto::getPrecioTotal(){
    return preciotot;
}
int Producto::getCantidadProducto(){
    return cantidad;
}

//METODOS SET
void Producto::setNombre(string _nombre){
    nombre = _nombre;
}
void Producto::setPrecioUnitario(double _preciouni){
    preciounitario = _preciouni;
}
void Producto::setPrecioTotal(double _preciotot){
    preciotot = _preciotot;
}
void Producto::setCantidad(int _cantidad){
    cantidad = _cantidad;
}


#endif