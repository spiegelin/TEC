#include <iostream>
#include "Graph.cpp"

using namespace std;

int main() {
    // Crear Graph
    Graph G(5,7);

    // Printear Lista de Adyacencia y Matriz de Adyacencia en 0
   // G.printGraphL();
  //  cout << endl;
  //  G.printGraphM();

    /* Tarea */
    // Load Graph
    cout << "Conexiones obtenidas en Load Graph:" << endl;
    G.loadGraph(5,7);
    cout << endl;

    cout << "Lista de Adyacencia:";
    G.printGraphL();
    cout << endl;

    cout << "Matriz de Adyacencia:" << endl;
    G.printGraphM();
    cout << endl;

    // DFS
    cout << "Función DFS Lista Adyacente: ";
    G.DFSList(0); cout << endl;
    G.ResetVisited();

    cout << "Función DFS Matriz Adyacente: ";
    G.DFSMatrix(0); cout << endl;
    G.ResetVisited();
    cout << endl << endl;


    // BFS
    cout << "Función BFS Lista Adyacente: ";
    G.BFSList(0); cout << endl;
    G.ResetVisited();

    cout << "Función BFS Matriz Adyacente: ";
    G.BFSMatrix(0); cout << endl;
    G.ResetVisited();
    cout << endl;
    

    return 0;
}