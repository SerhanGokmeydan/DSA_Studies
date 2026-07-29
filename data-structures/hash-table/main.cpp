#include <string>
#include "hash-table-chaining.hpp"

int main(){
    HashTableChaining<int, std::string> hashTableChaining;

    hashTableChaining.insert(1, "serhan");
    hashTableChaining.insert(2, "serra");
    hashTableChaining.insert(3, "servet");
    hashTableChaining.insert(4, "seray");

    hashTableChaining.insert(11, "mustafa");
    hashTableChaining.insert(13, "omar");

    hashTableChaining.insert(3, "bilal");

    hashTableChaining.insert(105, "sedef");
    hashTableChaining.insert(94, "sedat");
    hashTableChaining.insert(84, "sadik");

    hashTableChaining.print();

    return 0;
}