#include "PQHeap.hpp"

// Constructor y Destructor
PQHeap::PQHeap() {}

PQHeap::~PQHeap() {}

// Heapify
// hT is the heap Tree
// i is the index of the largest element

void PQHeap::Heapify(std::vector<Node> &hT, int i) {// Función para convertir un vector en un heap. {
    int size = hT.size();

    // Find the largest among root, left child, and right child
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && hT[l].priority > hT[largest].priority) {
        largest = l;
    }
    if (r < size && hT[r].priority > hT[largest].priority) {
        largest = r;
    }

    // Swap and continue heapifying if root is not the largest
    if (largest != i) {
        std::swap(hT[i], hT[largest]);
        Heapify(hT, largest);
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// MaxHeap
void PQHeap::maxHeap() {
    int size = Heap.size();  // Obtener el tamaño del vector Heap

    for (int i = size / 2 - 1; i >= 0; i--) {
        Heapify(Heap, i);  // Llamar a Heapify para convertir en Max-Heap
    }
}


// Tarea
void PQHeap::Push(int data, int priority) {
    // Crear un nuevo nodo con los valores de data y priority
    Node newNode(data, priority);

    // Agregar el nuevo nodo al final del vector Heap
    Heap.push_back(newNode);

    // Aplicar la función maxHeap para convertir el vector en un Max-Heap
    maxHeap();
}

// Pop: Eliminar el elemento con mayor prioridad.
void PQHeap::Pop() {
    if (Empty()) {
        // Priority Queue está vacío
        std::cout << "La fila priorizada está vacía" << std::endl;
    }

    // Siguiendo la presentación
    // Paso 1: Seleccionar el elemento a eliminar (el que está en la raíz)
    // Lo tenemos en la posición 0 del vector Heap

    // Paso 2: Intercambiarlo con el último elemento
    int lastIndex = Heap.size() - 1;
    Node temp = Heap[0];
    Heap[0] = Heap[lastIndex];
    Heap[lastIndex] = temp;

    // Paso 3: Eliminar el último elemento
    Heap.pop_back();

    // Paso 4: Aplicar maxHeap para restaurar la propiedad del Max-Heap
    maxHeap();
}

// Top: Obtener el elemento con mayor prioridad.
int PQHeap::Top() {
    if (Empty()) {
        // Priority Queue está vacío
        std::cout << "La fila priorizada está vacía" << std::endl;
    }

    // El elemento con la mayor prioridad se encuentra en la raíz (posición 0)
    return Heap[0].data;
}

// Ambas funciones ya vienen integradas en la clase vector
// Empty: Comprobar si la fila priorizada está vacía.
bool PQHeap::Empty() {
    return Heap.empty();
}

// Size: Obtener la cantidad de elementos en la fila priorizada.
int PQHeap::Size() {
    return Heap.size();
}

// Extra
// Display: Mostrar todos los elementos del heap.
void PQHeap::Display() {
    if (Heap.empty()) {
        std::cout << "Priority Queue está vacío" << std::endl;
        return;
    }

    std::cout << "Valor(Prioridad): ";
    for (int i = 0; i < Heap.size(); ++i) {
        std::cout << Heap[i].data << "(" << Heap[i].priority << ")" << " ";
    }
    std::cout << std::endl;
}

// Delete Element: Eliminar un elemento del heap.
void PQHeap::deleteElement(int data) {
    int index = -1; // Inicializamos el índice a -1 para indicar que no se encontró el elemento

    // Buscar el índice del elemento con el valor 'data' en el heap
    for (int i = 0; i < Heap.size(); i++) {
        if (Heap[i].data == data) {
            index = i; // Encontramos el elemento, almacenamos su índice
            break;     // Salimos del bucle
        }
    }

    if (index == -1) {
        // El elemento no se encontró en el heap
        std::cout << "El elemento " << data << " no se encuentra en la fila priorizada." << std::endl;
        return;
    }

    // Intercambiar el elemento encontrado con el último elemento del heap
    std::swap(Heap[index], Heap[Heap.size() - 1]);

    // Eliminar el último elemento (que ahora contiene el elemento que queremos eliminar)
    Heap.pop_back();

    // Aplicar maxHeap para restaurar la propiedad del Max-Heap
    maxHeap();
}

void PQHeap::DisplayTree() {
    if (Heap.empty()) {
        std::cout << "Priority Queue está vacío" << std::endl;
        return;
    }

    int n = Heap.size();
    int h = 0;

    int index = n-1;
    while (index > 0) {
        index = (index - 1) / 2;
        h++;
    }

    int lvlNodes = 1;
    index = 0;

    for (int i = 0; i <= h; i++) {
        for (int j = 0; j < lvlNodes; j++) {
            if (index < n) {
                std::cout << "(" << Heap[index].data << ", " << Heap[index].priority << ") ";
                index++;
            }
        }
        std::cout << std::endl;
        lvlNodes = lvlNodes * 2;
    }

    /*
    int nivel_actual = 0;
    int elementos_en_nivel = 1;

    for (int i = 0; i < Heap.size(); i++) {
        if (i == elementos_en_nivel) {
            std::cout << std::endl;
            elementos_en_nivel = (elementos_en_nivel << 1) + 1;
            nivel_actual++;
        }

        // Imprime el elemento actual
        if (Heap[i].data != -1) {
            std::cout << "(" << Heap[i].data << ", " << Heap[i].priority << ") ";
        } else {
            std::cout << "( ) ";
        }
    }

    std::cout << std::endl;
    */
}
