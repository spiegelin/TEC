#include <vector>   
#include "ProfesorTC.hpp"
#include "ProfesorHoras.hpp"
#include <iostream>
using namespace std;

int main()
{
    //Escribe el código necesario de acuerdo a las instrucciones del readme
    vector<Profesor*> profesores;
    profesores.push_back(new ProfesorHoras(112, 150.35, 40));
    profesores.push_back(new ProfesorTC(111, 20000.00, 5));
    profesores.push_back(new ProfesorHoras(110, 375.00, 50));

    ProfesorTC p1(100, 15000.00, 25);

    for (int i = 0; i < profesores.size(); i++) {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "SUELDO PROFESOR POSICIÓN " << i << ": " << profesores[i] -> calculaSueldoFinal() << endl;
        if (p1 == *profesores[i]) {
            cout << endl;
            cout << "¡¡¡Profesor en la posición " << i << " tiene el mismo sueldo que Profesor p1!!!" << endl;
            cout << "SUELDO PROFESOR POSICIÓN " << i << ": " << profesores[i] -> calculaSueldoFinal() << " == " << "SUELDO PROFESOR p1: " << p1.calculaSueldoFinal() << endl;
        }
    }
    cout << "--------------------------------------------------------------------------------" << endl;

}