#include <iostream>
#include "StackArray.hpp"
#include "StackLinkedList.hpp"

int main()
{
    // Stack with array implementation
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

    // Stack with linked list implementation
    StackLinkedList *stackLinkedList = new StackLinkedList();

    std::cout << "-----Stack with linked list implementation-----" << std::endl;

    stackLinkedList->push(1);
    stackLinkedList->push(2);
    stackLinkedList->push(3);

    stackLinkedList->print();

    std::cout << "Stack size is " << stackLinkedList->size() << std::endl;

    if (stackLinkedList->isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        std::cout << "Stack is not empty" << std::endl;
    }

    std::cout << "-----push-----" << std::endl;
    stackLinkedList->push(100);
    stackLinkedList->print();

    std::cout << "-----pop-----" << std::endl;
    stackLinkedList->pop();
    stackLinkedList->print();

    std::cout << "-----peek-----" << std::endl;
    std::cout << "The top is " << stackLinkedList->peek() << std::endl;

    delete stackLinkedList;

    return 0;
}