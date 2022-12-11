#include <iostream>
#include <stdlib.h>
#include "Alumno.h"
using namespace std;

Alumno::Alumno(string matricula, string nombre, int edad, string carrera) {
    edad = edad;
    nombre = nombre;
    matricula = matricula;
    carrera = carrera;
}

string Alumno::getMatricula() {
    return matricula;
}

string Alumno::getNombre() {
    return nombre;
}

int Alumno::getEdad() {
    return edad;
}

string Alumno::getCarrera() {
    return carrera;
}

void Alumno::setMatricula(string mat){
    matricula = mat;
}

void Alumno::setNombre(string nom){
    nombre = nom;
}

void Alumno::setEdad(int ed){
    edad = ed;
}

void Alumno::setCarrera(string carr){
    carrera = carr;
}

void Alumno::imprimeAlumno(){
    cout << "Matricula: "+ matricula << endl;
    cout <<"Nombre: "+ nombre << endl;
    cout <<"Edad: "+ edad << endl;
    cout <<"Carrera: "+ carrera << endl;
}

void Alumno::cumpleanios(){
    edad +=1;
}
