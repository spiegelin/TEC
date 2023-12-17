#pragma once
#include <iostream>
#include <list>

class HashTable {
    private:
        int capacity;
        std::list<int> *table;
        int collisions;
    public:
        // Constructor
        HashTable(int V);

        // Destructor
        ~HashTable();

        // Funciones
        bool checkPrime(int);
        int getPrime(int);
        int getCollisions() { return collisions; }

        void insertItemQuadratic(int);
        void insertItemChaining(int);
        void deleteItem1(int);
        void deleteItem2(int);
        int hashFunction(int);
        void displayHash();

        // Tarea
        int quadraticProbing(int, int);
};