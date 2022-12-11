#include <iostream>
using namespace std;

void total_pagar();
void clasifica(int num);
double calcula_volumen(double a, double b, double c);

int main(void) {
    // Programa 1
    total_pagar();

    // Programa 2
    int n;
    cout << "Números a clasificar: ";
    cin >> n;
    clasifica(n);

    // Programa 3
    int a, b, c;
    cout << "Ingresa a: "; cin >> a;
    cout << "Ingresa b: "; cin >> b;
    cout << "Ingresa c: "; cin >> c;

    cout << "Volumen: " << calcula_volumen(a,b,c);
}
void total_pagar(void) {
    double pago;
    double total;
    cout << "Total a pagar: ";
    cin >> pago;

    if (pago > 1000 && pago <= 2000) {
        total = pago - (pago * 0.12);
        cout << "Total a pagar final: " << total;
    } else if (pago > 2000){
        total = pago - (pago * 0.145);
        cout << "Total a pagar final: " << total;
    } else {
        cout << "Total final: " << pago;
    }
}

void clasifica(int num) {
    int arreglo[num];
    int pares = 0, impares = 0, ceros = 0;
    for (int i=0;i<num;i++) {
        cout<<"Número " << i + 1 << ": ";
        cin >> arreglo[i];

        if (arreglo[i] == 0){
            ceros++;
        } else if (arreglo[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }
    printf("Número de pares: %i, Número de impares: %i, Número de ceros: %i\n", pares, impares, ceros);
}

double calcula_volumen(double a, double b, double c) {
    double volumen = a * b * c;
    return volumen;
}