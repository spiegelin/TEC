#include <iostream>
#include "PQueue.cpp"

using namespace std;

// Queue follows the First In First Out (FIFO) rule - the item that goes in first is the item that comes out 
// first.
// Enqueue: Add an element to the end of the queue.
// Dequeue: Remove an element from the front of the queue.
// IsEmpty: Check if the queue is empty.
// IsFull: Check if the queue is full.
// Peek: Get the value of the front of the queue without removing it.

// Programa principal
int main() {
    // Crear un Queue de tamaño 6
    PQueue PQ(6);

    // Verificar que esté vacío
    PQ.Display();

    // Peek (ver el frente, en este caso da -1 porque no hay datos)
    cout << endl;
    int n = PQ.Peek();
    cout << "El frente es: " << n << endl;

    // Rellenarlo
    PQ.Enqueue(1, 2);
    PQ.Enqueue(2, 1);
    PQ.Enqueue(3, 4);
    PQ.Enqueue(4, 3);

    // Mostrar el Queue
    cout << endl;
    PQ.Display();

    // Eliminar datos
    PQ.Dequeue();
    PQ.Dequeue();

    // Observar cambios
    PQ.Display();

    // Agregar
    PQ.Enqueue(10, 5);
    PQ.Display();

    // Peek (ver el frente)
    n = PQ.Peek();
    cout << "El valor con mayor prioridad es: " << n << endl;

    // Update
    PQ.Update(10,12);
    std::cout << std::endl;
    std::cout << "Valor(Prioridad) en índice 2: ";
    PQ.Display(2);
    PQ.Display();

    // Vaciar
    while (!PQ.isEmpty()) {
        PQ.Dequeue();
    }

    return 0;
}