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
    int size();

    StackArray(int size);
    ~StackArray();
};