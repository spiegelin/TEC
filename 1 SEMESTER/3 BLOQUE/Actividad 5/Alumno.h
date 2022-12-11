#ifndef ALUMNO
#define ALUMNO
#include <iostream>
#include <stdlib.h>
using namespace std;

class Alumno{
    public:
        Alumno(string, string, int, string); // constructor
        string getMatricula();
        string getNombre();
        int getEdad();
        string getCarrera();
        void setMatricula(string mat);
        void setNombre(string nom);
        void setEdad(int ed);
        void setCarrera(string carr);
        void imprimeAlumno();
        void cumpleanios();
    private:
        string matricula;
        string nombre;
        int edad;
        string carrera;
};

#endif