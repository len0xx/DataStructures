#include <iostream>
#include <cstdint>
#include <string>
#include "metaclasses.hpp"

#ifndef _STACK_H_
#define _STACK_H_

// Last-in-first-out stack based on the linked list
template <typename K>
class Stack {

using Node = DS::Node<K>;

private:
   Node *head, *last;
    size_t counter;

public:
    // Default constructor
    Stack(void) {
        head = last = nullptr;
        counter = 0;
    }

    // Constructor with the first element as the argument
    Stack(K val) {
        head = last = new Node(val);
    }

    // Insert the element to the end of the stack
    size_t insert(K val) {
        if (!counter) {
            head = last = new Node(val);
            return ++counter;
        }
        else {
            Node *entry = new Node(val);
            last->next = entry;
            last = entry;
            return ++counter;
        }
    }

    // Pop the element from the end of the stack and return it
    K *pop(void) {
        if (!counter)
            throw Error("The stack is empty");
            
       Node *node = head, *ret;
        while (node->next != last)
            node = node->next;

        last = node;
        ret = node->next;
        node->next = nullptr;
        counter--;
        return &ret->value;
    }

    // Get the length of the stack
    size_t length(void) const noexcept {
        return counter;
    }

    // Get the first element in the stack
   Node *get_head(void) const noexcept {
        return head;
    }
};
#endif
