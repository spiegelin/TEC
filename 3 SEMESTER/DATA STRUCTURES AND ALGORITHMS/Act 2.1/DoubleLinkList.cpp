#include "DoubleLinkList.hpp"

// CRUD
// Create
void DoubleLinkList::Create(int value) {
    // Asignar un espacio de memoria al nuevo Nodo
    Node *aptNode = new Node;

    if (aptNode == NULL) {
        std::cout << "Error: memory could not be reserved. \n" << std::endl;
    }

    // Asignar un valor al nuevo Nodo
    aptNode -> data = value;

    // Apuntar el next al primer nodo
    aptNode -> next = Head;

    // Apuntar el previo a NULL
    aptNode -> prev = NULL;

    // Si la lista no está vacía, el prev del primer nodo al nodo nuevo
    if (Head != NULL) {
        Head -> prev = aptNode;
    }

    // Head a nodo Actual
    Head = aptNode;
    BubbleSort();
}

// Read
Node* DoubleLinkList::Read(int value) {
    Node* current = Head;

    while (current != NULL) {
        // Si se encuentra el valor, devuelve un puntero al nodo actual
        if (current->data == value) {
            return current; 
        }
        // Si no se encuentra se mueve el nodo al siguiente
        current = current->next;
    }

    // Si el valor no se encontró en la lista regresa NULL
    return NULL; 
}

// Update
void DoubleLinkList::Update(int oldValue, int newValue) {
    Node* current = Head;

    while (current != NULL) {
        // Si se encuentra el valor, actualiza el valor en el nodo actual
        if (current -> data == oldValue) {
            current -> data = newValue;
            BubbleSort();
            return;
        }
        // Si no se encuentra se mueve el nodo al siguiente
        current = current->next;
    }

    // El valor no se encontró en la lista
    std::cout << "Valor " << oldValue << " no se encuentra en la lista" << std::endl;
}

// Delete
void DoubleLinkList::Delete(int value) {
    Node* current = Head;

    while (current != NULL) {
        // Si se encuentra el valor, elimina el nodo actual
        if (current -> data == value) {
            // Verifica si el nodo actual es el primer nodo
            if (current == Head) {
                // Actualiza el head para apuntar al siguiente nodo
                Head = current -> next;
                // Y actualiza el previo a NULL
                if (Head != NULL) {
                    Head->prev = NULL;
                }
            } else {
                // Conecta el nodo anterior al siguiente nodo, omitiendo el nodo actual
                current -> prev -> next = current -> next;
                if (current -> next != NULL) {
                    // Actualiza el prev del siguiente nodo
                    current -> next -> prev = current -> prev;
                }
            }

            delete current;
            BubbleSort();
            return;
        }
        // Si no se encuentra se mueve el nodo al siguiente
        current = current->next;
    }

    // El valor no se encontró en la lista.
    std::cout << "Valor " << value << " no se encuentra en la lista." << std::endl;
}

// Extra
void DoubleLinkList::DeleteAll(){
    Node *aptNode = Head;

    while (aptNode != NULL) {
        // Head apunta al siguiente nodo y borra el nodo actual
        Head = Head -> next;
        delete aptNode;
        aptNode = Head;
    }
    std::cout << "Lista eliminada exitosamente" << std::endl;
}

// Display
void DoubleLinkList::Display(){
    Node* current = Head;

    // De inicio a fin
    while (current != NULL) {
        std::cout << current -> data << " -> ";

        if (current -> next == NULL) {
            break;
        } 
        current = current -> next;
    }
    std::cout << "NULL" << std::endl;

    /*
    while (current != NULL) {
        std::cout << current -> data << " -> ";

        if (current -> prev== NULL) {
            break;
        }
        current = current -> prev;
    }
    std::cout << "NULL" << std::endl;
    */
}

// Sort
void DoubleLinkList::BubbleSort() {
    bool swap;
    Node* current;
    Node* last = NULL;

    // La lista está vacía
    if (Head == NULL)
        return; 

    do {
        swap = false;
        current = Head;

        while (current -> next != last) {
            if (current -> data > current -> next -> data) {
                // Hacer el cambio de los nodos
                int tmp = current -> data;
                current -> data = current -> next -> data;
                current -> next -> data = tmp;
                swap = true;
            }
            current = current -> next;
        }
        last = current;
    } while (swap);
}
