#pragma once

#include "Personaje.hpp"

class PersonajeGuerrero: public Personaje {
    public:
        // Constructores
        PersonajeGuerrero();
        PersonajeGuerrero(std::string, std::string, Mundo*, int, int, int, int);

        // Destructor
        ~PersonajeGuerrero();

        // Getters
        int getSaludTotal();
        int getSaludActual();
        int getMaxAtaque();

        // Setters
        void setSaludTotal(int);
        void setSaludActual(int);
        void setMaxAtaque(int);

        // Métodos
        bool isAlive() override;
        int porcentajeSalud();
        void barraVida();
        void imprime() override;
        int juega(int) override;
        void recibeInteraccion(int) override;
    private:
        int saludTotal;
        int saludActual;
        int maxAtaque;
};