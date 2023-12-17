#include "Circulo.hpp"

const double Circulo::PI = 3.1415967;

Circulo::Circulo() {
    radio = 1;
}

Circulo::Circulo(int _x, int _y, int _radio):Figura(_x, _y) {
    radio = _radio;
}

int Circulo::getRadio() const {
    return radio;
}

void Circulo::setRadio(int _radio) {
    radio = _radio <= 0 ? 1 :_radio; // Condicional terciario
}

double Circulo::circunferencia() {
    return 2*PI*radio;
}

std::string Circulo::dibuja() {
    return Figura::dibuja() + ": Circulo";
}

double Circulo::area() {
    return PI*radio*radio;
}