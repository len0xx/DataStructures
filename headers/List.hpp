#include <iostream>
#include <cstdint>
#include "ListInterface.hpp"

#ifndef _LIST_H_
#define _LIST_H_

// Single-linked list data structure which implements ListInterface
template <typename K>
class List : public ListInterface<K> {

using Node = DS::Node<K>;

private:
    Node *head = nullptr;
    Node *last = nullptr;
    size_t counter = 0;

public:
    // Default constructor
    List(void) { }

    // Constructor with the first element as the argument
    List(K val) {
        append(val);
    }

    // Constructor with the array and its length as the arguments
    List(K *val, size_t len) {
        for (size_t j = 0; j < len; ++j)
            append(val[j]);
    }

    // Copy constructor
    List(const List& anotherList) {
        Node *current = anotherList.get_head();

        while (current->next) {
            append(current->value);
            current = current->next;
        }
        if (current != nullptr)
            append(current->value);
    }

    // Destructor
    ~List() {
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
            current->next = modifiedNode;
            last = modifiedNode;
        }
        counter++;
    }

    // Remove the element by Node and return new element at this index
    Node *remove(Node *entry) override {

        if (head == entry) {
            head = entry->next;
            delete entry;
            counter--;
            if (head != nullptr)
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

            if (current->next != nullptr) {
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
        Node *current = List<K>::get_head();
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

        if (!counter) return false;

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

        if (!counter) throw Error("The list is empty");

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
};
#endif
