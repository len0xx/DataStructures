#include <iostream>
#include <chrono>
#include <random>
#include <iomanip>
#include "../headers/BinarySearchTree.hpp"
#include "../headers/List.hpp"
#include "StopWatch.hpp"

using namespace std;

// This test demonstrates the perfomance of BinarySearchTree 
// over the List and regular C-like array
// in terms of searching the elements

// In BinarySearchTree search operations performs 75 times quicker
// than in a regular C-like array

int main() {
    random_device rd;                                   // non-deterministic generator
    mt19937 gen(rd());                                  // to seed mersenne twister.
    uniform_int_distribution<> dist(1, 2'000'000'000);  // distribute results between 1 and 2'000'000'000 inclusive.

    size_t A = 50000;
    int arr[A];
    List<int> list = List<int>();
    BinarySearchTree tree = BinarySearchTree();
    try {
        for (int i = 0; i < A; ++i) {
            uint32_t num = dist(gen);
            if (!list.exists(num)) {
                arr[i] = num;
                list.append(num);
                tree.append(num);
            }
        }

        StopWatch sw {};
        for (int i = 2000; i < 9000; ++i) {
            int a = 0;
            for (int j = 0; j < A; j++) {
                if (arr[j] == arr[i]) {
                    a = 1;
                    break;
                }
            }
        }
        cout << fixed << setprecision(7)
        << "Linear search (continious memory) took " << sw.mark_s() << " seconds" << endl;

        for (int i = 2000; i < 9000; ++i) {
            list.index(arr[i]);
        }
        cout << "Linear search (linked list) took " << sw.mark_s() << " seconds" << endl;

        for (int i = 2000; i < 9000; ++i) {
            tree.search(arr[i]);
        }
        cout << "Binary tree search took " << sw.mark_s() << " seconds" << endl;
    }
    catch (const runtime_error &e) {
        cout << "An error occurred: " << e.what() << endl;
    }
}