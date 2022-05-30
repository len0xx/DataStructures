#include <iostream>
#include <cstdint>
#include <string>
#include "metaclasses.hpp"

#ifndef _X_STRING_H_
#define _X_STRING_H_

// A simple string class implementation based on the linked list
class String {

using Character = DS::Node<char>;

private:
    Character *head = nullptr;
    Character *last = nullptr;
    size_t counter = 0;

public:

    // Default constructor
    String(void) = delete;

    // Construct strings from char*
    String(char* str) {
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
    String(std::string thestr) : String(thestr.c_str()) { }

    // Construct strings from const char*
    String(const char *thestr) : String(const_cast<char*>(thestr)) { }
  
    // Destructor
    ~String() { }

    // Get the length of the list
    size_t length(void) const noexcept {
        return counter;
    }

    // Convert String to char[]
    operator char*(void) const {
        char *result = new char[length() + 1];
        size_t i = 0;
        for (i = 0; i < length(); result[i] = (*this)[i], i++);
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
