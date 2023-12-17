#include <iostream>
#include "Queue.cpp"

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
    Queue Q(6);

    // Verificar que esté vacío
    Q.Display();

    // Peek (ver el frente, en este caso da -1 porque no hay datos)
    cout << endl;
    int n = Q.Peek();
    cout << "El frente es: " << n << endl;

    // Rellenarlo
    Q.Enqueue(1);
    Q.Enqueue(2);
    Q.Enqueue(3);
    Q.Enqueue(4);

    // Mostrar el Queue
    Q.Display();

    // Eliminar datos
    Q.Dequeue();
    Q.Dequeue();

    // Observar cambios
    Q.Display();

    // Agregar
    Q.Enqueue(10);
    Q.Display();

    // Peek (ver el frente)
    n = Q.Peek();
    cout << "El frente es: " << n << endl;

    // Update
    Q.Update(3,12);
    Q.Display();

    // Vaciar
    while (!Q.isEmpty()) {
        cout << Q.Dequeue() -> value << " " << endl;
    }

    return 0;
}