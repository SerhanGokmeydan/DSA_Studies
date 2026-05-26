#include <iostream>
#include "StackArray.hpp"

int main()
{
    StackArray *stackArray = new StackArray(10);

    std::cout << "-----Stack with array implementation-----" << std::endl;

    stackArray->push(10);
    stackArray->push(20);
    stackArray->push(30);

    stackArray->print();

    std::cout << "Stack size is " << stackArray->size() << std::endl;

    if (stackArray->isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        std::cout << "Stack is not empty" << std::endl;
    }

    if (stackArray->isFull())
    {
        std::cout << "Stack is full" << std::endl;
    }
    else
    {
        std::cout << "Stack is not full" << std::endl;
    }

    std::cout << "-----push-----" << std::endl;
    stackArray->push(100);
    stackArray->print();

    std::cout << "-----pop-----" << std::endl;
    stackArray->pop();
    stackArray->print();

    std::cout << "-----peek-----" << std::endl;
    std::cout << "The top is " << stackArray->peek() << std::endl;

    delete stackArray;
    return 0;
}