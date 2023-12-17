#include "Profesor.hpp"
// ===============
// implementations

// Constructor
Profesor::Profesor() {
    numNomina = 0;
    sueldoBase = 200.0;
}

Profesor::Profesor(int _numNomina, double _sueldoBase) {
    numNomina = _numNomina;
    sueldoBase = _sueldoBase;
}

// Getters
double Profesor::getSueldoBase() {
    return sueldoBase;
}

int Profesor::getNumNomina() {
    return numNomina;
}

// Setters
void Profesor::setSueldoBase(double _sueldoBase) {
    sueldoBase = _sueldoBase;
}
void Profesor::setNumNomina(int _numNomina) {
    numNomina = _numNomina;
}

bool Profesor::operator==(Profesor& p2) {
    if (this -> calculaSueldoFinal() == p2.calculaSueldoFinal()) {
        return true;
    } else {
        return false;
    }
}