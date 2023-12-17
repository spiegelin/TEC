#include "Item.hpp"
#include <iostream>

Item::Item(){
    this->nombre = "";
    this->descripcion = "";
    this->puntos = 0;
    this->tipo = "";
}

Item::Item(std::string nombre, std::string descripcion, int puntos, std::string tipo){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->puntos = puntos;
    this->tipo = tipo;
}


std::string Item::getNombre(){
    return this->nombre;
}

std::string Item::getDescripcion(){
    return this->descripcion;
}

int Item::getPuntos(){
    return this->puntos;
}

std::string Item::getTipo(){
    return this->tipo;
}

void Item::setNombre(std::string nombre){
    this->nombre = nombre;
}

void Item::setDescripcion(std::string descripcion){
    this->descripcion = descripcion;
}

void Item::mostrarItem(){
    std::cout << "Nombre: " << this->nombre << std::endl;
    std::cout << "Descripcion: " << this->descripcion << std::endl;
    std::cout << "Puntos: " << this->puntos << std::endl;
}