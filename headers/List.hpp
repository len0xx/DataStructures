#include <iostream>
#include <cstdint>
#include <string>
#include "stdarg.h"
#ifndef METACLASSES
#include "metaclasses.hpp"
#endif

#define LIST 1

using namespace std;

// Single-linked list data structure
template <typename K>
class List {
private:
    DS::Node<K>* head = nullptr;
    DS::Node<K>* last = nullptr;
    size_t counter = 0;

public:
    // Empty constructor
    List() { }

    // Constructor with the first element as the argument
    List(K val) {
        Append(val);
    }

    // Constructor with the first Node as the argument
    List(DS::Node<K>* newNode) {
        auto modifiedNode = new DS::Node<K>(newNode->value);
        head = modifiedNode;
        last = modifiedNode;
        counter++;
    }

    // Constructor for strings
    List(const char* str) {
        uint32_t i = 0;
        auto newNode = new DS::Node<K>(str[i++]);
        head = newNode;
        last = newNode;
        counter++;
        while(str[i] != '\0') {
            Append(str[i++]);
        }
    }

    // Constructor for creating copies
    List(const List& anotherList) {
        auto current = anotherList.GetHead();

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
    void Append(K val) {
        DS::Node<K>* newNode, * current;
        newNode = new DS::Node<K>(val);

        if (!counter) {
            head = newNode;
            last = newNode;
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
    void Append(DS::Node<K>* newNode) {
        DS::Node<K>* current, * modifiedNode;

        modifiedNode = new DS::Node<K>(newNode->value, newNode->key);

        if (!counter) {
            head = modifiedNode;
            last = modifiedNode;
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
    void Duplicate(DS::Node<K>* newNode) {
        Append(newNode);
    }

    // Remove the Node
    DS::Node<K>* Remove(DS::Node<K>* entry) {

        if (head == entry) {
            head = entry->next;
            delete entry;
            counter--;
            if (head != NULL)
                return head->next;
            else {
                head = new DS::Node<K>();
                last = head;
                return head;
            }
        }
        else {
            auto current = head;

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
    size_t Length(void) const noexcept {
        return counter;
    }

    // Find a first Node with the given value
    DS::Node<K>* Get(K val) const {
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

    DS::Node<K>* GetHead() const noexcept {
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
    K& operator[](size_t index) const {
        auto current = List<K>::GetHead();
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
    bool Exists(K entry) const {
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
