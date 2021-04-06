#include <iostream>
#include <cstdint>
#include <string>
#include "metaclasses.hpp"

#ifndef _STACK_FIFO_H_
#define _STACK_FIFO_H_

template <typename K>
class StackFIFO {
private:
    DS::Node<K> *head, *last;
    size_t counter;

public:
    // Empty constructor
    StackFIFO(void) {
        head = last = nullptr;
        counter = 0;
    }

    // Constructor with the first element as the argument
    StackFIFO(K val) {
        head = last = new DS::Node<K>(val);
    }

    // Insert the element to the end of the stack
    size_t insert(K val) {
        if (!counter) {
            head = last = new DS::Node<K>(val);
            return ++counter;
        }
        else {
            DS::Node<K> *entry = new DS::Node<K>(val);
            last->next = entry;
            last = entry;
            return ++counter;
        }
    }

    // Pop the element from the beginning of the stack and return it
    K *pop(void) {
        if (!counter)
            throw Error("The stack is empty");
        
        DS::Node<K> ret = head;
        head = head->next;
        counter--;
        return &ret->value;
    }

    // Get the length of the stack
    size_t length(void) const noexcept {
        return counter;
    }

    // Get the first element in the stack
    DS::Node<K> *get_head(void) const noexcept {
        return head;
    }
};
#endif
