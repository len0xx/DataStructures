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
    virtual void Append(K val) = 0;

    // Append new element to the list with the Node
    virtual void Append(DS::Node<K> *newNode) = 0;

    // Duplicate the Node
    virtual void Duplicate(DS::Node<K> *newNode) = 0;

    // Remove the Node
    virtual DS::Node<K> *Remove(DS::Node<K> *entry) = 0;

    // Get the length of the list
    virtual size_t Length(void) const noexcept = 0;

    // Find a first Node with the given value
    virtual DS::Node<K> *Get(K val) const = 0;

    virtual DS::Node<K> *GetHead() const noexcept = 0;

    // Remove all the elements from the list
    virtual void Clear(void) = 0;

    // Indexing operator
    virtual K& operator[](size_t index) const = 0;

    // Check if the value is present in the list or not
    virtual bool Exists(K entry) const = 0;
};
#endif
