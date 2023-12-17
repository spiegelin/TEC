#include <iomanip>
#include <cmath>
#include "Tiempo.hpp"
// ===================================
// Implementación de la clase Tiempo
// ===================================

Tiempo::Tiempo() {
    hora = 0;
    minu = 0;
}

Tiempo::Tiempo(int h, int m) {
    hora = h;
    minu = m;
}

void Tiempo::setHora(int h) {
    hora = h;
}

void Tiempo::setMinu(int m) {
    if (m - 60 >= 0) {
        int horas = (int)floor(m / 60);
        int extraMinu =  m - horas*60;
        setHora(hora + horas);
        minu = extraMinu; 
    } else {
        minu = m;
    }
}

int Tiempo::getHora() const {
    return hora;
}

int Tiempo::getMinu() const{
    return minu;
}

// Agrega las implementaciones de los métodos de sobrecarga de operadores
// Operador ++ incrementa (preincremento) el Tiempo en 1 minuto y regresa el tiempo
Tiempo Tiempo::operator++() {
    setMinu(++minu);
    return *this;
}

//Friend. operador -- decrementa (predecremento)el Tiempo en 1 minuto y regresa el tiempo
// si la hora es 0:0 y se pide decrementar, regresa 0:0
Tiempo Tiempo::operator--() {
    if (hora == 0 && minu == 0) {
        return *this;
    } else {
        if (minu == 0) {
            setHora(--hora);
            setMinu(59);
        } else {
            setMinu(--minu);
        }
        return *this;
    }
}

// Miembro de la clase. operador > Compara si el primer Tiempo es mayor que el segundo
bool Tiempo::operator>(const Tiempo& t2) {
    if (hora > t2.hora) {
        return true;
    } else if (hora == t2.hora) {
        return minu > t2.minu;
    } else {
        return false;
    }
    //return hora > t2.hora ? true : minu > t2.minu;
}

// Miembro de la clase. operador + Para sumar tiempo + minutos, regresa un tiempo como resultado
// Hacer que no exceda cantidad de minutos **************************+
Tiempo Tiempo::operator+(int m) {
    int min = minu + m;
    int horas = 0;
    if (min - 60 >= 0) {
        horas = floor(min/60);
        min = min - horas*60;
    }
    Tiempo suma(horas + hora, min);
    return suma;
}

// Friend. operador + Para sumar minutos + tiempo, regresa un tiempo como resultado
// Hacer que no exceda cantidad de minutos **************************+
Tiempo operator+(int m, Tiempo& t1) {
    int min = m + t1.minu;
    int horas = 0;
    if (min - 60 >= 0) {
        horas = floor(min/60);
        min = min - horas*60;
    }
    Tiempo suma(horas + t1.hora, min);
    return suma;
}

// Miembro de la clase. operador + Suma t1 con t2 y regresa un tiempo con el resultado
// Hacer que no exceda cantidad de minutos **************************+
Tiempo Tiempo::operator+(Tiempo& t2) {
    int m = minu + t2.minu;
    int h = hora + t2.hora;
    if (m - 60 >= 0) {
        int horas = floor(m / 60);
        int extraMinu =  m - horas*60;
        Tiempo suma(h + horas,extraMinu);
        return suma;
    } else {
        Tiempo suma(h,m);
        return suma;
    }
}

// Friend. operador += Suma t1 con t2 y deja el resultado en t1, no regresa nada
// Funciona porque ya sobrecargamos el operador + desde antes
void operator+=(Tiempo& t1, Tiempo& t2) {
    t1 = t1 + t2;
}

// Sobrecarga el operador de salida: Friend. operador << Imprime el tiempo con el formato 00:00 a través del operador <<
std::ostream& operator<< (std::ostream& salida, const Tiempo& t1) {
    if (t1.hora >= 10) {
        if (t1.minu >= 10) {
            salida << t1.hora << ":" << t1.minu;
        } else {
            salida << t1.hora << ":0" << t1.minu;
        }
    } else {
        if (t1.minu >= 10) {
            salida << "0" << t1.hora << ":" << t1.minu;
        } else {
            salida << "0" << t1.hora << ":0" << t1.minu;
        }
    }
    return salida;
}

// sobrecarga el operador de entrada: Friend. operador >> Lee el tiempo obtiene hora y minutos a través del operador >>
std::istream &operator>> (std::istream& entrada, Tiempo& t1) {
    int h,m;
    entrada >> h >> m;
    t1.setHora(h);
    t1.setMinu(m);
    return entrada;
}