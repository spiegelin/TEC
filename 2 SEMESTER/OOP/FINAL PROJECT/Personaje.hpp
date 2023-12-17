#pragma once

#include <iostream>
#include "Mundo.hpp"

class Mundo;

class Personaje {
    public:
        // Constructores
        Personaje();
        Personaje(std::string, std::string, Mundo*,int);

        // Destructor
        ~Personaje();

        // Getters
        std::string getNombre();
        std::string getDesc();
        Mundo* getUbi();
        int getTipo();

        // Setters
        void setNombre(std::string);
        void setDesc(std::string);
        void setUbi(Mundo*);

        // Métodos
        virtual void imprime();
        virtual int juega(int) = 0;
        virtual void recibeInteraccion(int) = 0;
        virtual bool isAlive() = 0;

        // Sobrecarga de operador de flujo de salida
        friend std::ostream& operator<< (std::ostream&, Personaje&);
    private:
        std::string nombre;
        std::string desc;
        Mundo* ubi;
        int tipo;
};