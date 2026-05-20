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

// check whether list is empty
bool LinkedList::emptyListCheck()
{
    if (this->head == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return true;
    }
    return false;
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
    if (this->emptyListCheck())
        return;
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

void LinkedList::getNthFromBeginning(int pos)
{
    if (this->emptyListCheck())
        return;
    if (pos < 1)
    {
        std::cout << "Invalid position" << std::endl;
        return;
    }
    Node *currentNode = this->head;
    for (int i = 0; i < pos - 1; i++)
    {
        currentNode = currentNode->next;
        if (currentNode == nullptr)
        {
            std::cout << "Invalid position" << std::endl;
            return;
        }
    }
    std::cout << pos << ". node from beginning is " << currentNode->data << std::endl;
}

void LinkedList::getNthFromEnd(int pos)
{
    if (this->emptyListCheck())
        return;
    if (pos < 1)
    {
        std::cout << "Invalid position" << std::endl;
        return;
    }
    Node *currentNode = this->head;
    Node *targetNode = this->head;
    for (int i = 0; i < pos - 1; i++)
    {
        currentNode = currentNode->next;
        if (currentNode == nullptr)
        {
            std::cout << "Invalid position" << std::endl;
            return;
        }
    }
    while (currentNode->next != nullptr)
    {
        currentNode = currentNode->next;
        targetNode = targetNode->next;
    }
    std::cout << pos << ". node from end is " << targetNode->data << std::endl;
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
    if (this->emptyListCheck())
        return;
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
    if (this->emptyListCheck())
        return;
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
    if (this->emptyListCheck())
        return;
    if (pos < 1)
    {
        std::cout << "Invalid position" << std::endl;
        return;
    }
    Node *currentNode = this->head;
    for (int i = 0; i < pos - 1; i++)
    {
        if (currentNode == nullptr)
        {
            std::cout << "Invalid position" << std::endl;
            return;
        }
        currentNode = currentNode->next;
    }
    Node *newNode = new Node(data);
    newNode->next = (pos == 1) ? this->head : currentNode->next;
    (pos == 1 ? this->head : currentNode->next) = newNode;
}

void LinkedList::insertEnd(int data)
{
    if (this->head == nullptr)
    {
        this->insertBeginnig(data);
        return;
    }
    Node *currentNode = this->head;
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
    if (this->emptyListCheck())
        return;
    Node *tempNode = this->head;
    this->head = this->head->next;
    delete tempNode;
}

void LinkedList::deleteAfterNode(int key)
{
    if (this->emptyListCheck())
        return;
    Node *currentNode = this->head;
    while (currentNode != nullptr)
    {
        if (currentNode->data == key)
        {
            if (currentNode->next == nullptr)
            {
                std::cout << "There is no node after given key" << std::endl;
                return;
            }
            Node *tempNode = currentNode->next;
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
    if (this->emptyListCheck())
        return;
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

void LinkedList::deleteAtPoint(int pos)
{
    if (this->emptyListCheck())
        return;
    if (pos < 1)
    {
        std::cout << "Invalid position" << std::endl;
        return;
    }
    if (pos == 1)
    {
        this->deleteBeginning();
        return;
    }
    Node *currentNode = this->head;
    for (int i = 0; i < pos - 2; i++)
    {
        currentNode = currentNode->next;
        if (currentNode == nullptr || currentNode->next == nullptr)
        {
            std::cout << "Invalid position" << std::endl;
            return;
        }
    }
    if (currentNode == nullptr || currentNode->next == nullptr)
    {
        std::cout << "Invalid position" << std::endl;
        return;
    }
    Node *tempNode = currentNode->next;
    currentNode->next = currentNode->next->next;
    delete tempNode;
}

void LinkedList::deleteEnd()
{
    if (this->emptyListCheck())
        return;
    Node *currentNode = this->head;
    if (this->head->next == nullptr)
    {
        delete this->head;
        this->head = nullptr;
        return;
    }
    while (currentNode->next->next != nullptr)
    {
        currentNode = currentNode->next;
    }
    Node *tempNode = currentNode->next;
    currentNode->next = nullptr;
    delete tempNode;
}