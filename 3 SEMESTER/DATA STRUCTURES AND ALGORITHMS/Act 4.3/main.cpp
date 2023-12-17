#include "Graph.cpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;


void ipStringToArray(string ipString, int *arr) {
    istringstream iss(ipString);
    string octet;

    for (int i = 0; i < 4; ++i) {
        getline(iss, octet, '.');
        //cout << stoi(octet) << " ";
        arr[i] = stoi(octet);
    }

    //cout << endl;   
}

void addConnections(int *arr, Graph &g){
    for (int i = 0; i < 3; ++i) {
        if (!g.alreadyConnected(arr[i], arr[i+1])) {
            g.addEdge(arr[i], arr[i+1]);
            g.addOutDegree(arr[i]);
            //cout << arr[i] << " ";
        }
    }

    //cout << endl;
}

void cargarBitacora(string bitacora, Graph &g){
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

            int arr[4];
            ipStringToArray(ipAndPort, arr);
            addConnections(arr, g);
        }
    }
}

void showLogsTopOutDegree(int vertex, Graph &g, string bitacora){
    cout << "Logs of the top Out Degree Node: " << vertex << endl;
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

            int arr[4];
            ipStringToArray(ipAndPort, arr);
            for (int i = 0; i < 4; ++i) {
                if (arr[i] == vertex) {
                    cout << linea << endl;
                }
            }
        }
    }
}

int main(){
    Graph g(1000);
    cargarBitacora("bitacora.txt", g);

    //g.printOutDegree();

    g.printTop10OutDegrees();

    int vertex = g.getTopOutDegree();

    showLogsTopOutDegree(vertex, g, "bitacora.txt");

    return 0;
}