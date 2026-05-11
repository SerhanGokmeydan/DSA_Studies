#include <iostream>
#include "../include/LinkedList.hpp"

LinkedList::Node::Node(int data)
{
    this->data = data;
    this->next = nullptr;
}

LinkedList::LinkedList(){
    this->head = nullptr;
}

int LinkedList::getNodeCount(){
    Node* currentNode = this->head;
    int nodeCount = 0;

    while(currentNode != nullptr){
        nodeCount++;
        currentNode = currentNode->next;
    }

    return nodeCount;
}

void LinkedList::printLinkedList(){
    Node* currentNode = this->head;

    while(currentNode != nullptr){
        std::cout << currentNode->data << " -> ";
        currentNode = currentNode->next;
    }
}