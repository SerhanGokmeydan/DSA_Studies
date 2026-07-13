#include <iostream>
#include "queue-array.hpp"

QueueArray::QueueArray(int cap)
{
    count = 0;
    this->cap = cap;
    arr = new int[this->cap];
    front = rear = 0;
}

QueueArray::~QueueArray()
{
    delete[] arr;
}

int QueueArray::circArr(int index)
{
    if (index < 0)
    {
        std::cout << "Invalid index" << std::endl;
        return -1;
    }

    index %= cap;
    return index;
}

bool QueueArray::isEmpty()
{
    return count == 0;
}

bool QueueArray::isFull()
{
    return count == cap;
}

void QueueArray::enqueue(int data)
{
    if (isFull())
    {
        std::cout << "The queue is already full" << std::endl;
        return;
    }
    arr[rear] = data;
    rear = circArr(rear + 1);
    count++;
}

void QueueArray::dequeue()
{
    if (isEmpty())
    {
        std::cout << "The queue is already empty" << std::endl;
        return;
    }
    front = circArr(front + 1);
    count--;
}

int QueueArray::peekFront()
{
    if (isEmpty())
    {
        std::cout << "The queue is empty" << std::endl;
    }
    return arr[front];
}

int QueueArray::peekRear()
{
    if (isEmpty())
    {
        std::cout << "The queue is empty" << std::endl;
    }
    // rear sıranın sonundaki elemanın sağında kaldığı için bir gerisini işaret etmemiz gerekiyor
    return arr[circArr(rear + (cap - 1))];
}

int QueueArray::size()
{
    return count;
}

void QueueArray::print()
{
    if (isEmpty())
    {
        std::cout << "The queue is empty" << std::endl;
        return;
    }
    // sadece sıradaki eleman sayısı kadarını ekrana yazdır
    for (int i = 0; i < count; i++)
    {
        int index = circArr(front + i);
        std::cout << arr[index] << " <- ";
    }
    std::cout << std::endl;
}
