#include <iostream>
#include "PQHeap.cpp"

using namespace std;

// Priority Queue using Max Heap

int main() {
    // Crear la fila de prioridad
    PQHeap PQH;
    PQH.Display();
    PQH.DisplayTree();
    cout << endl;

    
    PQH.Push(5, 1);
    PQH.Push(2, 3);
    PQH.Push(8, 4);
    PQH.Push(1, 2);
    PQH.Push(7, 5);
    
   /*
    PQH.Push(5, 5);
    PQH.Push(2, 2);
    PQH.Push(8, 8);
    PQH.Push(1, 1);
    PQH.Push(7, 8);
    // 8,7,5,2,1
    */

    // Debería verse así por prioridad:
    // 7, 8, 2, 5, 1

    // Se muestra la cola de prioridad
    PQH.Display();
    PQH.DisplayTree();
    cout << "Tamaño de la fila de prioridad: " << PQH.Size() << endl;

    // Top
    cout << "El elemento con mayor prioridad es: " << PQH.Top() << endl;
    cout << endl;

    // Pop (eliminar el elemento de mayor prioridad)
    PQH.Pop();
    cout << "El nuevo elemento con mayor prioridad es: " << PQH.Top() << endl;
    PQH.Display();
    PQH.DisplayTree();
    cout << endl;

    // Agregamos dos elementos 
    PQH.Push(0, 6);
    PQH.Push(100, 7);
    PQH.Display();
    PQH.DisplayTree();
    cout << "Tamaño de la fila de prioridad: " << PQH.Size() << endl;
    cout << endl;

    // Se elimina el elemento con valor 2 
    PQH.deleteElement(2);
    PQH.Display();
    PQH.DisplayTree();
}