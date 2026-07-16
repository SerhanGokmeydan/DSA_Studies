#include <iostream>
#include "queue-list.hpp"

QueueList::Node::Node(int data)
{
    this->data = data;
    next = nullptr;
}

QueueList::QueueList()
{
    front = rear = nullptr;
    count = 0;
}

QueueList::~QueueList()
{
    Node *temp = rear;
    Node *next = nullptr;
    while (temp != nullptr)
    {
        next = temp->next;
        delete temp;
        temp = next;
    }
}

bool QueueList::isEmpty()
{
    return count == 0;
}

void QueueList::enqueue(int data)
{
    Node *newNode = new Node(data);
    if (isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    count++;
}

void QueueList::dequeue()
{
    if (isEmpty())
    {
        std::cout << "The queue is already empty" << std::endl;
        return;
    }
    Node *temp = front;
    front = front->next;
    if (front == nullptr)
    {
        rear = nullptr;
    }
    delete temp;
    count--;
}

int QueueList::peekFront()
{
    if (isEmpty())
    {
        std::cout << "The queue is empty" << std::endl;
        return -1;
    }
    return front->data;
}

int QueueList::peekRear()
{
    if (isEmpty())
    {
        std::cout << "The queue is empty" << std::endl;
        return -1;
    }
    return rear->data;
}

int QueueList::size()
{
    return count;
}

void QueueList::print()
{
    if (isEmpty())
    {
        std::cout << "The queue is empty" << std::endl;
        return;
    }
    Node *current = front;
    while (current != nullptr)
    {
        std::cout << current->data << " <- ";
        current = current->next;
    }
    std::cout << std::endl;
}