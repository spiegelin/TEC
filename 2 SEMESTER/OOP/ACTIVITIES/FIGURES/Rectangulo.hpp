#pragma once
#include "Figura.hpp"

class Rectangulo: public Figura {
    public:
        // Constructores
        Rectangulo();
        Rectangulo(int, int, int, int);

        // Setters y Getters
        int getAncho() const;
        void setAncho(int ancho);
        int getLargo() const;
        void setLargo(int largo);

        // Métodos
        std::string dibuja() override;
        int perimetro();
        double area();
    private:
        int ancho;
        int largo;
};