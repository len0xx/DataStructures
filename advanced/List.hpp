#include <iostream>
#include <cstdint>
#include <string>
#include "../headers/ListInterface.hpp"

// ! The code written in this file is not supported in C++ standart yet (at least for now)
// ! So, make sure your compiler does support Concepts
// ! For example if you are using GCC (G++), use the flag '-fconcepts' like this:
// ! g++ -fconcepts lists.cpp -o lists 

#ifndef _ADVANCED_LIST_H_
#define _ADVANCED_LIST_H_

template<typename T>
concept bool Comparable() {
    return requires (T a, T b) {
        {a > b} -> bool;
        {a < b} -> bool;
        {a == b} -> bool;
        {a != b} -> bool;
        {a >= b} -> bool;
        {a <= b} -> bool;
    };
}

// Single-linked list data structure which implements ListInterface
template <Comparable K>
class ComparableList : public ListInterface<K> {

using Node = DS::Node<K>;

private:
    Node *head = nullptr;
    Node *last = nullptr;
    size_t counter = 0;

public:
    // Empty constructor
    ComparableList(void) { }

    // Constructor with the first element as the argument
    ComparableList(K val) {
        append(val);
    }

    // Constructor with the array and its length as the arguments
    ComparableList(K *val, size_t len) {
        if (!len)
            throw Error("Array length can't be 0!");

        for (size_t j = 0; j < len; ++j)
            append(val[j]);
    }

    // Constructor with the first Node as the argument
    ComparableList(Node *newNode) {
        Node modifiedNode = new Node(newNode->value);
        head = last = modifiedNode;
        counter++;
    }

    // Constructor for creating copies
    ComparableList(const ComparableList& anotherComparableList) {
        Node *current = anotherComparableList.get_head();

        while (current->next) {
            append(current->value);
            current = current->next;
        }
        if (current != nullptr)
            append(current->value);
    }

    // Destructor
    ~ComparableList() {
        clear();
    }

    // Append new element to the list with the value
    void append(K val) override {
        Node *newNode, *current;
        newNode = new Node(val);

        if (!counter) {
            head = last = newNode;
        }
        else {
            current = last;
            while (current->next)
                current = current->next;
            current->next = newNode;
            last = newNode;
        }
        counter++;
    }

    // Append new element to the list with the Node
    void append(Node *newNode) override {
        Node *current, *modifiedNode;

        modifiedNode = new Node(newNode->value);

        if (!counter) {
            head = last = modifiedNode;
        }
        else {
            current = last;
            while (current->next)
                current = current->next;
            current->next = modifiedNode;
            last = modifiedNode;
        }
        counter++;
    }

    // Duplicate the Node
    void duplicate(Node *newNode) override {
        append(newNode);
    }

    // Remove the Node
    Node *remove(Node *entry) override {

        if (head == entry) {
            head = entry->next;
            delete entry;
            counter--;
            if (head != NULL)
                return head->next;
            else {
                head = last = new Node();
                return head;
            }
        }
        else {
            Node *current = head;

            while (current->next && current->next != entry)
                current = current->next;

            if (current->next != NULL) {
                current->next = entry->next;
                if (entry == last)
                    last = current;
                delete entry;
                counter--;
                return current->next;
            }
            else
                throw Error("Could not find the entry");
        }
    }

    // Get the length of the list
    size_t length(void) const noexcept override {
        return counter;
    }

    // Find a first Node with the given value
    Node *get(K val) const override {
        Node *current = head;

        while (current->next) {
            if (current->value == val)
                return current;
            current = current->next;
        }
        if (current->value == val)
            return current;
        else
            throw Error("Could not find an entry", 404);
    }

    Node *get_head() const noexcept override {
        return head;
    }

    // Remove all the elements from the list
    void clear(void) {
        Node *current;
        if (counter == 1) current = head;
        else current = head->next;

        if (counter) {
            while (current->next)
                current = remove(current);

            if (counter > 1) {
                delete head->next;
                counter--;
                delete head;
                counter--;
            }
            else {
                delete head;
                counter--;
            }
        }
    }

    // Indexing operator
    K& operator[](size_t index) const override {
        Node *current = ComparableList<K>::get_head();
        size_t i = 0;
        if (!counter || index >= counter)
            throw Error("Nonexistent key given");

        while (current->next) {
            if (index == i++)
                return current->value;
            
            current = current->next;
        }
        return current->value;
    }

    // Check if the value is present in the list or not
    bool exists(K entry) const override {
        auto flag = false;
        Node *current = head;

        while (current->next) {
            if (current->value == entry)
                return true;
            current = current->next;
        }
        if (current->value == entry)
            flag = true;
        return flag;
    }

    size_t index(K entry) const override {
        Node *current = head;
        size_t i {};

        while (current->next) {
            if (current->value == entry)
                return i;
            i++;
            current = current->next;
        }
        if (current->value == entry)
            return i;
        else
            throw Error("Could not find an entry", 404);
    }

    K min(void) const {
        Node *current = head;
        K result = current->value;

        while (current->next) {
            if (current->value < result)
                result = current->value;
            current = current->next;
        }
        if (current->value < result)
            result = current->value;

        return result;
    }
    
    K max(void) const {
        Node *current = head;
        K result = current->value;
        
        while (current->next) {
            if (current->value > result)
                result = current->value;
            current = current->next;
        }
        if (current->value > result)
            result = current->value;

        return result;
    }
};
#endif
