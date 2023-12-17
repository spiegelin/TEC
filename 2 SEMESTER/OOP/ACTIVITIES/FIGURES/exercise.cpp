#include <iostream>
#include "Rectangulo.hpp"
#include "Circulo.hpp"
#include <vector>
using namespace std;

int main() 
{
  Circulo c1(1,1,5);
  Rectangulo r1(8,8,-2,5);

  cout << c1.dibuja() << endl;
  cout << "Se encuentra en las coordenadas x: " << c1.getX() << " y: " << c1.getY() << endl;
  cout << "Radio: " << c1.getRadio() << endl;
  cout << "---------------------------------------------------------------------------------" << endl;
  cout << r1.dibuja() << endl;
  cout << "Se encuentra en las coordenadas x: " << r1.getX() << " y: " << r1.getY() << endl;
  cout << "Ancho: " << r1.getAncho() << endl;
  cout << "Largo: " << r1.getLargo() << endl;

  vector<Figura*> figuritas;
  figuritas.push_back(new Circulo(3,3,2));
  figuritas.push_back(new Rectangulo(2,2,4,5));
  figuritas.push_back(new Rectangulo(6,6,5,9));
  figuritas.push_back(new Circulo(4,4,6));

  for (int i = 0; i < figuritas.size(); i++) {
    //cout << figuritas[i] -> dibuja() << endl;
    cout << *figuritas[i] << endl;
    cout << "El área es: " << figuritas[i] -> area() << endl;
    if (Circulo* ptrC = dynamic_cast<Circulo *>(figuritas[i])) {
      cout << "Y mi circunferencia es: " << ptrC->circunferencia() << endl;
    }
  }
/*
  for (auto &fig : figuritas) {
    cout << fig -> dibuja() << endl;
  }
  */
}
