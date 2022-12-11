#include <iostream>
#include <stdlib.h>
using namespace std;

class Tiempo{
    private:
        int horas, minutos, segundos;
    public:
        Tiempo(int,int,int);
        Tiempo(int);
        void mostrarResultado();
};

Tiempo::Tiempo(int _horas, int _minutos, int _segundos){
    horas = _horas;
    minutos = _minutos;
    segundos = _segundos;
}

Tiempo::Tiempo(int _segundos){
    horas = (int)_segundos / 3600;
    minutos = (int)(_segundos - 3600*horas)/60;
    segundos = (int)(_segundos - (60*minutos)) - int(3600*horas);
}

void Tiempo::mostrarResultado(){
    printf("Horas: %d, Minutos: %d, Segundos %d\n", horas, minutos, segundos);
}

int main(){
    Tiempo num1(2,30,32);
    Tiempo num2(3601);

    num1.mostrarResultado();
    num2.mostrarResultado();
}