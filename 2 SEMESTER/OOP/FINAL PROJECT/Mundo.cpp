#include "Mundo.hpp"


Mundo::Mundo(){
    this->nombre = "";
    this->descripcion = "";
    this->mundosiguiente = NULL;
    this->items = NULL;
    this->refpersonaje = NULL;
}

Mundo::Mundo(std::string nombre, std::string descripcion, Item* items, Personaje* refpersonaje, Mundo* mundosiguiente){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->mundosiguiente = NULL;
    this->items = items;
    this->refpersonaje = refpersonaje;
}


std::string Mundo::getNombre(){
    return this->nombre;
}

std::string Mundo::getDescripcion(){
    return this->descripcion;
}

Item* Mundo::getItem(){
    return this->items;
}

Personaje* Mundo::getPersonaje(){
    return this->refpersonaje;
}

Mundo* Mundo::getMundoSiguiente(){
    return this->mundosiguiente;
}

void Mundo::setNombre(std::string nombre){
    this->nombre = nombre;
}

void Mundo::setDescripcion(std::string descripcion){
    this->descripcion = descripcion;
}

void Mundo::setMundoSiguiente(Mundo* mundosiguiente){
    this->mundosiguiente = mundosiguiente;
}

void Mundo::setItem(Item* items){
    this->items = items;
}

void Mundo::setPersonaje(Personaje* refpersonaje){
    this->refpersonaje = refpersonaje;
}

void Mundo::mostrarMundo(){
    std::cout << "DATOS DE LA REGION"<< std::endl;
    std::cout << "-------------------------------------" <<std::endl;
    std::cout << "Nombre: " << this->nombre << std::endl;
    std::cout << "Descripcion: " << this->descripcion << std::endl;
    std::cout << "Personaje: " << this->refpersonaje->getNombre() << std::endl;
    std::cout << "-------------------------------------" <<std::endl;
    std::cout << " " << std::endl;
}