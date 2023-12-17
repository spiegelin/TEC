#pragma once
#include <iostream>
#include <vector>

struct Node {
    int data;
    int priority;

    Node(int data, int priority) : data(data), priority(priority) {}
};

class PQHeap {
    private:
        std::vector<Node> Heap; 
        void Heapify(std::vector<Node>&, int); // Función para convertir un vector en un heap.
    public:
        // Constructor y Destructor
        PQHeap();  
        ~PQHeap();       

        // Tarea
        void Push(int, int); // Agregar un elemento a la fila priorizada.
        void Pop(); // Eliminar el elemento con mayor prioridad.
        int Top(); // Obtener el elemento con mayor prioridad.
        bool Empty(); // Comprobar si la fila priorizada está vacía.
        int Size(); // Obtener la cantidad de elementos en la fila priorizada.

        // Extra
        void Display(); // Mostrar todos los elementos del heap.
        void deleteElement(int); // Eliminar un elemento del heap.

        // Heap
        void maxHeap(); // Función para convertir un heap en un max heap.
        void DisplayTree();
};
