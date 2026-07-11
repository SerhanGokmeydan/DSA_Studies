#include <iostream>
#include "queue-array.hpp"

int main()
{
    QueueArray *queueArray = new QueueArray(5);

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
}