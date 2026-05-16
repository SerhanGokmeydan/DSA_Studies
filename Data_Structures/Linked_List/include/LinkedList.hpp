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
    int getNodeCount();
    void printLinkedList();
    bool searchNode(int key);

    void insertBeginnig(int data);
    void insertAfterNode(int key, int data);
    void insertBeforeNode(int key, int data);
    void insertAtPoint(int pos, int data);
    void insertEnd(int data);

    void deleteBeginning();
    void deleteAfterNode(int key);
    void deleteBeforeNode(int key);
    void deleteAtPoint(int pos);
    void deleteEnd();

    LinkedList();
    ~LinkedList();
};
