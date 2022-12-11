#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Fecha{
    private:
        int dia, mes;
    public:
        // Constructor y Destructor
        Fecha(int,int);
        Fecha();
        ~Fecha();

        // Getters
        int getDia();
        int getMes();

        // Setters
        void setDia(int);
        void setMes(int);
};
// Constructor y Destructor
Fecha::Fecha(){}
Fecha::~Fecha(){}
Fecha::Fecha(int _dia, int _mes){
    dia = _dia;
    mes = _mes;
}

// Getters
int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return mes;
}

// Setters
void Fecha::setDia(int _dia){
    dia = _dia;
}
void Fecha::setMes(int _mes){
    mes = _mes;
}


class Empleado{
    private:
        string nombre; char nivel;
        float sueldo;
        Fecha fechaCumple;
        int dia, mes;
    public:
        // Constructor y Destructor
        Empleado();
        ~Empleado();

        // Getters
        string getNombre();
        float getSueldo();
        char getCategoria();
        Fecha getFecha();

        // Setters
        void setNombre(string);
        void setSueldo(float);
        void setCategoria(char);
        void setFecha(Fecha);

        // Adicional
        void promoverEmpleado(char);
};
// Constructor y Destructor
Empleado::Empleado(){}
Empleado::~Empleado(){}

// Getters
string Empleado::getNombre(){
    return nombre;
}
float Empleado::getSueldo(){
    return sueldo;
}
char Empleado::getCategoria(){
    return nivel;
}
Fecha Empleado::getFecha(){
    return fechaCumple;
}

// Setters
void Empleado::setNombre(string _nombre){
    nombre = _nombre;
}
void Empleado::setSueldo(float _sueldo){
    sueldo = _sueldo;
}
void Empleado::setCategoria(char _nivel){
    if (_nivel != 'A' && _nivel != 'B' && _nivel != 'C' && _nivel != 'D'){
        cout << "Categoria inválida" << endl;
    } else {
        nivel = _nivel;
    }
}
void Empleado::setFecha(Fecha _fechaCumple){
    fechaCumple = _fechaCumple;
}

// Adicionales
void Empleado::promoverEmpleado(char categoria){
    if (categoria > nivel) {
        if (categoria == nivel+3) {
            sueldo = sueldo + sueldo*(0.075);
        } else if (categoria == nivel+2) {
            sueldo = sueldo + sueldo*(0.05);
        } else {
            sueldo = sueldo + sueldo*(0.025);
        }
        nivel = categoria;
    }
}

int main(){
    // Creación Empleados
    Empleado emp1;
    Empleado emp2;

    // Empleado 1
    emp1.setNombre("Pepe");
    emp1.setSueldo(10000);
    emp1.setCategoria('A');
    emp1.setFecha(Fecha(19, 5));

    // Empleado 1
    emp2.setNombre("Rocio");
    emp2.setSueldo(12000);
    emp2.setCategoria('B');
    emp2.setFecha(Fecha(1, 1));

    // Mostrar Datos
    cout << "Nombre: " << emp1.getNombre() << " | Sueldo: "<< emp1.getSueldo() << " | Categoria: " << emp1.getCategoria() << " | Cumpleaños: " << emp1.getFecha().getDia() << "/"<< emp1.getFecha().getMes() << endl;
    cout << "Nombre: " << emp2.getNombre() << " | Sueldo: "<< emp2.getSueldo() << " | Categoria: " << emp2.getCategoria() << " | Cumpleaños: " << emp2.getFecha().getDia() << "/"<< emp2.getFecha().getMes() << endl;

    // Promover a Pepe a D
    emp1.promoverEmpleado('D');
    cout << "Nombre: " << emp1.getNombre() << " | Sueldo: "<< emp1.getSueldo() << " | Categoria: " << emp1.getCategoria() << endl;

    // Fecha Cumpleaños Rocío
    cout << "Fecha de Cumpleaños: " << emp2.getFecha().getDia() << "/"<< emp2.getFecha().getMes() << endl;

    // Casos de Prueba
    emp1.setCategoria('Z');
    emp2.promoverEmpleado('A');
    emp2.setCategoria('A');
    emp2.promoverEmpleado('C');
}