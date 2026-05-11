#include <iostream>
#include "LinkedList.hpp"

int main()
{
    LinkedList *linkedList = new LinkedList();

    linkedList->head = new LinkedList::Node(1);
    linkedList->head->next = new LinkedList::Node(2);
    linkedList->head->next->next = new LinkedList::Node(3);

    std::cout << linkedList->getNodeCount() << std::endl;
    linkedList->printLinkedList();
}