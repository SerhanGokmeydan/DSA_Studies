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

    // queueArray->dequeue();
    // queueArray->dequeue();
    // queueArray->dequeue();

    // queueArray->enqueue(60);
    // queueArray->enqueue(70);
    // queueArray->enqueue(80);
    // queueArray->enqueue(90);

    queueArray->print();

    std::cout << "Queue size is " << queueArray->size() << std::endl;
}