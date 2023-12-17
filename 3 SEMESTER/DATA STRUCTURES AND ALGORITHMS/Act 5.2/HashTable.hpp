#pragma once
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <fstream>

class HashTable {
    private:
        int capacity;
        std::list<std::string> *table;
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
        void insertItemChaining(int, std::string);
        void deleteItem1(int);
        int hashFunction(int);
        void displayHash();
        void displayKey(int);
        std::list<std::pair<int, int> > find5MostAccessedPorts();
        void print5MostAccessedPorts(std::ofstream&);
        std::string getPort(int);
};