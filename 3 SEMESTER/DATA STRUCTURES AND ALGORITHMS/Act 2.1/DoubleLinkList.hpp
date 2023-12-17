//#ifndef DOUBLELINKLIST_H
//#define DOUBLELINKLIST_H
#pragma once

#include <iostream>

struct Node {
    int data;
    Node *prev;
    Node *next;
};

class DoubleLinkList {
    private:
        Node *Head;
    public:
        // Constructor y Destructor
        DoubleLinkList(): Head(NULL){};
        ~DoubleLinkList() {
            std::cout << "Destructor: ";
            DeleteAll();
            delete Head;
        }

        // CRUD
        void Create(int);
        Node* Read(int);
        void Update(int, int);
        void Delete(int);

        // Extra
        void DeleteAll();
        void Display();
        void BubbleSort();
};

//#endif