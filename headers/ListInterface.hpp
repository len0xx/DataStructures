#include <iostream>
#include <cstdint>
#include <string>
#include "metaclasses.hpp"

#ifndef _LIST_INTERFACE_H_
#define _LIST_INTERFACE_H_

// Interface for lists
template <typename K>
class ListInterface {
public:
    // Destructor
    virtual ~ListInterface() = default;

    // Append new element to the list with the value
    virtual void append(K val) = 0;

    // Append new element to the list with the Node
    virtual void append(DS::Node<K> *newNode) = 0;

    // Remove the element in the list by Node and return new element at this index
    virtual DS::Node<K> *remove(DS::Node<K> *entry) = 0;

    // Get the length of the list
    virtual size_t length(void) const noexcept = 0;

    // Find a first Node with the given value
    virtual DS::Node<K> *get(K val) const = 0;

    virtual DS::Node<K> *get_head() const noexcept = 0;

    // Remove all the elements from the list
    virtual void clear(void) = 0;

    // Indexing operator
    virtual K& operator[](size_t index) const = 0;

    // Check if the value is present in the list or not
    virtual bool exists(K entry) const = 0;

    // Get the index of the given entry
    virtual size_t index(K entry) const = 0;
};
#endif
