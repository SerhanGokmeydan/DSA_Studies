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

bool LinkedList::searchNode(int data)
{
    Node *currentNode = this->head;

    while (currentNode != nullptr)
    {
        if (currentNode->data == data)
        {
            return true;
        }
        currentNode = currentNode->next;
    }

    return false;
}