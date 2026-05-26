#pragma once

class StackArray
{
private:
    int *arr;
    int capacity;
    int top;

public:
    void push(int data);
    void pop();
    int peek();
    bool isEmpty();
    bool isFull();
    int size();
    void print();

    StackArray(int size);
    ~StackArray();
};