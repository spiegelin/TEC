#pragma once
#include <iostream>

class Fraccion
{
    public:
        Fraccion();
        Fraccion(int, int);
        int getNum() const;
        int getDen() const;
        void setNum(int);
        void setDen(int);
        //Sobrecarga de operador binario como miembro de la clase
        Fraccion operator+(const Fraccion&); 

        // Sobrecarga de operador binario como función friend
        friend Fraccion operator-(const Fraccion&, const Fraccion&);
        
        // Sobrecarga de operador de flujo de salida
        friend std::ostream& operator<< (std::ostream &, const Fraccion&);
        
        // Sobrecarde de operador de flujo de entrada
        friend std::istream &operator>> (std::istream &, Fraccion&);
        
        // Sobrecarga de operador unario ++ prefijo -preincremento
        //Fraccion operator++ ();
        
        // Sobrecarga de operador unario ++ postfijo -postincremento
        //Fraccion operator++ (int);

        // Agrega el prototipo para tener la sobrecarga de -- predecremento 
        // Agrega el prototipo para tener la sobrecarga de -- postdecremento
        // Agrega lo necesario para tener la sobrecarga del operador += como función miembro o friend tu decides
        
        // Sobrecarga del operador booleano > como funcion de la clase (función miembro)
        bool operator> (const Fraccion&);
        
    private:
        int num;
        int den;
        int mcd(int, int);
};