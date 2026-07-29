#pragma once
#include <iostream>
#include <vector>
#include <cstddef>
#include <type_traits>
#include <stdexcept>
#include <string>

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
    size_t cap;
    float loadFactor;

    void rehash(size_t count)
    {
        // do not forget casting float, or the LF will be 0
        float currentLF = (float)count / table.size();
        size_t newSize = 0;
        if (currentLF >= loadFactor)
        {
            newSize = table.size() * 2;
        }
        // to reduce table size, take the quarted of LF as a measure due to thrashing problem
        // if we take same LF to update table size, there will be so much O(N) processes in consecutive insert and remove
        else if (currentLF <= loadFactor / 4.0f && table.size() / 2 >= cap)
        {
            newSize = table.size() / 2;
        }
        else
        {
            return;
        }
        std::vector<Node *> newTable(newSize, nullptr);
        for (size_t i = 0; i < table.size(); i++)
        {
            Node *current = table.at(i);
            while (current != nullptr)
            {
                Node *next = current->next;
                size_t newIndex = hash(current->key, newSize);
                current->next = newTable.at(newIndex);
                newTable.at(newIndex) = current;
                current = next;
            }
        }
        // to copy newTable to table use std::move, it prevent O(N) copying process, reduce it to O(1)
        table = std::move(newTable);
    }

    size_t hash(const K &key, size_t size) const
    {
        if constexpr (std::is_integral_v<K>)
        {
            // use is_signed_v, otherwise the compiler throw an error says "unsigned numbers cannot be negative"
            if constexpr (std::is_signed_v<K>)
            {
                if (key < 0)
                {
                    throw std::invalid_argument("Key value must be positive whole number");
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
            throw std::invalid_argument("The key value must be a number or a string.");
        }
    }

    size_t hash(const K &key) const
    {
        return hash(key, table.size());
    }

public:
    HashTableChaining(size_t cap = 10, float loadFactor = 0.75f) : cap(cap), table(cap, nullptr), count(0), loadFactor(loadFactor) {}

    ~HashTableChaining()
    {
        for (size_t i = 0; i < table.size(); i++)
        {
            Node *current = table.at(i);
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
    }

    void insert(const K &key, const V &val)
    {
        try
        {
            size_t index = hash(key);
            Node *current = table.at(index);
            while (current != nullptr)
            {
                if (current->key == key)
                {
                    current->val = val;
                    return;
                }
                current = current->next;
            }
            Node *node = new Node(key, val);
            node->next = table.at(index);
            table.at(index) = node;
            rehash(++count);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void remove(const K &key)
    {
        try
        {
            size_t index = hash(key);
            Node *current = table.at(index);
            Node *prev = nullptr;
            while (current != nullptr)
            {
                if (current->key == key)
                {
                    if (prev == nullptr)
                    {
                        table.at(index) = current->next;
                    }
                    else
                    {
                        prev->next = current->next;
                    }
                    delete current;
                    rehash(--count);
                    return;
                }
                prev = current;
                current = current->next;
            }
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
            Node *current = table.at(index);
            while (current != nullptr)
            {
                if (current->key == key)
                {
                    std::cout << current->key << " : " << current->val << std::endl;
                    return;
                }
                current = current->next;
            }
            if (current == nullptr)
            {
                std::cout << "Data is not found" << std::endl;
                return;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void print()
    {
        std::cout << "------------------------" << std::endl;
        for (size_t i = 0; i < table.size(); i++)
        {
            std::cout << "[" << i << "]";
            Node *current = table.at(i);
            while (current != nullptr)
            {
                std::cout << " -> (" << current->key << " : " << current->val << ")";
                current = current->next;
            }
            std::cout << std::endl;
        }
        std::cout << "------------------------" << std::endl;
    }
};
