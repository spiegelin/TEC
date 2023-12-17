#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node{

    int key;
    int count;
    vector<string> logs;
    Node *left, *right;

    Node(int k, string log):key(k), count(1), left(nullptr), right(nullptr){
        logs.push_back(log);
    }

};

class BST{

private:
    Node *Root;
    vector<Node> largestNodes;

    void Insert(int&, string&, Node*&);
    void InOrder(Node*);
    void PreOrder(Node*);
    void PostOrder(Node*);
    void DeleteNode(int&, Node*&);

    int Height(Node*);

    void FindLargestNodes(Node*);

public:
    BST():Root(nullptr){}

    ~BST(){
        cout << "Destructor: ";
        DeleteBST(Root);
        //delete Root;
    }

    //Operacione de insercion
    void Insert(int& value, string& log){ Insert(value,log, Root);}

    //Operaciones de mostrado de el arbol
    void InOrder() {InOrder(Root);}
    void PreOrder() {PreOrder(Root);}
    void PostOrder() {PostOrder(Root);}
    void BFT();


    //Operaciones de borrado
    void DeleteNode(int& value) {DeleteNode(value, Root);}
    void DeleteBST(Node*&);
    void SubstituteToMin(Node*&, Node*&);

    void FindTop5Nodes();
    void printTop5Nodes(ofstream& salida);

};