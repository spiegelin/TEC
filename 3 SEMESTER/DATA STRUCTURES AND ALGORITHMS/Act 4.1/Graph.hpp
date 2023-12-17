#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <random>

class Graph {
    private:
        int numVertices;
        int numEdges;

    
        // Adjacent List
        std::list<int> *adjLists;
        bool *visited;

        // Adjacent Matrix
        std::vector<std::vector<bool> > adjMatrix;

    public:
        // Constructor
        Graph(int,int);

        // Destructor
        ~Graph();

        // Funciones Lista
        void addEdge(int, int);
        void addEdgeDirect(int,int);
        void printGraphL();
        void ResetVisited(); //

        // Funciones Matriz
        void printGraphM();

        // Tarea
        void loadGraph(int, int); // Matriz y Lista por referencia 

        // Matriz
        void DFSMatrix(int);
        void initDFSMatrix(int);
        void BFSMatrix(int);
        void initBFSMatrix(int);

        // Lista
        void DFSList(int);
        void initDFSList(int);
        void BFSList(int);
        void initBFSList(int);
};