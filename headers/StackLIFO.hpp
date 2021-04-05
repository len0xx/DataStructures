#include <iostream>
#include <cstdint>
#include <string>
#ifndef METACLASSES
#include "metaclasses.hpp"
#endif

#define STACKLIFO 1

using namespace std;

// Last-in-first-out stack data structure
template <typename K>
class StackLIFO {
private:
    DS::Node<K> *head, *last;
    size_t counter;

public:
    // Empty constructor
    StackLIFO(void) {
        head = last = nullptr;
        counter = 0;
    }

    // Constructor with the first element as the argument
    StackLIFO(K val) {
        head = last = new DS::Node<K>(val);
    }

    // Insert the element to the end of the stack
    size_t insert(K val) {
        if (!counter) {
            head = last = new DS::Node<K>(val);
            return ++counter;
        }
        else {
            auto entry = new DS::Node<K>(val);
            last->next = entry;
            last = entry;
            return ++counter;
        }
    }

    // Pop the element from the end of the stack and return it
    K *pop(void) {
        if (!counter)
            throw Error("The stack is empty");
            
        DS::Node<K> *node = head, *ret;
        while (node->next != last)
            node = node->next;

        last = node;
        ret = node->next;
        node->next = nullptr;
        counter--;
        return &ret->value;
    }

    // Get the length of the stack
    size_t length(void) {
        return counter;
    }

    // Get the first element in the stack
    DS::Node<K> *get_head(void) {
        return head;
    }
};
