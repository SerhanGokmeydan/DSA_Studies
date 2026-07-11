#include <iostream>
#include "queue-array.hpp"

QueueArray::QueueArray(int cap)
{
    this->count = 0;
    this->cap = cap;
    this->arr = new int[this->cap];
    this->front = this->rear = 0;
}

QueueArray::~QueueArray()
{
    delete[] this->arr;
}

int QueueArray::circArr(int index)
{
    if (index < 0)
    {
        std::cout << "Invalid index" << std::endl;
        return -1;
    }

    index %= this->cap;
    return index;
}

bool QueueArray::isEmpty()
{
    return this->count == 0;
}

bool QueueArray::isFull()
{
    return this->count == this->cap;
}

void QueueArray::enqueue(int data)
{
    if (this->isFull())
    {
        std::cout << "The queue is already full" << std::endl;
        return;
    }
    this->arr[this->rear] = data;
    this->rear = this->circArr(this->rear + 1);
    this->count++;
}

void QueueArray::dequeue()
{
    if (this->isEmpty())
    {
        std::cout << "The queue is already empty" << std::endl;
        return;
    }
    this->front = circArr(this->front + 1);
    this->count--;
}

int QueueArray::peekFront()
{
    if (this->isEmpty())
    {
        std::cout << "The queue is empty" << std::endl;
    }
    return this->arr[this->front];
}

int QueueArray::peekRear()
{
    if (this->isEmpty())
    {
        std::cout << "The queue is empty" << std::endl;
    }
    // rear sıranın sonundaki elemanın sağında kaldığı için bir gerisini işaret etmemiz gerekiyor
    return this->arr[this->circArr(this->rear + (this->cap - 1))];
}

int QueueArray::size()
{
    return this->count;
}

void QueueArray::print()
{
    if (this->isEmpty())
    {
        std::cout << "The queue is empty" << std::endl;
        return;
    }
    // sadece sıradaki eleman sayısı kadarını ekrana yazdır
    for (int i = 0; i < this->count; i++)
    {
        int index = circArr(this->front + i);
        std::cout << this->arr[index] << " <- ";
    }
    std::cout << std::endl;
}
