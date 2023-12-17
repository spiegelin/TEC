#include "Graph.h"

using namespace std;

Graph::Graph(int vertices){
    
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    outdegree = new int[vertices]();
    adjMatrix = vector<vector<bool> >(vertices, vector<bool>(vertices, false));

}

void Graph::printAdjList(){
    for (int i = 0; i< this->numVertices;i++){
        cout << "\n Vertex " << i << ":";

        for (auto x : this->adjLists[i]){
            cout << "-> " << x;
        }
        cout << endl;
    }
}

void Graph::printAdjMatrix(){
    for (int i = 0; i < this->numVertices; i++){
        for (int j = 0; j < this->numVertices; j++){
            cout << this->adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout <<endl;
}


bool Graph::alreadyConnected(int src, int dest){
    if (this->adjMatrix[src][dest]){
        return true;
    }
    return false;
}

void Graph::addEdgeList(int src, int dest){
    adjLists[src].push_back(dest);
    
}

void Graph::addEdgeMatrix(int src, int dest){
    this->adjMatrix[src][dest] = true;
    
}

void Graph::addEdge(int src, int dest){
    addEdgeList(src, dest);
    addEdgeMatrix(src, dest);
}


void Graph::addOutDegree(int src){
    this->outdegree[src]++;
}


int Graph::outDegreeNode(int src){
    return this->outdegree[src];
}

void Graph::printOutDegree(){
    for (int i = 0; i < this->numVertices; i++){
        if (this->outdegree[i] != 0){
            cout << "Vertice " << i << " tiene grado de salida: " << this->outDegreeNode(i) << endl;
        }
    }
}

void Graph::outDegreeNodeList(int src){
    int outList = 0;
    for (auto x : this->adjLists[src]){
        outList++;
    }
    cout << "El vertice " << src << " tiene grado de salida: " << outList << endl;
}

void Graph::outDegreeNodeMatrix(int src){
    int outMatrix = 0;
    for (int i = 0; i < this->numVertices; i++){
        if (this->adjMatrix[src][i]){
            outMatrix++;
        }
    }
    cout << "El vertice " << src << " tiene grado de salida: " << outMatrix << endl;
}

int Graph::getTopOutDegree(){
    getTop10OutDegrees();

    return nodeOutdegrees[0].first;
}

void Graph::getTop10OutDegrees(){
    // Crear un vector de pares (índice, outdegree)
        nodeOutdegrees.clear();  // Limpiar el vector antes de cada impresión

        for (int i = 0; i < numVertices; ++i) {
            nodeOutdegrees.push_back(make_pair(i, outdegree[i]));
        }

        // Ordenar el vector en función de los outdegrees en orden descendente
        sort(nodeOutdegrees.begin(), nodeOutdegrees.end(),[](const auto& lhs, const auto& rhs) {
            return lhs.second > rhs.second;
                  });
}

void Graph::printTop10OutDegrees() {
        
        getTop10OutDegrees();

        // Imprimir los topN nodos con mayor outdegree
        for (int i = 0; i < 10; ++i) {
            cout << "Nodo " << nodeOutdegrees[i].first << " con outdegree: " << nodeOutdegrees[i].second << endl;
        }
    }


void Graph::sortAdjList(){
    //esta funciona la hice para evitar ambiguedades al hacer el dfs y bfs entre lista y matriz, ya que a veces el loadgrpah mete los
    //nodos en un orden que es diferente a la matriz, y auqneu es correcto lo que hace los imprime diferente
    for (int i = 0; i < this->numVertices; i++){
        this->adjLists[i].sort();
    }
}


