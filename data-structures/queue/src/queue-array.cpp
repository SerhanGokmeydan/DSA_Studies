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

void QueueArray::circArr(int index, int val)
{
    index = this->circArr(index);
    this->arr[index] = val;
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
        this->front++;
    }
    this->rear++;
    this->count++;
    this->circArr(this->rear, data);
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
    this->circArr(this->front, 0);
    this->front--;
    this->count--;
}

int QueueArray::peekFront()
{
    return circArr(this->front);
}

int QueueArray::peekRear()
{
    return circArr(this->rear);
}

int QueueArray::size()
{
    return this->count;
}

void QueueArray::print()
{
    int currentIndex = this->rear;
    while (currentIndex != this->front - 1)
    {
        std::cout << this->arr[currentIndex] << " -> ";
        currentIndex--;
        // currentIndex = circArr(currentIndex);
    }
    std::cout << std::endl;
}
