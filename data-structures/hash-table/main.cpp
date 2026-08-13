#include "hash-table-chaining.hpp"
#include "hash-table-addressing.hpp"
#include <iostream>

int main()
{
    HashTableChaining<int, std::string> hashTableChaining;
    HashTableAddressing<int, std::string> hashTableAddressing;

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

    std::cout << "--- Hash Table with addressing ---" << std::endl;

    hashTableAddressing.insert(1, "serhan");
    hashTableAddressing.insert(2, "serra");
    hashTableAddressing.insert(11, "seray");
    hashTableAddressing.insert(10, "servet");
    hashTableAddressing.insert(20, "ali");
    hashTableAddressing.insert(9, "sedef");
    hashTableAddressing.insert(8, "sadik");
    hashTableAddressing.insert(18, "saadet");
    hashTableAddressing.insert(17, "salih");
    hashTableAddressing.insert(16, "soner");
    hashTableAddressing.insert(5, "simit");
    hashTableAddressing.insert(31, "sidika");

    hashTableAddressing.print();

    hashTableAddressing.remove(1);
    hashTableAddressing.remove(11);
    hashTableAddressing.remove(17);

    hashTableAddressing.print();

    hashTableAddressing.search(31);
    hashTableAddressing.search(111);
    hashTableAddressing.insert(31, "serhan");

    hashTableAddressing.print();
    
    return 0;
}