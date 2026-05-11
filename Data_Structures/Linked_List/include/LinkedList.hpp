#pragma once

class LinkedList
{
public:
    struct Node
    {
        int data;
        Node *next;
        Node(int data);
    };

    Node *head;
    int getNodeCount();
    void printLinkedList();

    LinkedList();
};
