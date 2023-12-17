#pragma once
#include <iostream>
#include "Item.hpp"
#include "Personaje.hpp"

class Item;
class Personaje;

class Mundo{
    private:
        std::string nombre;
        std::string descripcion;
        Mundo* mundosiguiente;
        Item* items;
        Personaje* refpersonaje;
    public:
        Mundo();
        Mundo(std::string, std::string, Item*, Personaje*, Mundo*);
        std::string getNombre();
        std::string getDescripcion();
        Item* getItem();
        Personaje* getPersonaje(); 
        Mundo* getMundoSiguiente();
        void setNombre(std::string);
        void setDescripcion(std::string);
        void setMundoSiguiente(Mundo*);
        void setItem(Item*);
        void setPersonaje(Personaje*);
        void mostrarMundo();
};