#include <iostream>
#include "../include/LinkedList.hpp"

LinkedList::Node::Node(int data)
{
    this->data = data;
    this->next = nullptr;
}

LinkedList::LinkedList(){
    this->head = nullptr;
    this->nodeCount = 0;
}