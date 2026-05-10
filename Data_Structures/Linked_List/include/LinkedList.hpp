#pragma once

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node(int data);
    };

    Node *head;

public:
    int nodeCount;
    LinkedList();
};
