#include "Fraccion.hpp"

Fraccion::Fraccion(){
    num=0;
    den=1;
}

Fraccion::Fraccion(int n, int d){
    num=n;
    setDen(d);
}

int Fraccion::getNum() const{
    return num;
}

int Fraccion::getDen() const{
    return den;
}

void Fraccion::setNum(int n) {
    num=n;
    int mcdiv=mcd(num,den);
    num=num/mcdiv;
    den=den/mcdiv;
}

void Fraccion::setDen(int d) {
    if (d > 0){
        int mcdiv=mcd(num,d);
        num=num/mcdiv;
        den=d/mcdiv;
    } else {
        den = 1;
    }
}

//método privado de la clase para calcular minimo comun denominador
int Fraccion::mcd(int n, int d){
    int num1, num2, residuo;
    num1=abs(n);
    num2=abs(d);
    while (num2 > 0){
        residuo=num1 % num2;
        num1=num2;
        num2=residuo;
        
    }
    return num1;
}
Fraccion Fraccion::operator+(const Fraccion& f1){
    int n = num*f1.den + den*f1.num;
    int d = den * f1.den;
    Fraccion suma(n,d);
    return suma; 
}

Fraccion operator-(const Fraccion& f1, const Fraccion& f2){
    int n = f1.num*f2.den - f1.den*f2.num;
    int d = f1.den * f2.den;
    Fraccion resta(n,d);
    return resta; 
}

std::ostream& operator<< (std::ostream& salida, const Fraccion& f1){
    salida<< f1.num << "/" << f1.den;
    return salida;
}

std::istream& operator>> (std::istream& entrada, Fraccion& f1){
    int n,d;
    entrada >> n >> d;
    f1.setNum(n);
    f1.setDen(d);
    return entrada;
}

bool Fraccion::operator>(const Fraccion& f1){
    return num*f1.den > f1.num*den;
}