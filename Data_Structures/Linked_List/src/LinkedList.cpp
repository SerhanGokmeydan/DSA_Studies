#include <iostream>
#include "../include/LinkedList.hpp"

// linked list's constructure, deconstructure

LinkedList::Node::Node(int data)
{
    this->data = data;
    this->next = nullptr;
}

LinkedList::LinkedList()
{
    this->head = nullptr;
}

LinkedList::~LinkedList()
{
    Node *currentNode = this->head;
    Node *nextNode = nullptr;

    while (currentNode != nullptr)
    {
        nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
}

// list size

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

// list printing

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

// list searching

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

// insertion methods

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
            return;
        }
        currentNode = currentNode->next;
    }
    std::cout << "Node is not found" << std::endl;
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
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    std::cout << "Node is not found" << std::endl;
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

void LinkedList::insertEnd(int data)
{
    Node *currentNode = this->head;

    if (this->head == nullptr)
    {
        this->insertBeginnig(data);
        return;
    }

    while (currentNode->next != nullptr)
    {
        currentNode = currentNode->next;
    }

    Node *newNode = new Node(data);
    currentNode->next = newNode;
}

// deletion methods

void LinkedList::deleteBeginning()
{
    Node *tempNode = this->head;
    this->head = this->head->next;

    delete tempNode;
}

void LinkedList::deleteAfterNode(int key)
{
    Node *currentNode = this->head;
    while (currentNode != nullptr)
    {
        if (currentNode->data == key)
        {
            Node *tempNode = currentNode->next;
            if (currentNode->next == nullptr)
            {
                std::cout << "There is no node after given key" << std::endl;
                return;
            }
            currentNode->next = currentNode->next->next;
            delete tempNode;
            return;
        }
        currentNode = currentNode->next;
    }
    std::cout << "Node is not found" << std::endl;
}

void LinkedList::deleteBeforeNode(int key)
{
    Node *currentNode = this->head;
    Node *firstPrevNode = nullptr;
    Node *secondPrevNode = nullptr;
    while (currentNode != nullptr)
    {
        if (currentNode->data == key)
        {
            Node *tempNode = firstPrevNode;
            if (currentNode == this->head)
            {
                std::cout << "There is no node before given key" << std::endl;
                return;
            }
            if (currentNode == this->head->next)
            {
                this->deleteBeginning();
                return;
            }
            secondPrevNode->next = currentNode;
            delete tempNode;
            return;
        }
        secondPrevNode = firstPrevNode;
        firstPrevNode = currentNode;
        currentNode = currentNode->next;
    }
    std::cout << "Node is not found" << std::endl;
}