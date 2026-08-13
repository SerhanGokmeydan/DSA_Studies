#pragma once
#include <iostream>
#include <vector>
#include <cstddef>
#include <type_traits>
#include <stdexcept>
#include <string>

template <typename K, typename V>
class HashTableAddressing
{
private:
    struct Node
    {
        enum class State
        {
            OCCUPIED,
            DELETED
        };
        K key;
        V val;
        State state;
        Node(const K &key, const V &val) : key(key), val(val), state(Node::State::OCCUPIED) {}
    };
    std::vector<Node *> table;
    size_t count;
    size_t cap;
    float loadFactor;

    void rehash(size_t count)
    {
        float currentLF = (float)count / table.size();
        size_t newSize = 0;
        if (currentLF >= loadFactor)
        {
            newSize = table.size() * 2;
        }
        // prevent from thrasing problem
        else if (currentLF <= loadFactor / 4.0f && table.size() / 2 >= cap)
        {
            newSize = table.size() / 2;
        }
        else
        {
            return;
        }
        std::vector<Node *> newTable(newSize, nullptr);
        for (Node *node : table)
        {
            if (node == nullptr)
            {
                continue;
            }
            // do not rehash deleted nodes, and delete them
            if (node->state == Node::State::DELETED)
            {
                delete node;
                continue;
            }
            size_t newIndex = hash(node->key, newSize);
            // to prevent collision during rehashin, check whether new position is null.
            // if it's not, then increase new index by 1.
            while (newTable.at(newIndex) != nullptr)
            {
                newIndex = (newIndex + 1) % newSize;
            }
            newTable.at(newIndex) = node;
        }
        // use move instead of direct copying
        table = std::move(newTable);
    }

    size_t hash(const K &key, size_t size) const
    {
        if constexpr (std::is_integral_v<K>)
        {
            if constexpr (std::is_signed_v<K>)
            {
                if (key < 0)
                {
                    throw std::invalid_argument("Key value must be positive integer.");
                }
            }
            return (size_t)key % size;
        }
        else if constexpr (std::is_same_v<K, std::string>)
        {
            size_t hashVal = 0;
            for (char c : key)
            {
                hashVal += (size_t)c;
            }
            return hashVal % size;
        }
        else
        {
            throw std::invalid_argument("Key value must be an integer or a string");
        }
    }

    size_t hash(const K &key) const
    {
        return hash(key, table.size());
    }

public:
    HashTableAddressing(size_t cap = 10, float loadFactor = 0.75f) : cap(cap), table(cap, nullptr), count(0), loadFactor(loadFactor) {}

    ~HashTableAddressing()
    {
        for (Node *node : table)
        {
            delete node;
        }
    }

    void insert(const K &key, const V &val)
    {
        try
        {
            size_t INVALID_INDEX = table.size();
            size_t index = hash(key);
            size_t initialIndex = index;
            size_t firstDeletedIndex = INVALID_INDEX;
            Node *current = table.at(index);
            while (current != nullptr)
            {
                // save first deleted tombstone
                if (current->state == Node::State::DELETED && firstDeletedIndex == INVALID_INDEX)
                {
                    firstDeletedIndex = index;
                }
                if (current->key == key)
                {
                    current->val = val;
                    if (current->state == Node::State::DELETED)
                    {
                        current->state = Node::State::OCCUPIED;
                        rehash(++count);
                    }
                    return;
                }
                index = (index + 1) % table.size();
                current = table.at(index);
                // table may filled up with tombstone, so it can be enter infinite loop
                if (initialIndex == index)
                {
                    break;
                }
            }
            if (firstDeletedIndex == INVALID_INDEX)
            {
                table.at(index) = new Node(key, val);
            }
            else
            {
                // delete previous tombstone node
                delete table.at(firstDeletedIndex);
                table.at(firstDeletedIndex) = new Node(key, val);
            }
            rehash(++count);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    void remove(const K &key)
    {
        try
        {
            size_t index = hash(key);
            size_t initialIndex = index;
            Node *current = table.at(index);
            while (current != nullptr)
            {
                if (current->key == key && current->state != Node::State::DELETED)
                {
                    table.at(index)->state = Node::State::DELETED;
                    rehash(--count);
                    return;
                }
                index = (index + 1) % table.size();
                current = table.at(index);
                if (initialIndex == index)
                {
                    break;
                }
            }
            std::cout << "Key is not found" << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void search(const K &key)
    {
        try
        {
            size_t index = hash(key);
            size_t initialIndex = index;
            Node *current = table.at(index);
            // current->key : segmantation fault
            while (current != nullptr)
            {
                if (current->key == key && current->state != Node::State::DELETED)
                {
                    std::cout << current->key << " : " << current->val << std::endl;
                    return;
                }
                index = (index + 1) % table.size();
                current = table.at(index);
                if (index == initialIndex)
                {
                    break;
                }
            }
            std::cout << "Key is not found" << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void print()
    {
        std::cout << "-----------------------" << std::endl;
        for (size_t i = 0; i < table.size(); i++)
        {
            Node *current = table.at(i);
            if (current == nullptr)
            {
                std::cout << "[" << i << "] ->" << std::endl;
                continue;
            }
            if (current->state == Node::State::DELETED)
            {
                std::cout << "[" << i << "] ->" << std::endl;
                continue;
            }
            std::cout << "[" << i << "] -> ("
                      << current->key << " : " << current->val << ")" << std::endl;
        }
        std::cout << "-----------------------" << std::endl;
    }
};