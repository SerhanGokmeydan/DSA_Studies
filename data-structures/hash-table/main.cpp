#include "hash-table-chaining.hpp"
#include <iostream>

int main()
{
    HashTableChaining<int, std::string> hashTableChaining;

    std::cout << "--- Hash Table with separate chaining ---" << std::endl;

    hashTableChaining.insert(1, "serhan");
    hashTableChaining.insert(2, "serra");
    hashTableChaining.insert(3, "servet");
    hashTableChaining.insert(4, "seray");

    hashTableChaining.print();

    hashTableChaining.insert(11, "mustafa");
    hashTableChaining.insert(13, "omar");

    hashTableChaining.insert(3, "bilal");

    hashTableChaining.insert(105, "sedef");
    hashTableChaining.insert(94, "sedat");
    hashTableChaining.insert(84, "sadik");

    hashTableChaining.print();

    hashTableChaining.remove(13);
    hashTableChaining.remove(11);
    hashTableChaining.remove(84);
    hashTableChaining.remove(1);

    hashTableChaining.print();

    hashTableChaining.search(94);
    hashTableChaining.search(2);

    return 0;
}