#include <iostream>
#include "../include/LinkedList.hpp"

LinkedList::Node::Node(int data)
{
    this->data = data;
    this->next = nullptr;
}

LinkedList::LinkedList()
{
    this->head = nullptr;
}

int LinkedList::getNodeCount()
{
    Node *currentNode = this->head;
    int nodeCount = 0;

    while (currentNode != nullptr)
    {
        nodeCount++;
        currentNode = currentNode->next;
    }

    return nodeCount;
}

void LinkedList::printLinkedList()
{
    Node *currentNode = this->head;

    while (currentNode != nullptr)
    {
        std::cout << currentNode->data << " -> ";
        currentNode = currentNode->next;
    }

    std::cout << std::endl;
}

bool LinkedList::searchNode(int key)
{
    Node *currentNode = this->head;

    while (currentNode != nullptr)
    {
        if (currentNode->data == key)
        {
            return true;
        }
        currentNode = currentNode->next;
    }

    return false;
}

void LinkedList::insertBeginnig(int data)
{
    Node *newNode = new Node(data);
    newNode->next = this->head;
    this->head = newNode;
}

void LinkedList::insertAfterNode(int key, int data)
{
    Node *currentNode = this->head;

    while (currentNode != nullptr)
    {
        if (currentNode->data == key)
        {
            Node *newNode = new Node(data);
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            break;
        }
        currentNode = currentNode->next;
    }
    if (currentNode == nullptr)
    {
        std::cout << "Node is not found" << std::endl;
    }
}

void LinkedList::insertBeforeNode(int key, int data)
{
    Node *currentNode = this->head;
    Node *prevNode = nullptr;

    while (currentNode != nullptr)
    {
        if (currentNode->data == key)
        {
            Node *newNode = new Node(data);
            newNode->next = currentNode;
            (prevNode == nullptr ? this->head : prevNode->next) = newNode;
            break;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode == nullptr)
    {
        std::cout << "Node is not found" << std::endl;
    }
}

void LinkedList::insertAtPoint(int pos, int data)
{
    Node *currentNode = this->head;

    for (int i = 0; i < pos - 1; i++)
    {
        currentNode = currentNode->next;
    }

    if (currentNode == nullptr || pos < 1)
    {
        std::cout << "Position is not valid" << std::endl;
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = (pos == 1) ? this->head : currentNode->next;
    (pos == 1 ? this->head : currentNode->next) = newNode;
}

void LinkedList::insertEnd(int data){
    Node *currentNode = this->head;

    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }

    Node *newNode = new Node(data);
    (this->head == nullptr ? this->head : currentNode->next) = newNode;
}