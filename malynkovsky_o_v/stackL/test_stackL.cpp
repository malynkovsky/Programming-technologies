#include "stackL.h"
#include <iostream>

int main() {
    using namespace std;
    StackL example;

    example.push(12);
    example.push(-1);
    example.push(4);
    example.push(44);
    example.push(3);
    example.push(-8);
    example.push(0);
    example.push(76);
    example.push(-52);
    example.push(2);
    cout << "Example stackL: " << endl;
    cout << example << endl << endl;
    cout << endl;
    cout << "Is Example stack empty(must be NO): ";
    cout << example.isEmpty() << endl << endl;

    cout << "Let's try pop(): " << endl;
    example.pop();
    cout << example << endl << endl;
    cout << "Let's try top(): " << endl;
    cout << example.top() << endl << endl;
    cout << "Let's set top() (333): " << endl;
    example.top() = 333;
    cout << example << endl << endl;
    return 0;
}