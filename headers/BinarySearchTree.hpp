#include <iostream>
#include <cstdint>
#include <string>
#include "metaclasses.hpp"

#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

// Binary search tree data structure
class BinarySearchTree {

using Node = DS::TreeNode<int>;

private:
    Node *head = nullptr;
    size_t counter = 0;

public:
    // Default constructor
    BinarySearchTree(void) { }

    // Constructor with the first element as the argument
    BinarySearchTree(int val) {
        append(val);
    }

    // Append the element to the tree
    void append(int val) {
        if (!counter) {
            head = new Node(val);
            counter++;
        }
        else {
            if (exists(val))
                throw Error("An element with this value already exists in a Tree");

            Node *next = head, *prev;
            while (next != nullptr) {
                prev = next;
                if (val > next->value)
                    next = next->right;
                else
                    next = next->left;
            }

            if (val > prev->value)
                prev->right = new Node(val, prev);
            else
                prev->left = new Node(val, prev);

            counter++;
        }
    }

    // Find the element with the given value in the tree
    Node *search(int val) const {
        Node *next = head;
        if (!counter)
            throw Error("The tree is empty", 404);
            
        while(next != nullptr) {
            if (val > next->value)
                next = next->right;
            else if (val < next->value)
                next = next->left;
            else
                return next;
        }
        throw Error("Not found", 404);
    }

    // Check if the value is present in the tree or not
    bool exists(int val) const {
        try {
            search(val);
        }
        catch (const Error e) {
            if (e.code == 404)
                return false;
        }
        return true;
    }

    // Find the smallest value in the tree
    int minimum(void) const {
        Node *next = head;
        while (next->left != nullptr) {
            next = next->left;
        }
        return next->value;
    }

    // Find the largest value in the tree
    int maximum(void) const {
        Node *next = head;
        while (next->right != nullptr) {
            next = next->right;
        }
        return next->value;
    }

    // Remove the element from the tree
    Node* remove(Node* node) {
        if (node->left == nullptr && node->right == nullptr) {
            Node *p = node->prev;
            if (p->left == node)
                p->left = nullptr;
            else
                p->right = nullptr;
            counter--;
            return p;
        }
        else if (node->left != nullptr && node->right != nullptr) {
            Node *p, *pr;
            Node *l = node->left, *r = node->right;
            if (node->value < node->prev->value) {
                // Левая ветвь
                p = node->right;
                while (p->left != nullptr) {
                    p = p->left;
                }
                pr = node->prev;
                pr->left = p;
                p->prev->right = nullptr;
                pr->left->left = l;
                pr->left->right = r;
                pr->left->prev = pr;
                return p;
            }
            else {
                // Правая ветвь
                p = node->left;
                while (p->right != nullptr) {
                    p = p->right;
                }
                pr = node->prev;
                pr->right = p;
                p->prev->left = nullptr;
                pr->right->left = l;
                pr->right->right = r;
                pr->right->prev = pr;
                return p;
            }
        }
        else {
            Node *p = node->prev;
            Node *entry = node->left != nullptr ? node->left : node->right;

            p->left == node ? p->left = entry : p->right = entry;

            counter--;
            return entry;
        }
    }

    // Get the root element of the tree
    Node* get_head(void) const noexcept {
        return head;
    }

    // Get the amount of nodes in the current tree
    size_t length(void) const noexcept {
        return counter;
    }
};
#endif
