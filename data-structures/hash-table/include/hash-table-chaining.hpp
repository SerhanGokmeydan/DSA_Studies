#pragma once
#include <vector>
#include <cstddef>

template <typename K, typename V>
class HashTableChaining
{
private:
    struct Node
    {
        K key;
        V val;
        Node *next;
        Node(const K &key, const V &val) : key(key), val(val), next(nullptr) {}
    };
    std::vector<Node *> table;
    size_t count;
    float loadFactor;

public:
    HashTableChaining(size_t cap = 11, float loadFactor = 0.75f) : table(cap, nullptr), count(0), loadFactor(loadFactor) {}
};
