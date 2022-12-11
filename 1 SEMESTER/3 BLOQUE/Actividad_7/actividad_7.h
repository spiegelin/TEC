#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "actividad_7.h"
using namespace std;

class Fraccion {
    private: 
        int num, den;
    public:
        // Constructores
        Fraccion();
        Fraccion(int, int);

        // Destructor
        ~Fraccion();

        // Acceder a Atributos
        int getNumerador();
        int getDenominador();

        // Modificar Atributos
        void setNumerador(int);
        void setDenominador(int);

        // Operaciones
        double calcValorReal();
        void sumaFracciones(int, int, int, int);
        void imprimeFraccion();
};
// Constructor Vacío
Fraccion::Fraccion(){
    num = 1;
    den = 2;
}
// Constructor
Fraccion::Fraccion(int _num, int _den){
    num = _num;
    den = _den;
}
// Destructor
Fraccion::~Fraccion(){
}
// Regresar el valor del numerador
int Fraccion::getNumerador() {
    return num;
}
// Regresar el valor de denominador
int Fraccion::getDenominador(){
    return den;
}
// Modificar el valor del numerador
void Fraccion::setNumerador(int _num){
    num = _num;
}
// Modificar el valor del denominador
void Fraccion::setDenominador(int _den){
    den = _den;
}
// Calcular Decimal
double Fraccion::calcValorReal(){
    return (float)num / den;
}
// Sumar Fracciones y Devolver resultado como objeto
void Fraccion::sumaFracciones(int _num1, int _den1, int _num2, int _den2) {
    int numr, denr; // Numerador y denominador del resultado de la suma
    if (_den1 == _den2) {
        numr = _num1 + _num2;
        denr = _den1;
    } else {
        denr = _den1 * _den2;
        numr = (_num1 * _den2) + (_num2 * _den1);
    }
    Fraccion resultado(numr, denr); // Fraccion sin simplificar
}
// Imprimir fracción
void Fraccion::imprimeFraccion(){
    cout << num / den << endl;
}