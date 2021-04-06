#include <iostream>
#include <cstdint>
#include <string>
#include "ListInterface.hpp"

#ifndef _LIST_H_
#define _LIST_H_

// Single-linked list data structure which implements ListInterface
template <typename K>
class List : public ListInterface<K> {
private:
    DS::Node<K>* head = nullptr;
    DS::Node<K>* last = nullptr;
    size_t counter = 0;

public:
    // Empty constructor
    List(void) { }

    // Constructor with the first element as the argument
    List(K val) {
        Append(val);
    }

    // Constructor with the array and its length as the arguments
    List(K *val, size_t len) {
        if (!len)
            throw Error("Array length can't be 0!");

        for (size_t j = 0; j < len; ++j)
            Append(val[j]);
    }

    // Constructor with the first Node as the argument
    List(DS::Node<K>* newNode) {
        DS::Node<K> modifiedNode = new DS::Node<K>(newNode->value);
        head = last = modifiedNode;
        counter++;
    }

    // Constructor for strings
    List(const char* str) {
        size_t i = 0;
        DS::Node<K> newNode = new DS::Node<K>(str[i++]);
        head = last = newNode;
        counter++;
        while(str[i] != '\0') {
            Append(str[i++]);
        }
    }

    // Constructor for creating copies
    List(const List& anotherList) {
        DS::Node<K> *current = anotherList.GetHead();

        while (current->next) {
            Append(current->value);
            current = current->next;
        }
        if (current != nullptr)
            Append(current->value);
    }

    // Destructor
    ~List() {
        Clear();
    }

    // Append new element to the list with the value
    void Append(K val) override {
        DS::Node<K>* newNode, *current;
        newNode = new DS::Node<K>(val);

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
    void Append(DS::Node<K> *newNode) override {
        DS::Node<K>* current, *modifiedNode;

        modifiedNode = new DS::Node<K>(newNode->value);

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
    void Duplicate(DS::Node<K>* newNode) override {
        Append(newNode);
    }

    // Remove the Node
    DS::Node<K>* Remove(DS::Node<K>* entry) override {

        if (head == entry) {
            head = entry->next;
            delete entry;
            counter--;
            if (head != NULL)
                return head->next;
            else {
                head = last = new DS::Node<K>();
                return head;
            }
        }
        else {
            DS::Node<K> *current = head;

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
    size_t Length(void) const noexcept override {
        return counter;
    }

    // Find a first Node with the given value
    DS::Node<K>* Get(K val) const override {
        auto current = head;

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

    DS::Node<K>* GetHead() const noexcept override {
        return head;
    }

    // Remove all the elements from the list
    void Clear(void) {
        DS::Node<K>* current;
        if (counter == 1) current = head;
        else current = head->next;

        if (counter) {
            while (current->next)
                current = Remove(current);

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
        DS::Node<K> *current = List<K>::GetHead();
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
    bool Exists(K entry) const override {
        auto flag = false;
        auto current = head;

        while (current->next) {
            if (current->value == entry)
                return true;
            current = current->next;
        }
        if (current->value == entry)
            flag = true;
        return flag;
    }
};
#endif
