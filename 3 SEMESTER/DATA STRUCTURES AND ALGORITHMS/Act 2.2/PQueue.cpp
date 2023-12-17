#include <iostream>
#include "PQueue.hpp"

// Constructor y Destructor
PQueue::PQueue(int size) {
    N = size;
    PQ = new Node[size];
    NumNodes = -1;
}

PQueue::~PQueue() {
    delete[] PQ;
}

// CRUD
// Enqueue: Agregar elemento al queue
void PQueue::Enqueue(int n, int priority) {
    if (isFull()) {
        std::cout << "Queue está lleno" << std::endl;
        return;
    } 
    // Incrementar tamaño
    NumNodes++;

    // Insertar elemento
    PQ[NumNodes].value = n;
    PQ[NumNodes].priority = priority;
}

// Peek: Obtener el valor del queue con mayor prioridad sin removerlo
int PQueue::Peek() {
    if (isEmpty()) {
        std::cout << "Queue está vacío" << std::endl;
        return -1;
    }

    // Encontrar el elemento de mayor prioridad
    int max = PQ[0].priority;
    int idx = 0;

    for (int i = 0; i <= NumNodes; i++) {
        if (PQ[i].priority > max) {
            max = PQ[i].priority;
            idx = i;
        }
    }

    // Retornar el valor
    return PQ[idx].value;
}

// Update: Actualizar el valor de un elemento de la cola de prioridad, manteniendo la prioridad
void PQueue::Update(int oldValue, int newValue) {
    if (isEmpty()) {
        std::cout << "Queue está vacío" << std::endl;
        return;
    }

    // Encontrar el elemento de mayor prioridad
    int max = PQ[0].priority;
    int idx = 0;

    for (int i = 0; i <= NumNodes; i++) {
        if (PQ[i].priority > max) {
            max = PQ[i].priority;
            idx = i;
        }
    }

    // Actualizar el valor
    PQ[idx].value = newValue;
}

// Dequeue: Remover elemento de mayor prioridad en el queue
Node* PQueue::Dequeue() {
    if (isEmpty()) {
        std::cout << "Queue está vacío" << std::endl;
        return NULL;
    }

    // Encontrar el elemento de mayor prioridad
    int max = PQ[0].priority;
    int idx = 0;

    for (int i = 0; i <= NumNodes; i++) {
        if (PQ[i].priority > max) {
            max = PQ[i].priority;
            idx = i;
        }
    }

    // Remover el elemento
    Node* tmp = new Node;
    tmp -> value = PQ[idx].value;
    tmp -> priority = PQ[idx].priority;

    for (int i = idx; i < NumNodes; i++) {
        PQ[i] = PQ[i+1];
    }

    // Decrementar tamaño
    NumNodes--;

    // Retornar el valor
    return tmp;
}


// Extras
// IsEmpty: Revisar si la cola está vacía
bool PQueue::isEmpty() {
    if (NumNodes == -1) {
        return true;
    }
    return false;
}

// IsFull: Revisar si la cola está llena
bool PQueue::isFull() {
    if (NumNodes == N-1) {
        return true;
    }
    return false;
}

// Imprime 1 solo elemento con el índice
void PQueue::Display(int idx) {
    std::cout << PQ[idx].value;
    std::cout << "(" << PQ[idx].priority << ")\n\n";
}

// Display: Imprimir todos los elementos de la cola
void PQueue::Display() {
    std::cout << "Valor(Prioridad): ";

    for (int i = 0; i <= NumNodes; i++) {
        std::cout << PQ[i].value;
        std::cout << "(" << PQ[i].priority << ")" << " ";
    }
    std::cout << std::endl << std::endl;
}
