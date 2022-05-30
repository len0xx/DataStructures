#include <iostream>
#include <cstdint>
#include <string>
#include <climits>
#include <cstring>
#include <stdio.h>

#ifndef _METACLASSES_H_
#define _METACLASSES_H_

// Data structure namespace
namespace DS {
    template <typename T>
    class Node {
    public:
        T value;
        Node *next = nullptr;
        Node *prev = nullptr;

        Node(void) { }

        Node(T v) : value {v} { }

        Node(T v, Node* anc) : value {v}, next {anc} { }
    };
    
    template <typename T>
    class KeyNode {
    public:
        T value;
        std::string key;
        KeyNode *next = nullptr;

        KeyNode(void) { }

        KeyNode(T v, KeyNode* anc) : value {v}, next {anc} { }
        
        KeyNode(std::string k, T v) : key {k}, value {v} { }
    };
    
    template <typename T>
    class TreeNode {
    public:
        T value;
        TreeNode *prev = nullptr;
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;

        TreeNode(void) { }

        TreeNode(T v) : value {v} { }

        TreeNode(T v, TreeNode* anc) : value {v}, prev {anc} { }
    };
}
#endif
