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
        this->next = nullptr;
    }

    Node *add(Node *node)
    {
        this->next = node;
        return node;
    }
};

int main()
{
    Node *header = new Node(1);
    Node *node2 = header->add(new Node(2));
    Node *node3 = node2->add(new Node(3));
    Node *node4 = node3->add(new Node(4));

    int counter = 1;
    Node *temp = header;
    while(temp->next != nullptr){
        counter++;
        temp = temp->next;
    }
    delete temp;

    cout << counter;

    return 0;
}