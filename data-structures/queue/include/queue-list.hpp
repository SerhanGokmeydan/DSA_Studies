#pragma once

class QueueList
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node(int data);
    };
    Node *front;
    Node *rear;
    int count;

public:
    void enqueue(int data);
    void dequeue();
    int peekFront();
    int peekRear();
    bool isEmpty();
    int size();
    void print();

    QueueList();
    ~QueueList();
};