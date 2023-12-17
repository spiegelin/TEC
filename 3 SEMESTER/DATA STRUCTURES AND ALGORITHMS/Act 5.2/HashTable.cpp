#include "HashTable.hpp"
#include <iostream>
#include <list>
#include <fstream>

// Constructor
HashTable::HashTable(int V) {
    int size = getPrime(V);
    this->capacity = size;
    table = new std::list<std::string>[capacity];
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

// DeleteItem (Elimina el último elemento de la lista)
void HashTable::deleteItem1(int key){
    int index = hashFunction(key);
    table[index].pop_back();
}


// DisplayHash
void HashTable::displayHash(){
    for (int i = 0; i < capacity; i++) {

        std::string port = getPort(i);// Todo este proceso es para poder imprimir el puerto como Port[puerto]
        
        std::cout << "Port[" << port << "]";

        // Cuenta el número de accesos y los agrega a la lista
        /*
        int accesses = 0;
        for (auto j : table[i]) {
            accesses++;
        }
        table[i].push_front(std::to_string(accesses));
        */


        // Imprime el resto de la lista
        for (auto x : table[i]) {
            std::cout << " --> " << x << std::endl;
        }
        std::cout << std::endl;
    }
}


// InsertItem (Chaining)
void HashTable::insertItemChaining(int data, std::string line) {
    int index = hashFunction(data);
    int accesses = table[index].size();

    // Revisar colisiones (Colisiones totales)
    if (!table[index].empty()) {
        collisions++;
        table[index].pop_front();
    }

    table[index].push_back(line);
    table[index].push_front(std::to_string(accesses));
}

// HashFunction (Método de división)
int HashTable::hashFunction(int key) {
    const int prime = 31;  // A prime number to reduce collisions

    // Use the modulo operation to map the key to a slot in the hash table
    int index = key % capacity;

    // Apply additional operations (e.g., multiply by a prime number) to further mix the bits
    index = (index * prime) % capacity;

    return index;
}

// Display Key
void HashTable::displayKey(int key) {
   //int key2 = key;
    int index = hashFunction(key);

    std::cout << "Port[" << key << "]";
    for (auto x : table[index]) {
            std::cout << " --> " << x << std::endl;
        }
    std::cout << std::endl;
}

// GetPort
std::string HashTable::getPort(int index) {
    auto line = table[index].back();
    std::size_t posColon = line.find_last_of(":");  // Encuentra la última aparición del carácter ":"
    std::size_t posSpace = line.find_first_of(" "); // Encuentra la primera aparición del carácter " "

    // Extrae la secuencia de dígitos entre el espacio y los dos puntos como puerto
    std::string port = line.substr(posColon + 1, posSpace + 1);
    
    
    return port;
}

// Find 5 port numbers and print all the accesses
std::list<std::pair<int, int> > HashTable::find5MostAccessedPorts() {
    std::list<std::pair<int, int> > list;

    for (int i = 0; i < capacity; i++) {
        int accesses = 0;
        for (auto j : table[i]) {
            accesses++;
        }
        list.push_back(std::make_pair(accesses, i));
    }

    list.sort();
    list.reverse();

    return list;
}

void HashTable::print5MostAccessedPorts(std::ofstream& salida) {
    std::list<std::pair<int, int> > list = find5MostAccessedPorts();

    int count = 0;
    for (auto i : list) {
        int port = stoi(getPort(i.second));

        int index = hashFunction(port);

        std::cout << "Port[" << port << "]";
        salida << "Port[" << port << "]";
        for (auto x : table[index]) {
                std::cout << " --> " << x << std::endl;
                salida << " --> " << x << std::endl;
            }
        std::cout << std::endl;
        salida << std::endl;

        count++;
        if (count == 5) {
            break;
        }
    }
}