#include <iostream>
#include "LinkedList.hpp"

int main()
{
    LinkedList *linkedList = new LinkedList();

    linkedList->head = new LinkedList::Node(1);
    linkedList->head->next = new LinkedList::Node(2);

    std::cout << linkedList->getNodeCount() << std::endl;
}