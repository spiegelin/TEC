// Escribe la implementación de la clase, no olvides los includes necesarios
#include "ProfesorTC.hpp"

// Constructores
ProfesorTC::ProfesorTC() {
    incentivo = 2;
}

ProfesorTC::ProfesorTC(int _numNomina, double _sueldoBase, int _incentivo): Profesor(_numNomina, _sueldoBase) {
    incentivo = _incentivo;
}

// Getters
int ProfesorTC::getIncentivo() {
    return incentivo;
}

// Setters
void ProfesorTC::setIncentivo(int _incentivo) {
    incentivo = _incentivo;
}

double ProfesorTC::calculaSueldoFinal() {
    // Escribe el método calculaSueldoFinal(), un profesor de tiempo completo, tiene un sueldo base al mes 
    // y se gana un % extra de incentivo por desempeño, calculado sobre el sueldo base. 
    // Por ejemplo si el sueldo base de un profesor es 10000 al mes y tiene un incentivo del 5% su sueldo final será: 
    // 10500.00
    return Profesor::getSueldoBase() * incentivo/100 + Profesor::getSueldoBase();
}