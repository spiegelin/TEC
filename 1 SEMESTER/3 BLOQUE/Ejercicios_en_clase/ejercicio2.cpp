#include <iostream>
using namespace std;

int main(void) {
    int arreglo[5];
    // Método para llenar el arreglo
    for (int i = 0; i<5; i++){
        printf("Dame el valor de la posición %d: ", i+1);
        cin>>arreglo[i];
    }

    // Método para recorrer el arreglo
    for (int i = 0; i<sizeof(arreglo)/sizeof(int); i++){
        printf("El valor en la posición %d es %d\n", i+1, arreglo);
    }
}