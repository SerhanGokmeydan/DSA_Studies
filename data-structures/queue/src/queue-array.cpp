#include <iostream>
#include "queue-array.hpp"

QueueArray::QueueArray(int cap)
{
    this->count = 0;
    this->cap = cap;
    this->arr = new int[this->cap];
    this->front = this->rear = -1;
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
    if (this->count == 0)
        return true;
    return false;
}

bool QueueArray::isFull()
{
    if (this->count == this->cap)
        return true;
    return false;
}

void QueueArray::enqueue(int data)
{
    if (this->isFull())
    {
        std::cout << "The queue is already full" << std::endl;
        return;
    }
    if (this->isEmpty())
    {
        this->front = this->circArr(++this->front);
    }
    this->rear = this->circArr(++this->rear);
    this->arr[this->rear] = data;
    this->count++;
}

// front değerini azaltarak değil çemberde bir tur attırarak güncellemeye çalış
// front += (cap + 1)
void QueueArray::dequeue()
{
    if (this->isEmpty())
    {
        std::cout << "The queue is already empty" << std::endl;
        return;
    }
    this->arr[this->front] = 0;
    this->front = circArr(this->front + (this->cap + 1));
    this->count--;
}

int QueueArray::peekFront()
{
    return this->arr[this->front];
}

int QueueArray::peekRear()
{
    return this->arr[this->rear];
}

int QueueArray::size()
{
    return this->count;
}

void QueueArray::print()
{
    int currentIndex = this->front;
    do
    {
        std::cout << this->arr[currentIndex] << " -> ";
        currentIndex = circArr(++currentIndex);

    } while (currentIndex != this->circArr(this->rear + 1));
    std::cout << std::endl;
}
