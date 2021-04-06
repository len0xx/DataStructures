#include <iostream>
#include <cstdint>
#include <string>
#include "metaclasses.hpp"

#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

// Binary tree data structure
class BinaryTree {
private:
    DS::TreeNode* head;
    size_t counter;

public:
    // Empty constructor
    BinaryTree(void) {
        head = nullptr;
        counter = 0;
    }

    // Constructor with the first element as the argument
    BinaryTree(int val) {
        head = nullptr;
        counter = 0;
        append(val);
    }

    // Append the element to the tree
    void append(int val) {
        if (!counter) {
            head = new DS::TreeNode(val);
            counter++;
        }
        else {
            DS::TreeNode *next = head, *prev;
            while(next != nullptr) {
                prev = next;
                if (val > next->value)
                    next = next->right;
                else
                    next = next->left;
            }

            if (val > prev->value)
                prev->right = new DS::TreeNode(val, prev);
            else
                prev->left = new DS::TreeNode(val, prev);

            counter++;
        }
    }

    // Find the element with the given value in the tree
    DS::TreeNode* search(int val) {
        DS::TreeNode *next = head;
        while(next != nullptr) {
            if (val > next->value)
                next = next->right;
            else if (val < next->value)
                next = next->left;
            else
                return next;
        }
        throw Error("Not found");
    }

    // Find the smallest value in the tree
    int minimum(void) {
        DS::TreeNode *next = head;
        while (next->left != nullptr) {
            next = next->left;
        }
        return next->value;
    }

    // Find the largest value in the tree
    int maximum(void) {
        DS::TreeNode *next = head;
        while (next->right != nullptr) {
            next = next->right;
        }
        return next->value;
    }

    // Remove the element from the tree
    DS::TreeNode* remove(DS::TreeNode* node) {
        if (node->left == nullptr && node->right == nullptr) {
            DS::TreeNode *p = node->prev;
            if (p->left == node)
                p->left = nullptr;
            else
                p->right = nullptr;
            counter--;
            return p;
        }
        else if (node->left != nullptr && node->right != nullptr) {
            DS::TreeNode *p, *pr;
            DS::TreeNode *l = node->left, *r = node->right;
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
            DS::TreeNode *p = node->prev;
            DS::TreeNode *entry = node->left != nullptr ? node->left : node->right;

            p->left == node ? p->left = entry : p->right = entry;

            counter--;
            return entry;
        }
    }

    // Get the root element of the tree
    DS::TreeNode* get_head(void) {
        return head;
    }
};
#endif
