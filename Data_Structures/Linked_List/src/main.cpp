#include <iostream>
#include "LinkedList.hpp"

int main()
{
    LinkedList *linkedList = new LinkedList();

    linkedList->insertEnd(10);
    linkedList->insertEnd(20);
    linkedList->insertEnd(30);

    std::cout << "List length is " << linkedList->getNodeCount() << std::endl;
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

    std::cout << "-------------" << std::endl;

    linkedList->insertBeginnig(4);
    linkedList->printLinkedList();

    std::cout << "-------------" << std::endl;

    linkedList->insertAfterNode(10, 5);
    linkedList->printLinkedList();

    std::cout << "-------------" << std::endl;

    linkedList->insertBeforeNode(30, 6);
    linkedList->printLinkedList();

    std::cout << "-------------" << std::endl;

    linkedList->insertAtPoint(5, 7);
    linkedList->printLinkedList();

    std::cout << "-------------" << std::endl;

    linkedList->insertEnd(60);
    linkedList->printLinkedList();

    std::cout << "-------------" << std::endl;

    linkedList->deleteBeginning();
    linkedList->printLinkedList();

    std::cout << "-------------" << std::endl;

    linkedList->deleteAfterNode(10);
    linkedList->printLinkedList();

    std::cout << "-------------" << std::endl;

    linkedList->deleteBeforeNode(30);
    linkedList->printLinkedList();

    delete linkedList;
}