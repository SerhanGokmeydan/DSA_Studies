#include <iostream>
#include "LinkedList.hpp"

int main()
{
    LinkedList *linkedList = new LinkedList();

    linkedList->head = new LinkedList::Node(1);
    linkedList->head->next = new LinkedList::Node(2);
    linkedList->head->next->next = new LinkedList::Node(3);

    std::cout << "List length is "<< linkedList->getNodeCount() << std::endl;
    linkedList->printLinkedList();

    if (linkedList->searchNode(2))
    {
        std::cout << "List includes node with data 2" << std::endl;
    }
    else
    {
        std::cout << "List does not include node with data 2" << std::endl;
    }

    if (linkedList->searchNode(10))
    {
        std::cout << "List includes node with data 10" << std::endl;
    }
    else
    {
        std::cout << "List does not include node with data 10" << std::endl;
    }
}