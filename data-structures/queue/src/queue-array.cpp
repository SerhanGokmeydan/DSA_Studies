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
    this->rear = this->circArr(++this->rear);
    this->arr[this->rear] = data;
    this->count++;
    // eğer liste ilk eklemede boş ise frontu 0 eşitlemek yerine rear eşitle
    if (this->count == 1)
    {
        this->front = this->rear;
    }
}

void QueueArray::dequeue()
{
    if (this->isEmpty())
    {
        std::cout << "The queue is already empty" << std::endl;
        // eğer dizi boşalırsa front ve rear değerlerini tekrar -1'e eşitle
        this->front = this->rear = -1;
        return;
    }
    this->arr[this->front] = 0;
    this->front = circArr(++this->front);
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
