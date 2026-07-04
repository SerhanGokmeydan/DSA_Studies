#include <iostream>
#include "StackLinkedList.hpp"

StackLinkedList::Node::Node(int data)
{
    this->data = data;
    this->next = nullptr;
}

StackLinkedList::StackLinkedList()
{
    this->top = nullptr;
    this->count = 0;
}

StackLinkedList::~StackLinkedList()
{
    Node *current = this->top;
    Node *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
}

void StackLinkedList::push(int data)
{
    Node *newNode = new Node(data);
    newNode->next = this->top;
    this->top = newNode;
    this->count++;
}

void StackLinkedList::pop()
{
    if (this->isEmpty())
    {
        std::cout << "Stack Underflow" << std::endl;
        return;
    }
    Node *temp = this->top;
    this->top = this->top->next;
    delete temp;
    this->count--;
}

int StackLinkedList::peek()
{
    if (this->isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
        return -1;
    }
    return this->top->data;
}

bool StackLinkedList::isEmpty()
{
    return this->top == nullptr;
}

int StackLinkedList::size()
{
    return this->count;
}

void StackLinkedList::print()
{
    Node *current = this->top;
    while (current != nullptr)
    {
        std::cout << current->data << " <- ";
        current = current->next;
    }
    std::cout << std::endl;
}