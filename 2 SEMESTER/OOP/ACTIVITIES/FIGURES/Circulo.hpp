#pragma once
#include <iostream>
#include "Figura.hpp"

class Circulo: public Figura {
    public:
        const static double PI; // static se refiere a que se puede acceder a ella sin la necesidad de crear un objeto para ver su valor
        Circulo();
        Circulo(int, int, int);
        int getRadio() const;
        void setRadio(int radio);
        std::string dibuja() override;
        double circunferencia();
        double area();
    private:
        int radio;
};