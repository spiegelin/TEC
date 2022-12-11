#include <iostream>
#include <cmath> 

using namespace std; //para no poner std::cout o std::endl

int main(void){ 
    double datos[10];
    datos[10] = 25.4;

    for (int i = 0; i <= 9; i++) {
        datos[i] = i*i;
        cout<< " "<<datos[i];
    }
}