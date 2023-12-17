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

    // isTree
    cout << "El grafo generado es un árbol: " << G.isTree(5,7) << endl;
    G.ResetVisited();

    cout << "Topological Sort: ";
    G.topologicalSort(); 
    cout << endl;
    G.ResetVisited();
    cout << endl << endl;
    
    // Bipartite Graph
    cout << "El DAG puede ser representado como bipartita: " << G.bipartiteGraph(0) << endl;
    G.ResetVisited();
    

    return 0;
}