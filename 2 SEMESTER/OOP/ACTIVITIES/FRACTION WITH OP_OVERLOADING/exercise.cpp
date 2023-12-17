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
}

