#include <iostream>
#include <cstdint>
#include <string>
#include "metaclasses.hpp"

#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

// Binary tree data structure
class BinarySearchTree {
private:
    DS::TreeNode<int> *head = nullptr;
    size_t counter = 0;

public:
    // Empty constructor
    BinarySearchTree(void) { }

    // Constructor with the first element as the argument
    BinarySearchTree(int val) {
        append(val);
    }

    // Append the element to the tree
    void append(int val) {
        if (!counter) {
            head = new DS::TreeNode<int>(val);
            counter++;
        }
        else {
            if (exists(val))
                throw Error("An element with this value already exists in a Tree");

            DS::TreeNode<int> *next = head, *prev;
            while(next != nullptr) {
                prev = next;
                if (val > next->value)
                    next = next->right;
                else
                    next = next->left;
            }

            if (val > prev->value)
                prev->right = new DS::TreeNode<int>(val, prev);
            else
                prev->left = new DS::TreeNode<int>(val, prev);

            counter++;
        }
    }

    // Find the element with the given value in the tree
    DS::TreeNode<int> *search(int val) const {
        DS::TreeNode<int> *next = head;
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
        DS::TreeNode<int> *next = head;
        while (next->left != nullptr) {
            next = next->left;
        }
        return next->value;
    }

    // Find the largest value in the tree
    int maximum(void) const {
        DS::TreeNode<int> *next = head;
        while (next->right != nullptr) {
            next = next->right;
        }
        return next->value;
    }

    // Remove the element from the tree
    DS::TreeNode<int>* remove(DS::TreeNode<int>* node) {
        if (node->left == nullptr && node->right == nullptr) {
            DS::TreeNode<int> *p = node->prev;
            if (p->left == node)
                p->left = nullptr;
            else
                p->right = nullptr;
            counter--;
            return p;
        }
        else if (node->left != nullptr && node->right != nullptr) {
            DS::TreeNode<int> *p, *pr;
            DS::TreeNode<int> *l = node->left, *r = node->right;
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
            DS::TreeNode<int> *p = node->prev;
            DS::TreeNode<int> *entry = node->left != nullptr ? node->left : node->right;

            p->left == node ? p->left = entry : p->right = entry;

            counter--;
            return entry;
        }
    }

    // Get the root element of the tree
    DS::TreeNode<int>* get_head(void) const noexcept {
        return head;
    }

    // Get the amount of nodes in the current tree
    size_t length(void) const noexcept {
        return counter;
    }
};
#endif
