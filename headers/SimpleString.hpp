#include <iostream>
#include <cstdint>
#include <string>
#include "metaclasses.hpp"

#ifndef _SIMPLE_STRING_H_
#define _SIMPLE_STRING_H_

// A simple string class implementation
class SimpleString {

using Character = DS::Node<char>;

private:
    Character *head = nullptr;
    Character *last = nullptr;
    size_t counter = 0;

public:

    // Default constructor
    SimpleString(void) = delete;

    // Construct strings from char*
    SimpleString(char* str) {
        head = last = nullptr;
        counter = 0;
        size_t i = 0;
        Character *current, *newNode = new Character(str[i++]);
        head = last = newNode;
        counter++;
        while(str[i] != '\0') {
            newNode = new Character(str[i]);
            current = last;
            current->next = newNode;
            last = newNode;
            counter++;
            i++;
        }
    }

    // Construct strings from std::string
    SimpleString(std::string thestr) : SimpleString(thestr.c_str()) { }

    // Construct strings from const char*
    SimpleString(const char *thestr) : SimpleString(const_cast<char*>(thestr)) { }
  
    // Destructor
    ~SimpleString() {
        Character *thenext, *current = head;

        if (counter) {
            while (current->next) {
                thenext = current;
                delete thenext;
                current = current->next;
                counter--;
            }
            delete current;
            counter--;
        }
    }

    // Get the length of the list
    size_t length(void) const noexcept {
        return counter;
    }

    // Convert SimpleString to char[]
    operator char*(void) const {
        char *result = new char[length() + 1];
        for (size_t i = 0; i < length(); result[i] = (*this)[i], i++);
        result[i] = '\0';
        return result;
    }

    // Indexing operator
    char& operator[](size_t index) const {
        Character *current = head;
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
};
#endif
