#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int
main()
{
    Node *head = new Node(1);
    head->next = new Node(2);

    return 0;
}
