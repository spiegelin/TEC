#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "actividad_7.h"
using namespace std;

int main(){
    int N = 5;
    int count = 0;
    while (count < N) {
        int num; cout << "Ingrese el valor del numerador de la fracción " << count + 1 << ": "; cin >> num;
        int den; cout << "Ingrese el valor del denominador de la fracción " << count + 1 << ": "; cin >> den;

        if (den == 0) {
            cout << "Ingrese un denominador diferente a 0" << endl;
        } else {
            count++;
        }
    }
    return 0;
}