#include <iostream>
#include "Queue.hpp"

// Constructor y Destructor
Queue::Queue(int size) {
    N = size;
    Q = new Node[size];
    front = -1;
    rear = -1;
}

Queue::~Queue() {
    delete[] Q;
}

// CRUD
// Enqueue: Agregar elemento al final de la cola.
void Queue::Enqueue(int n) {
    if (isFull()) {
        std::cout << "Queue está lleno" << std::endl;
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;

        Q[rear].value = n;
    }
}

// Peek: Obtener el valor del frente de la cola sin removerlo
int Queue::Peek() {
    if (isEmpty()) {
        std::cout << "Queue está vacío" << std::endl;
        return -1;
    }
    return Q[front].value;
}


// Update: Actualizar el valor de un elemento de la cola
void Queue::Update(int oldValue, int newValue) {
    if (isEmpty()) {
        std::cout << "Queue está vacío" << std::endl;
        return;
    }

    for (int i = front; i <= rear; i++) {
        if (Q[i].value == oldValue) {
            Q[i].value = newValue;
            return;
        }
    }
}

// Dequeue: Remover elemento del frente de la cola.
Node* Queue::Dequeue() {
    if (isEmpty()) {
        std::cout << "Queue está vacío" << std::endl;
        return NULL;
    }

    Node *tmp = &Q[front];

    if (front >= rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    return tmp;
}


// Extras
// IsEmpty: Revisar si la cola está vacía
bool Queue::isEmpty() {
    if (front == -1) {
        return true;
    }
    return false;
}

// IsFull: Revisar si la cola está llena
bool Queue::isFull() {
    if (front == 0 && rear == N-1) {
        return true;
    }
    return false;
}

// Display: Imprimir los elementos de la cola
void Queue::Display() {
    if (isEmpty()) {
        std::cout << "Queue vacía" << std::endl;
    } else {
        std::cout << std::endl << "Front -> ";

        for (int i = front; i <= rear; i++) {
            std::cout << Q[i].value << " ";
        }

        std::cout << "<- Rear" << std::endl << std::endl;
    }
}