#include <iostream>

using namespace std;

// Definición de Funciones
int sumaAlterativa(int);
int sumaRecursiva(int);
int sumaDirecta(int);

// Programa principal
int main() {
    // Casos prueba
    int n1,n2,n3,n4,n5;

    n1 = 100;
    n2 = 7.9;
    n3 = 1;
    n4 = 7;
    n5 = -1; // Extra para observar que sucede con cada función en caso de un número negativo

    // Método Iterativo
    // Complejidad: O(n)
    cout << "Método Iterativo: " << endl;
    cout << sumaAlterativa(n1) << endl;
    cout << sumaAlterativa(n2) << endl;
    cout << sumaAlterativa(n3) << endl;
    cout << sumaAlterativa(n4) << endl;
    cout << sumaAlterativa(n5) << endl;
    cout << endl;

    // Método Recursivo
    // Complejidad: O(n)
    cout << "Método Recursivo: " << endl;
    cout << sumaRecursiva(n1) << endl;
    cout << sumaRecursiva(n2) << endl;
    cout << sumaRecursiva(n3) << endl;
    cout << sumaRecursiva(n4) << endl; 
    //cout << sumaRecursiva(n5) << endl; // -1 en método recursivo causa segmentation fault
    cout << endl;

    // Método Matemático
    // Complejidad: O(1)
    cout << "Método Matemático: " << endl;
    cout << sumaDirecta(n1) << endl;
    cout << sumaDirecta(n2) << endl;
    cout << sumaDirecta(n3) << endl;
    cout << sumaDirecta(n4) << endl;
    cout << sumaDirecta(n5) << endl;
}

// Funciones
int sumaAlterativa(int n) {
    // Calcula la sumatoria de 1 hasta n con un metodo iterativo.
    // Complejidad: O(n)
    int suma = 0;
    for (int i = 1; i <= n; i++) {
        suma = suma + i;
    }
    return suma;
}

int sumaRecursiva(int n) {
    // Calcula la sumatoria de 1 hasta n con un metodo recursivo.
    // Complejidad: O(n)
    if (n == 1) { // Caso base
        return 1;
    } else { // Caso recursivo
        return n + sumaRecursiva(n-1);
    }
}

int sumaDirecta(int n) {
    // Calcula la sumatoria de 1 hasta n con un metodo matemático directo.
    // n(n+1) / 2
    // Complejidad: O(1)
    return (n * (n + 1)) / 2;
}