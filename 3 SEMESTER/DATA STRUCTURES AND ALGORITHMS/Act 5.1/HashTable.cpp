#include <iostream>
#include <list>
#include "HashTable.hpp"

// Constructor
HashTable::HashTable(int V) {
    int size = getPrime(V);
    this->capacity = size;
    table = new std::list<int>[capacity];
    collisions = 0;
}

// Destructor
HashTable::~HashTable() {
    delete[] table;
    std::cout << "\nHashTable deleted\n" << std::endl;
}

// Funciones
// CheckPrime
bool HashTable::checkPrime(int n) {
    if (n == 0 || n == 1) {
        return false;
    }

    int sqr_root = sqrt(n);
    for (int i = 2; i <= sqr_root; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// GetPrime
int HashTable::getPrime(int n) {
    if (n % 2 == 0) {
        n++;
    }

    while (!checkPrime(n)) {
        n += 2;
    }
    return n;
}

// DeleteItem
void HashTable::deleteItem1(int key){
    int index = hashFunction(key);
    table[index].remove(key);
}

void HashTable::deleteItem2(int key){
    int index = hashFunction(key);

    std::list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == key) {
            break;
        }
    }

    if (i != table[index].end()) {
        table[index].erase(i);
    }
}

// DisplayHash
void HashTable::displayHash(){
    for (int i = 0; i < capacity; i++) {
        std::cout << "table[" << i << "]";

        for (auto x : table[i]) {
            std::cout << " --> " << x;
        }
        std::cout << std::endl;
    }
}

// InsertItem (Quadratic Probing)
void HashTable::insertItemQuadratic(int data) {
    int index = hashFunction(data);
    index = quadraticProbing(data, index);

     // Revisar colisiones
    if (!table[index].empty()) {
        collisions++;
    }

    while (!table[index].empty()) {
        index += 1;
    }

    table[index].push_back(data);
}

// InsertItem (Chaining)
void HashTable::insertItemChaining(int data) {
    int index = hashFunction(data);

    // Revisar colisiones
    if (!table[index].empty()) {
        collisions++;
    }

    table[index].push_back(data);
}

// Tarea
// Quadratic Probing
int HashTable::quadraticProbing(int key, int index) {
    int i = 1;
    const int c1 = 1;
    const int c2 = 1;
    const int maxAttempts = capacity;  // Evitar bucles infinitos

    while (table[index].size() > 0 && i < maxAttempts) {
        index = (index + c1 * i + c2 * i * i) % capacity;
        i++;
    }

    return index;
}


// HashFunction
/*
int HashTable::hashFunction(int key){
    return (key % capacity);
}
*/
/*
// HashFunction (Método de división)
int HashTable::hashFunction(int key) {
    const int prime = 31;  // A prime number to reduce collisions

    // Use the modulo operation to map the key to a slot in the hash table
    int index = key % capacity;

    // Apply additional operations (e.g., multiply by a prime number) to further mix the bits
    index = (index * prime) % capacity;

    return index;
}
*/

// HashFunction (Método de multiplicación)
int HashTable::hashFunction(int key) {
    double A = (sqrt(5) - 1) / 2;  // Usar un tipo de dato double
    int index = floor(capacity * (key * A - floor(key * A)));
    return index;
}

