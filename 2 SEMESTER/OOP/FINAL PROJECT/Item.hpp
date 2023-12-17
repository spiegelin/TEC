#pragma once
#include <iostream>


class Item {

private:
    std::string nombre;
    std::string descripcion;
    int puntos;
    std::string tipo;

public:
    Item();
    Item(std::string, std::string, int, std::string);
    std::string getNombre();
    std::string getDescripcion();
    std::string getTipo();
    int getPuntos();
    void setNombre(std::string);
    void setDescripcion(std::string);
    void mostrarItem();
};