#include <iostream>
#include "HashTable.cpp"

using namespace std;

int main()
{
    /*
    - Individually, create a Hash table class with the variables table size, fixed-size lists or int array 
      (as applicable).
    - You must propose a hash function (that avoids collisions as best as possible) using chaining 
      (list array) and an open address collision resolution: quadratic probing (int array).
    - Test each test case for each collision resolution method through the insert() function.
    */
   int data[] = {231, 321, 212, 321, 433, 262, 845, 123, 341, 234};

   int size = sizeof(data)/sizeof(data[0]);

   HashTable h(size);
   HashTable t(size);

    cout << "Hash Table usando Quadratic Probing" << endl;
    for (int i = 0; i < size; i++) {
         h.insertItemQuadratic(data[i]);
    }
    h.displayHash();
    cout << "Colisiones: " << h.getCollisions() << endl;

    cout << "\nHash Table usando Chaining" << endl;
    for (int i = 0; i < size; i++) {
         t.insertItemChaining(data[i]);
    }
    t.displayHash();
    cout << "Colisiones: " << t.getCollisions() << endl;

    cout << "\nDelete element 231 (Quadratic Probing)\n";
    h.deleteItem1(231);
    h.displayHash();

    cout << "\nDelete element 231 (Chaining)\n";
    t.deleteItem1(231);
    t.displayHash();
}