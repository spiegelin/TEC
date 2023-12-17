#include "Personaje.hpp"

// Constructores
Personaje::Personaje() {}
Personaje::Personaje(std::string _nombre, std::string _desc, Mundo* _ubi,int _tipo) {
    nombre = _nombre;
    desc = _desc;
    ubi = _ubi;
    tipo = _tipo;
}

// Destructor
Personaje::~Personaje(){}

// Getters
std::string Personaje::getNombre() {
    return nombre;
}

std::string Personaje::getDesc() {
    return desc;
}

Mundo* Personaje::getUbi() {
    return ubi;
}

int Personaje::getTipo() {
    return tipo;
}

// Setters
void Personaje::setNombre(std::string _nombre) {
    nombre = _nombre;
}

void Personaje::setDesc(std::string _desc) {
    desc = _desc;
}

void Personaje::setUbi(Mundo* _ubi) {
    ubi = _ubi;
}

// Métodos
void Personaje::imprime() {
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "PERSONAJE: " << nombre << std::endl;
    std::cout << "UBICACIÓN: " << getUbi() -> getNombre() << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}

// Sobrecarga de operador de flujo de salida
std::ostream& operator<< (std::ostream& salida, Personaje& p) {
    salida << "-------------------------------------" << std::endl;
    salida << "PERSONAJE: " << p.getNombre() << std::endl;
    salida << "UBICACIÓN: " << p.getUbi() -> getNombre() << std::endl;
    salida << "-------------------------------------" << std::endl;

    return salida;
}