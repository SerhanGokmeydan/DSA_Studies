#pragma once

class Stack
{
private:
    int *arr;
    int size;
    int top;

public:
    void push();
    void pop();
    int seek();
    bool isEmpty();
    int size();

    Stack(int size);
    ~Stack();
};