#include "Fraccion.hpp"
using namespace std;

int main() 
{
  
  Fraccion f1,f2;
  cout << "Ingresa numerador y denominador separados por un espacio: ";
  cin >> f1;
  cout << "Ingresa numerador y denominador separados por un espacio: ";
  cin >> f2;

  cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
  cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;
  cout << f1 << " > " << f2 << " = " << (f1 > f2) << endl;
  cout << endl;

  Fraccion f5(1, 5);
  cout << "Fracción: " << f5 << endl;
  cout << "Preincremento ++: " << ++f5 << endl;
  cout << "Postincremento ++: " << f5++ << endl;
  cout << "Fracción actual: " << f5 << endl;
  cout << endl;

  Fraccion f7(2, 3);
  cout << "Fracción: " << f7 << endl;
  cout << "Preincremento --: " << --f7 << endl;
  cout << "Postincremento --: " << f7-- << endl;
  cout << "Fracción actual: " << f7 << endl;
  cout << endl;

  Fraccion f6(1,2);
  Fraccion f0 = f5; // Para poder imprimir el valor anterior de f6
  f5+=f6; // Probamos el operador sobrecargado
  cout << f0 << " += " << f6 << " = " << f5 << endl;
  cout << endl;

  Fraccion f8(5,2);
  Fraccion f9(5,2);
  cout << "Fracción 1: " << f8 << endl;
  cout << "Fracción 2: " << f9 << endl;
  cout << f8 << " == " << f9 << " -> " << (f8 == f9) << endl;
}