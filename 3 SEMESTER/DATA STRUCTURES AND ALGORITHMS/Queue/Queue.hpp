#pragma once

struct Node {
    int value;
};

class Queue {
    private:
        Node *Q;
        int front, rear, N;
    public:
        // Constructor y Destructor
        Queue(int size);
        ~Queue();

        // CRUD
        void Enqueue(int);
        int Peek();
        void Update(int,int);
        Node* Dequeue();

        // Extra
        void Display();
        bool isEmpty();
        bool isFull();
};