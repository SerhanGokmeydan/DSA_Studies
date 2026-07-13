#pragma once

class StackLinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node(int data);
    };
    Node *top;
    int count;

public:
    void push(int data);
    void pop();
    int peek();
    bool isEmpty();
    int size();
    void print();

    StackLinkedList();
    ~StackLinkedList();
};