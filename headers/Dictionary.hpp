#include <iostream>
#include <cstdint>
#include <string>
#include "metaclasses.hpp"

#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

// Dictionary data structure based on the linked list
template <typename N>
class Dictionary {

using Node = DS::KeyNode<N>;

private:
    Node *head = nullptr;
    Node *last = nullptr;
    size_t counter = 0;

public:
    // Default constructor
    Dictionary<N>(void) { }

    // Constructor with the first element as the argument
    Dictionary(std::string k, N val) {
        append(k, val);
    }

    // Constructor with the first Node as the argument
    Dictionary(Node *newNode) {
        Node *modifiedNode = new Node(newNode->key, newNode->value);
        head = last = modifiedNode;
        counter++;
    }

    // Constructor for creating copies
    Dictionary(const Dictionary& anotherDictionary) {
        Node *current = anotherDictionary.GetHead();

        while (current->next) {
            append(current->key, current->value);
            current = current->next;
        }
        if (current != nullptr)
            append(current->key, current->value);
    }

    // Destructor
    ~Dictionary() {
        clear();
    }

    // Append the element to the dictionary with key and value as arguments
    void append(std::string key, N val) {
        if (key_exists(key))
            throw std::runtime_error("An element with this key already exists");

        Node *newNode, *current;
        newNode = new Node(key, val);

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

    // Remove the given Node from the dictionary
    Node *remove(Node *entry) {

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
                throw std::runtime_error("Could not find the entry");
        }
    }

    // Get the length of this dictionary
    size_t length(void) const noexcept {
        return counter;
    }

    // Get the Node with the given value
    Node *get(N val) const {
        Node *current = head;

        while (current->next) {
            if (current->value == val)
                return current;
            current = current->next;
        }
        if (current->value == val)
            return current;
        else
            throw std::runtime_error("Could not find an entry");
    }

    // Get the first element of the dictionary
    Node *get_head() const noexcept {
        return head;
    }

    // Remove all the elements from the dictionary
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

    // Check if the element with the given key exists in dictionary
    bool key_exists(std::string key) const {
        bool flag = false;
        Node *current = head;

        if (!counter) return false;

        while (current->next) {
            if (current->key == key)
                flag = true;
            current = current->next;
        }
        if (current->key == key)
            flag = true;
        return flag;
    }

    // Indexing operator
    N& operator[](size_t index) const {
        Node *current = head;
        size_t i = 0;
        if (!(*this).length() || index >= (*this).length())
            throw std::runtime_error("Nonexistent key given");

        while (current->next) {
            if (index == i++)
                return current->value;
            
            current = current->next;
        }
        return current->value;
    }

    // Mapping operator (Get the element by its key)
    N& operator[](std::string search) const {
        Node *current = head;
        if (!key_exists(search))
            throw std::runtime_error("Nonexistent key given");

        while (current->next) {
            if (search == current->key)
                return current->value;
            current = current->next;
        }
        if (search == current->key)
            return current->value;
        else
            throw std::runtime_error("Not found");
    }
};
#endif
