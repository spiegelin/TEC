#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <random>
#include <queue>

class Graph {
    private:
        int numVertices;
        int numEdges;
        std::vector<int> indegree;

    
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

        /* Tarea 4.1 */
        // Matriz
        void DFSMatrix(int);
        void initDFSMatrix(int);
        void BFSMatrix(int);
        void initBFSMatrix(int);
        void loadGraph(int, int); // Matriz y Lista por referencia 

        // Lista
        void DFSList(int);
        void initDFSList(int);
        void BFSList(int);
        void initBFSList(int);

        /* Tarea 4.2 */
        void loadGraphDAG(int, int); // Matriz y Lista por referencia 
        bool isTree(int,int);
        void topologicalSort();
        bool bipartiteGraph(int);
};