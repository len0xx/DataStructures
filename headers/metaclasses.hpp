#include <iostream>
#include <cstdint>
#include <string>
#include <climits>
#include <cstring>
#include <stdio.h>

#define METACLASSES 1

using namespace std;

// A basic error class for throwing exceptions
class Error {
    public:
    string text;
    int code = 0;

    Error(string txt) {
        text = txt;
    }

    Error(int i) {
        code = i;
    }

    Error(string txt, int i) {
        text = txt;
        code = i;
    }
};

// Data structure namespace
namespace DS {
    template <typename T>
    class Node {
    public:
        T value;
        Node *next;

        Node(void) {
            next = nullptr;
        }

        Node(T v) {
            value = v;
            next = nullptr;
        }

        Node(T v, Node* anc) {
            value = v;
            next = anc;
        }
    };
    
    template <typename T>
    class KeyNode {
    public:
        T value;
        string key;
        KeyNode *next;

        KeyNode(void) {
            next = nullptr;
        }

        KeyNode(T v) {
            value = v;
            next = nullptr;
        }

        KeyNode(T v, KeyNode* anc) {
            value = v;
            next = anc;
        }

        KeyNode(string k, T v) {
            key = k;
            value = v;
        }
    };
    
    class TreeNode {
    public:
        int value;
        TreeNode *prev;
        TreeNode *left;
        TreeNode *right;

        TreeNode(void) {
            prev = nullptr;
            left = nullptr;
            right = nullptr;
        }

        TreeNode(int v) {
            value = v;
            prev = nullptr;
            left = nullptr;
            right = nullptr;
        }

        TreeNode(int v, TreeNode* anc) {
            value = v;
            prev = anc;
            left = nullptr;
            right = nullptr;
        }
    };
}
