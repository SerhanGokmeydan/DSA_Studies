#include <iostream>
#include "StackArray.hpp"

StackArray::StackArray(int cap)
{
    this->capacity = cap;
    this->arr = new int[this->capacity];
    this->top = -1;
}

StackArray::~StackArray()
{
    delete[] this->arr;
}

void StackArray::push(int data)
{
    if (this->isFull())
    {
        std::cout << "Stack Overflow" << std::endl;
        return;
    }
    this->arr[++top] = data;
}

void StackArray::pop()
{
    if (this->isEmpty())
    {
        std::cout << "Stack Underflow" << std::endl;
        return;
    }
    --this->top;
}

int StackArray::peek()
{
    if (this->isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
        return -1;
    }
    return this->arr[top];
}

bool StackArray::isEmpty()
{
    return this->top == -1;
}

bool StackArray::isFull()
{
    return this->top == this->capacity - 1;
}

int StackArray::size()
{
    return this->top + 1;
}

void StackArray::print(){
    for (int i = 0; i <= this->top; ++i)
    {
        std::cout << this->arr[i] << " -> ";
    }
    std::cout << std::endl;
}