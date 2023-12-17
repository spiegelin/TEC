#pragma once

#include "Personaje.hpp"

class PersonajeAmistoso: public Personaje {
    public:
        // Constructores
        PersonajeAmistoso();
        PersonajeAmistoso(std::string, std::string, Mundo*,int, bool, std::string);

        // Destructor
        ~PersonajeAmistoso();

        // Getters
        bool getEstatus();
        std::string getHistoria();

        // Setters
        void setEstatus(bool);
        void setHistoria(std::string);

        // Métodos
        int juega(int) override;
        void recibeInteraccion(int) override;
        bool isAlive() override;
    private:
        bool estatus;
        std::string historia;
};