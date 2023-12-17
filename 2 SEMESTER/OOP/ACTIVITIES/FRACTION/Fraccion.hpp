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
        Fraccion operator+ (const Fraccion&); 

        // Sobrecarga de operador binario como función friend
        friend Fraccion operator- (const Fraccion&, const Fraccion&);
        
        // Sobrecarga de operador de flujo de salida
        friend std::ostream& operator<< (std::ostream &, const Fraccion&);
        
        // Sobrecarga de operador de flujo de entrada
        friend std::istream &operator>> (std::istream &, Fraccion&);
        
        // Sobrecarga de operador unario ++ prefijo -preincremento
        // int x = 5
        // int y = 5;
        // cout << ++x << endl; -> 6 (Antes de hacer cualquier cosa hace el incremento y luego hace lo demás del renglón)
        // cout << y++ << endl; -> 5 (El incremento sucede hasta que todo lo demás en el renglón se realice)
        // cout << y << endl; -> 6

        Fraccion operator++(); // (1/4)++ -> 2/4 (En este caso solo vamos a incrementar al numerador)
        
        // Sobrecarga de operador unario ++ postfijo -postincremento
        Fraccion operator++(int);

        // Agrega el prototipo para tener la sobrecarga de -- predecremento 
        Fraccion operator--();

        // Agrega el prototipo para tener la sobrecarga de -- postdecremento
        Fraccion operator--(int);

        // Agrega lo necesario para tener la sobrecarga del operador += como función miembro o friend tu decides
        void operator+= (const Fraccion&); // No devuelve nada, soll realiza la operación, se usa const para no modificarla dentro de la función
        
        // Sobrecarga del operador booleano > como funcion de la clase (función miembro)
        bool operator> (const Fraccion&);

        // Sobrecarga el operador == como friend
        friend bool operator==(const Fraccion&, const Fraccion&); // Numeradores y denominadores deben ser iguales - Y como es friend no tienes acceso a this objeto, entonces le mandas dos parámetros
        
    private:
        int num;
        int den;
        int mcd(int, int);
};