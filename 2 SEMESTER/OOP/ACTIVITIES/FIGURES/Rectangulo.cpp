#include "Rectangulo.hpp"

Rectangulo::Rectangulo() {
    ancho = 1;
    largo = 2;
}

Rectangulo::Rectangulo(int _x, int _y, int _ancho, int _largo): Figura(_x, _y) {
    ancho = _ancho;
    largo = _ancho;
}

int Rectangulo::getAncho() const {
    return ancho;
}

void Rectangulo::setAncho(int _ancho) {
    ancho = _ancho <= 0 ? 1 :_ancho;
}

int Rectangulo::getLargo() const {
    return largo;
}

void Rectangulo::setLargo(int _largo) {
    largo = _largo <= 0 ? 1 :_largo;
}

int Rectangulo::perimetro() {
    return (2*ancho + 2*largo);
}

std::string Rectangulo::dibuja() {
    return Figura::dibuja() + ": Rectángulo";
}

double Rectangulo::area() {
    return largo*ancho;
}