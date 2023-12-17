#include <iostream>
#include "DoubleLinkList.cpp"

using namespace std;

// Programa principal
int main() {
    // Implementar las operaciones CRUD (Create, Read (buscar), Update, Delete)
    DoubleLinkList DL;

    // Creamos una lista que contenga 2,0,4,1
    DL.Create(1);
    DL.Create(4);
    DL.Create(0);
    DL.Create(2);

    // Se muestra la lista
    DL.Display();

    // Como no existe el número en la lista debería regresar NULL
    cout << DL.Read(11) << endl;

    // Ahora editamos un valor de la lista, lo mostramos, y como si existe si nos devuelve un puntero el Read
    cout << endl;
    DL.Update(0,11);
    DL.Display();
    cout << DL.Read(11) << endl;

    // Ahora usamos Delete para borrar otro elemento de la lista
    cout << endl;
    DL.Delete(1);
    DL.Display();
    cout << DL.Read(1) << endl;

    return 0;
}