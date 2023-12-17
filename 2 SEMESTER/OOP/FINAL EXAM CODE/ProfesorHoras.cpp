// EScribe TODO lo necesario para la implementación de tu clase, no olvides los includes
#include "ProfesorHoras.hpp"

// Constructores
ProfesorHoras::ProfesorHoras() {
    horas = 1;
}

ProfesorHoras::ProfesorHoras(int _numNomina, double _sueldoBase, int _horas): Profesor(_numNomina, _sueldoBase) {
    horas = _horas;
}

// Getters
int ProfesorHoras::getHoras() {
    return horas;
}

// Setters
/*
void ProfesorHoras::setHoras(int _horas) {
    horas = _horas;
}
*/

double ProfesorHoras::calculaSueldoFinal() {
    // Escribe el método calculaSueldoFinal(), el cual se calcula multiplicando el sueldo base que para estos 
    // profesores corresponde a lo que se le paga por hora y se multiplica por el número de horas que trabaja al mes.
    return Profesor::getSueldoBase() * horas;
}