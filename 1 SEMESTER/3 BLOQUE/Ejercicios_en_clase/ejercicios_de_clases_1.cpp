#include <iostream>
#include <stdlib.h>
using namespace std;

class Figura {
    public:
        Figura(float, float);
        float perimetro();
        float area();
    private:
        float base;
        float altura;
};

Figura::Figura(float b, float h){
    base = b;
    altura = h;
}

float Figura::area(){
    return base * altura;
}

float Figura::perimetro(){
    return (2*base) + (2*altura);
}

int main(){
    float altura, base;
    printf("Dame el valor de la altura de la Fig.1: "); cin >> altura;
    printf("\nDame el valor de la base de la Fig.1: "); cin >> base;
    Figura rectangulo(altura,base); // Base y altura como atributos

    printf("\nDame el valor de la altura de la Fig.2: "); cin >> altura;
    printf("\nDame el valor de la base de la Fig.2: "); cin >> base;
    Figura cuadrado(altura,base);

    printf("\nPerimetro: %.2f, Área: %.2f\n", rectangulo.perimetro(), rectangulo.area()); 
    printf("Perimetro: %.2f, Área: %.2f\n", cuadrado.perimetro(), cuadrado.area());
}