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

void Fraccion::setDen(int den) {
    if (den > 0){
        int mcdiv=mcd(num,den);
        this -> num=num/mcdiv; // Atributo de mi objeto this -> den, parámetro dado den solito, así no se confunde
        this -> den=den/mcdiv;
    } else {
        den = 1;
    }
}

/*
void Fraccion::setDen(int d) {
    if (d > 0){
        int mcdiv=mcd(num,d);
        num=num/mcdiv; 
        den=d/mcdiv;
    } else {
        den = 1;
    }
}
*/

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

std::ostream& operator<<(std::ostream& salida, const Fraccion& f1){
    salida<< f1.num << "/" << f1.den;
    return salida;
}

std::istream& operator>>(std::istream& entrada, Fraccion& f1){
    int n,d;
    entrada >> n >> d;
    f1.setNum(n);
    f1.setDen(d);
    return entrada;
}

bool Fraccion::operator>(const Fraccion& f1){
    return num*f1.den > f1.num*den;
}

void Fraccion::operator+=(const Fraccion& otra) {
    *this = *this + otra;// Hacer referencia a este objeto, cambiar el objeto el cual apunta, y se guarda en el objeto el cual apuntaste
    // obj1 += obj2     - >    obj1 es el que quiero cambiar, obj2 es el que llega como parámetro
}

Fraccion Fraccion::operator++() {
    setNum(++num);
    return *this;
}

Fraccion Fraccion::operator++(int) { // No se tiene que dar nombre al parámetro, así es la sintaxis
    Fraccion antes(num, den); // Fracción antes de editarla
    setNum(++num);
    return antes; // Esto hace que se modifique la fracción, pero como es post-incremento, regresas la anterior, y en la siguiente llamada a la fracción, estará editada
}

Fraccion Fraccion::operator--() {
    setNum(--num);
    return *this;
}

Fraccion Fraccion::operator--(int) {
    Fraccion antes(num, den);
    setNum(--num);
    return antes;
}

bool operator==(const Fraccion& f1, const Fraccion& f2) {
    if (f1.getNum() == f2.getNum() && f1.getDen() == f2.getDen()) {
        return true;
    } else {
        return false;
    }
}