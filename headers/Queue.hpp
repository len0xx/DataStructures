#include <iostream>
#include <cstdint>
#include <string>
#include "metaclasses.hpp"

#ifndef _QUEUE_H_
#define _QUEUE_H_

// Queue class based on the linked list
template <typename K>
class Queue {
    
using Node = DS::Node<K>;

private:
    Node *head, *last;
    size_t counter;

public:
    // Default constructor
    Queue(void) {
        head = last = nullptr;
        counter = 0;
    }

    // Constructor with the first element as the argument
    Queue(K val) {
        head = last = new Node(val);
    }

    // Insert the element to the end of the queue
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

    // Pop the element from the beginning of the queue and return it
    K *pop(void) {
        if (!counter)
            throw Error("The queue is empty");
        
        Node *ret = head;
        head = head->next;
        counter--;
        return &ret->value;
    }

    // Get the length of the queue
    size_t length(void) const noexcept {
        return counter;
    }

    // Get the first element in the queue
    Node *get_head(void) const noexcept {
        return head;
    }
};
#endif
