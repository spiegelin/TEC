#include <iostream>
#include <vector>
#include "BST.cpp"

using namespace std;

int main() {

    // Crear y llenar BST
    BST A;

    vector<int> v;
    v.push_back(50);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(70);
    v.push_back(60);
    v.push_back(80);
    for (int i = 0; i < v.size(); i++) {
        A.Insert(v[i]);
    }

    // Visit
    A.visit(1);
    A.visit(2);
    A.visit(3);
    A.visit(4);

    // Height
    cout << "The Height of the BST is " << A.height() << endl;

    // Ancestors
    A.ancestors(70);
    cout << endl;

    A.ancestors(80);
    cout << endl;

    // What level am I?
    cout << "El valor 40 se encuentra en la posición " << A.whatlevelamI(40) << endl;
    cout << "El valor 50 se encuentra en la posición " << A.whatlevelamI(50) << endl;

    // Delete Node
    int value = 50;
    A.DeleteNode(value);
    A.Preorder();
}
