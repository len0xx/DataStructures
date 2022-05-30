#include <stdio.h>
#include <iostream>
#include "Stack.hpp"
#include "Queue.hpp"

using namespace std;

int main(int argc, char **argv) {
    // Initializing the LIFO Stack
    Stack<unsigned int> addresses;

    // Initializing the FIFO Stack
    Queue<char> serial_port;

    // Inserting some elements to the LIFO stack
    addresses.insert(0x02FA); // 762
    addresses.insert(0x0010); // 16
    addresses.insert(0x0FFC); // 4092
    addresses.insert(0x0091); // 145

    // Showcasing LIFO stack methods:
    cout << "LIFO Stack:" << endl;
    cout << "Length of the stack before popping: " << addresses.length() << endl;
    auto out_from_LIFO = *(addresses.pop());
    cout << "The last inserted element is: " << out_from_LIFO << endl;
    cout << "Length of the stack after popping: " << addresses.length() << endl;

    // Inserting some elements to the FIFO stack
    serial_port.insert('M');
    serial_port.insert('e');
    serial_port.insert('m');
    serial_port.insert('o');
    serial_port.insert('r');
    serial_port.insert('y');

    // Showcasing FIFO stack methods:
    cout << "FIFO Stack:" << endl;
    cout << "Length of the stack before popping: " << serial_port.length() << endl;
    auto out_from_FIFO = *(serial_port.pop());
    cout << "The first inserted element is: " << out_from_FIFO << endl;
    cout << "Length of the stack after popping: " << serial_port.length() << endl;

    return 0;
}