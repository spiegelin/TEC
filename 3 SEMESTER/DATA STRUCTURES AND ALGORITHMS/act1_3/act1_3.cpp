//Pablo Heredia Sahagún A0163703

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "RegistroB.h"
using namespace std;



vector<RegistroB> crearArray(string bitacora){
    vector<RegistroB> bitacoras;
    ifstream archivo(bitacora);

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            istringstream iss(linea);
            string mes;
            int dia;
            string hora;
            string ip;
            string error;
            int numes;
            
            iss >> mes >> dia >> hora >> ip;
            getline(iss, error);
            
            if (mes == "Jan"){                          
                numes = 1;
            }else if(mes == "Feb"){
                numes = 2;
            }else if(mes == "Mar"){
                numes = 3;
            }else if(mes == "Apr"){
                numes = 4;
            }else if(mes == "May"){
                numes = 5;
            }else if(mes == "Jun"){
                numes = 6;
            }else if(mes == "Jul"){
                numes = 7;
            }else if(mes == "Aug"){
                numes = 8;
            }else if(mes == "Sep"){
                numes = 9;
            }else if(mes == "Oct"){
                numes = 10;
            }else if(mes == "Nov"){
                numes = 11;
            }else if(mes == "Dec"){
                numes = 12;
            }

            RegistroB registro(mes, numes,dia, hora, ip, error);
            bitacoras.push_back(registro);
        }
        archivo.close();

        return bitacoras;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
        return bitacoras;
    }
}

void merge(vector<RegistroB> &A, int p, int q, int r){

    const int n1 = q-p+1;
    const int n2 = r-q;

    RegistroB* L = new RegistroB[n1];
    RegistroB* R = new RegistroB[n2];


    for (int i = 0;i<n1;i++){
        L[i] = A[p+i];
    }
    for (int j = 0;j<n2;j++){
        R[j] = A[q+1+j]; 
    }

    int i=0, j=0, k=p;

    while(i<n1 && j<n2){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i< n1){
        A[k] = L[i];
        i++;
        k++;
    }

    while(j<n2){
        A[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;

}

void mergeSort(vector<RegistroB> &A, int p, int r){

    if (p>=r){
        return;
    }
    int q = (p+r)/2;
    mergeSort(A, p, q);
    mergeSort(A, q+1, r);
    return merge(A, p, q, r);

}


int busqSecuencial_abajo(vector<RegistroB> &A, int mes, int dia){
    int n = A.size();
    for (int i=0; i<n; i++){
        if (A[i].getNumes() >= mes){
            if  (A[i].getDia() >= dia){
                return i;
            }
        }
    }

    return -1;
}


int busqSecuencial_arriba(vector<RegistroB> &A, int mes, int dia){
    int n = A.size();
    for (int j=n-1; j>=0; j--){
        if (A[j].getNumes() <= mes){
            if  (A[j].getDia() <= dia){
                return j;
            }
        }
    }

    return -1;
}


int main() {
    vector<RegistroB> bitacoras = crearArray("bitacora.txt");

    mergeSort(bitacoras, 0, bitacoras.size());

    int mes_primero, dia_primero;
    int mes_segundo, dia_segundo;

    cout << "Ingrese el primer mes: ";
    cin >> mes_primero;
    cout << "Ingrese el primer día: ";
    cin >> dia_primero;

    cout << "Ingrese el segundo mes: ";
    cin >> mes_segundo;
    cout << "Ingrese el segundo día: ";
    cin >> dia_segundo;

    int indice_abajo = busqSecuencial_abajo(bitacoras, mes_primero,dia_primero);
    int indice_arriba = busqSecuencial_arriba(bitacoras, mes_segundo,dia_segundo);

    cout <<indice_abajo << indice_arriba;
    
    ofstream txtsalida("salida.txt");

    for (int i = indice_abajo; i < indice_arriba && i < bitacoras.size(); ++i) {
    RegistroB registro = bitacoras[i];
    cout << registro.getMes() << " " << registro.getDia() << " " << registro.getHora() << " " << registro.getIP()<< registro.getError() << endl;
    txtsalida << registro.getMes() << " " << registro.getDia() << " " << registro.getHora() << " " << registro.getIP() << registro.getError() << endl;
    }


    txtsalida.close();
/*
    for (RegistroB registro : bitacoras) {
        cout << "Mes: " << registro.getMes() << ", Día: " << registro.getDia()
             << ", Hora: " << registro.getHora() << ", IP: " << registro.getIP()
             << ", Error: " << registro.getError() << endl;
    }
*/
    return 0;
}