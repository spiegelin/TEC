#pragma once

struct Node {
    int value;
    int priority;
};

class PQueue {
    private:
        Node *PQ;
        int N, NumNodes;
    public:
        // Constructor y Destructor
        PQueue(int size);
        ~PQueue();

        // CRUD
        void Enqueue(int, int);
        int Peek();
        void Update(int,int);
        Node* Dequeue();

        // Extra
        void Display();
        void Display(int);
        bool isEmpty();
        bool isFull();
};