#include <iostream>
#include <cstdint>
#include <string>
#include "metaclasses.hpp"

#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

// Dictionary data structure
template <typename N>
class Dictionary {
private:
    DS::KeyNode<N>* head = nullptr;
    DS::KeyNode<N>* last = nullptr;
    size_t counter = 0;

public:
    // Empty constructor
    Dictionary<N>(void) { }

    // Constructor with the first element as the argument
    Dictionary(std::string k, N val) {
        Append(k, val);
    }

    // Constructor with the first Node as the argument
    Dictionary(DS::KeyNode<N>* newNode) {
        DS::KeyNode<N> *modifiedNode = new DS::KeyNode<N>(newNode->key, newNode->value);
        head = last = modifiedNode;
        counter++;
    }

    // Constructor for creating copies
    Dictionary(const Dictionary& anotherDictionary) {
        DS::KeyNode<N> *current = anotherDictionary.GetHead();

        while (current->next) {
            Append(current->key, current->value);
            current = current->next;
        }
        if (current != nullptr)
            Append(current->key, current->value);
    }

    // Destructor
    ~Dictionary() {
        Clear();
    }

    // Append the element to the dictionary with key and value as arguments
    void Append(std::string key, N val) {
        if (KeyExists(key))
            throw Error("An element with this key already exists");

        DS::KeyNode<N>* newNode, *current;
        newNode = new DS::KeyNode<N>(key, val);

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
    DS::KeyNode<N>* Remove(DS::KeyNode<N>* entry) {

        if (head == entry) {
            head = entry->next;
            delete entry;
            counter--;
            if (head != NULL)
                return head->next;
            else {
                head = last = new DS::KeyNode<N>();
                return head;
            }
        }
        else {
            DS::KeyNode<N> *current = head;

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

    // Get the length of this dictionary
    size_t Length(void) {
        return counter;
    }

    // Get the Node with the given value
    DS::KeyNode<N>* Get(N val) {
        DS::KeyNode<N>* current = head;

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

    // Get the first element of the dictionary
    DS::KeyNode<N>* GetHead() {
        return head;
    }

    // Remove all the elements from the dictionary
    void Clear(void) {
        DS::KeyNode<N>* current;
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

    // Check if the element with the given key exists in dictionary
    bool KeyExists(std::string key) {
        bool flag = false;
        DS::KeyNode<N>* current = head;

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
    N& operator[](size_t index) {
        DS::KeyNode<N>* current = head;
        size_t i = 0;
        if (!(*this).Length() || index >= (*this).Length())
            throw Error("Nonexistent key given");

        while (current->next) {
            if (index == i++)
                return current->value;
            
            current = current->next;
        }
        return current->value;
    }

    // Mapping operator (Get the element by its key)
    N& operator[](std::string search) {
        DS::KeyNode<N>* current = head;
        if (!KeyExists(search))
            throw Error("Nonexistent key given");

        while (current->next) {
            if (search == current->key)
                return current->value;
            current = current->next;
        }
        if (search == current->key)
            return current->value;
        else
            throw Error("Not found");
    }
};
#endif
