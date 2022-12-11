#include <iostream>
#include <stdlib.h>
#include "Alumno.cpp"
using namespace std;

int main(){
    Alumno alumno1("","",0,"");
    //METODOS SET
    alumno1.setMatricula("A01637397");
    alumno1.setNombre("Sebastian Vega");
    alumno1.setEdad(18);
    alumno1.setCarrera("ITC");

    cout << "METODO GET" <<endl;
    cout << "Matricula del alumno: "<< alumno1.getMatricula() << endl;
    cout << "Nombre del alumno: "<< alumno1.getNombre()<< endl;
    cout << "Edad del alumno: "<< alumno1.getEdad()<< endl;
    cout << "Carrera del alumno: "<< alumno1.getCarrera()<< endl;
    
    cout << "METODO imprimeAlumno" << endl;
    alumno1.imprimeAlumno();


    cout << "METODO cumpleanios" <<endl;
    alumno1.cumpleanios();
    cout << "Nueva edad alumno: " << alumno1.getEdad();
    return 0;
}