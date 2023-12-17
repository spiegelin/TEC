#include <iostream>
#include <cmath>
#include <stdexcept> // Usar las excepciones de c++
#include <string>
#include "ErrorMat.hpp"
#include "DivCero.hpp"

using namespace std;

double logaritmo(const double n){
    try {
        if (n < 0)
            throw(ErrorMat(ERROR_DOMINIO) );
        if (n == 0)
            throw(ErrorMat(ERROR_RANGO) );
        return log(n);
	}
    catch(ErrorMat& e) {
        cout << e.porque();
    }
    return 0;
}

void pruebaExcepcion8(){
    // prueba el manejo de excepciones a traves de una clase
    double numero = 100;
    cout << "log(" << numero << ") = " << logaritmo(numero) << endl;
    cout << "log(-" << numero << ") = " << logaritmo(-numero) << endl;
    cout << "log(0) = " << logaritmo(0) << endl;
}

void pruebaExcepcionCiclada() {
    double num,div;
    cout << "División entre dos números. " << endl;
    cout << "Ingrese el dividendo: "; cin >> num; cout << endl;
    cout << "Ingrese el divisor: "; cin >> div; cout << endl;
    while (true) {
        try {
            if (div == 0) {
                throw DivCero(); // Mensaje a decir, cualquier tipo de dato
            }

            if (div < 0) {
                throw "No quiero dividir negativos";
            }

            cout << "El resultado de la división es : " << num << "/" << div << " = " << num/div << endl;
            break;
        } catch(DivCero& exp) {
            cout << "Se presentó el error " << exp.what() << ": el divisor no puede ser 0" << endl;
            cout << "Ingresa un nuevo divisor: ";
            cin >> div; 
        } catch(const char* mag) {
            cout << mag << " No nos gustan los negativos en esta clase" << endl;
            cout << "Ingrese un nuevo divisor: "; cin >> div;
        }
    }
}

double raizCuadrada(double num) {
    if (num < 0) {
        string msg = "No calculo raíces imaginarias";
        throw invalid_argument(msg);
    }
    return sqrt(num);
}

void pruebaExcepcionLibreria() {
    double num;
    cout << "Ingresa el valor del cual quieres la raíz cuadrada: "; cin >> num; cout << endl;
    try {
        double resultado = raizCuadrada(num);
        cout << "La raíz cuadrada de " << num << " es " << resultado << endl;
    } catch(invalid_argument& excp){
        cout << excp.what() << " Lo siento..." << endl;

    }
}

int main() 
{
  //pruebaExcepcionCiclada();
  //pruebaExcepcionLibreria();
  pruebaExcepcion8();
}
