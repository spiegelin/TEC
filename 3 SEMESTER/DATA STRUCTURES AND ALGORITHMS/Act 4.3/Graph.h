#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <ctime>
#include <algorithm>
using namespace std;


class Graph{

    private:
        int numVertices;
        list<int> *adjLists;
        vector<vector<bool> > adjMatrix;
        
        int *outdegree;
        vector<pair<int, int> > nodeOutdegrees;

    public:

        Graph(int);

        ~Graph(){
            delete[] adjLists;
            delete[] outdegree;

        }

        void addEdgeList(int, int);
        void addEdgeMatrix(int, int);
        void addEdge(int, int);

        void printAdjList();
        void printAdjMatrix();
        void printOutDegree();

        void addOutDegree(int);
        int outDegreeNode(int);


        void getTop10OutDegrees();
        void printTop10OutDegrees();
        int getTopOutDegree();

        void outDegreeNodeList(int);
        void outDegreeNodeMatrix(int);
        bool alreadyConnected(int, int);

        void sortAdjList();

};