#include <iostream>
#include "queue-array.hpp"
#include "queue-list.hpp"

int main()
{
    QueueArray *queueArray = new QueueArray(5);
    QueueList *queueList = new QueueList();

    std::cout << "-----Queue with array implementation-----" << std::endl;

    queueArray->enqueue(10);
    queueArray->enqueue(20);
    queueArray->enqueue(30);
    queueArray->enqueue(40);
    queueArray->enqueue(50);
    queueArray->print();

    std::cout << "front: " << queueArray->peekFront() << " rear: " << queueArray->peekRear() << std::endl;

    queueArray->dequeue();
    queueArray->print();

    std::cout << "front: " << queueArray->peekFront() << " rear: " << queueArray->peekRear() << std::endl;

    std::cout << "Queue size is " << queueArray->size() << std::endl;

    std::cout << "-----Queue with list implementation-----" << std::endl;

    queueList->enqueue(10);
    queueList->enqueue(20);
    queueList->enqueue(30);
    queueList->enqueue(40);
    queueList->enqueue(50);
    queueList->print();

    std::cout << "front: " << queueList->peekFront() << " rear: " << queueList->peekRear() << std::endl;

    queueList->dequeue();
    queueList->print();

    std::cout << "front: " << queueList->peekFront() << " rear: " << queueList->peekRear() << std::endl;

    std::cout << "Queue size is " << queueList->size() << std::endl;
}