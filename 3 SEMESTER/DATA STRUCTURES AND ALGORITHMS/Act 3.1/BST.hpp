#pragma once
#include <iostream>


struct Node {
    int data;
    Node *left, *right;

    Node(int d): data(d), left(NULL), right(NULL) {}
};

class BST {
    private:   
        Node *root;

        // Funciones
        void Insert(int&, Node*&);
        void Inorder(Node*);
        void Preorder(Node*);
        void Postorder(Node*);
        void DeleteNode(int&, Node*&);
        int height(Node*);
        int whatlevelamI(int, Node*, int);
    public:
        BST(): root(NULL) {};
        ~BST();

        // Funciones
        void Insert(int &value) { Insert(value, root); };

        void Inorder() { Inorder(root); };
        void Preorder() { Preorder(root); };
        void Postorder() { Postorder(root); };
        void BFT();

        void SubstituteToMin(Node*&, Node*&);
        void DeleteNode(int &value) { DeleteNode(value, root); };
        void DeleteBST(Node*&);

        // Tarea
        void visit(int);
        int height() { return height(root); };
        void ancestors(int);
        int whatlevelamI(int value) { return whatlevelamI(value, root, -1);};
};