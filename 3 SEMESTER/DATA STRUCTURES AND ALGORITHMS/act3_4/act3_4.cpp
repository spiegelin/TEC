#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "vector"

#include "BST.h"

using namespace std;
void crearODLL(string bitacora, BST* bst){
    ifstream archivo(bitacora);
    ////ofstream salida("salida.txt"); // Abre el archivo de salida
    //// archivo.is_open() && salida.is_open()

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            //cout <<linea<<endl;
            istringstream iss(linea);
            string mes;
            string dia;
            string hora;
            string ipAndPort;
            string error;
            
            iss >> mes >> dia >> hora >> ipAndPort;

            size_t colonPos = ipAndPort.find(':');
            if (colonPos != string::npos) {
                int puerto = stoi(ipAndPort.substr(colonPos + 1)); 
                //cout << "IP: " << ip << ", Puerto: " << puerto << endl;

                bst->Insert(puerto, linea);
                //cout << puerto << linea << endl;
                
                // Imprimir en consola
                //cout << puerto << " " << linea << endl;

                // Guardar en el archivo de salida
                ////cout << puerto << " " << linea << endl;

                // Guardar en el archivo de salida
                ////salida << puerto << " " << linea << endl;
            }    
        }
       //// salida.close(); // Cierra el archivo de salida cuando se haya terminado de escribir 
    }
}

int main(){

    BST bst;
    crearODLL("bitacora.txt", &bst);

    //bst.BFT();
    cout << endl;

    //bst.PreOrder();
    cout << endl;

    ofstream salida("salida.txt"); // Abre el archivo de salida

    bst.FindTop5Nodes();

    bst.printTop5Nodes(salida);

    salida.close(); // Cierra el archivo de salida cuando hayas terminado de escribir en él
    


    return 0;
}