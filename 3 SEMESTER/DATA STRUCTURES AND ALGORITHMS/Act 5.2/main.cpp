#include "HashTable.cpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

void cargarBitacora(string bitacora, HashTable &HT){
    ifstream archivo(bitacora);

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
                
                // Insertar a Hash Table
                 HT.insertItemChaining(puerto, linea);

                //cout << puerto << endl;
            }
        }
    }
    archivo.close();
}

int main() {
    /*
    En equipos de tres personas, hacer una aplicación que:

      Open the input file "bitacora.txt" and add all the entries in a hash table structure where the key 
      will be the port number and the values to save on the hash table are the total number of accesses and 
      the bitacora entries that access in that port, similar to the activity 3.4.
      In this activity the following is expected:
      • Investigate and implement a hash function that avoids as many collisions as possible.
      • Implement a suitable collision handling method (chaining, open addressing).
      • Print the 5 port numbers with the most accesses (already obtained in activity 3.4) in the hash table. 
        The results should match.

        13819 collisions para que no haya más de un puerto por índice
    */
    HashTable HT(3000);
    cargarBitacora("bitacora.txt", HT);

    ofstream salida("salida.txt"); // Abre el archivo de salida

    //HT.displayHash();
    //HT.displayKey(6486);
    HT.print5MostAccessedPorts(salida);
    salida.close(); // Cierra el archivo de salida

    cout << HT.getCollisions() << endl;
}