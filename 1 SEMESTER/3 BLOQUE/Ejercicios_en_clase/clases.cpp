#include <iostream>
#include <stdlib.h>
using namespace std;

class Persona{
    private:
        int edad;
        string nombre;
    public:
        Persona(int,string); // constructor
        void correr();
        void leer();
};

Persona::Persona(int age, string name) {
    edad = age;
    nombre=name;
}

void Persona::leer(){
    cout<<"Soy "<<nombre<<" y me gusta leer"<< endl;
}

void Persona::correr() {
    cout << "Soy " <<nombre<<", tengo "<<edad<<" y estoy corriendo"<<endl;
}

int main(){
    Persona p1 = Persona(18, "Diego");
    Persona p2(24, "Ely");
    p1.leer();
    p2.correr();
}