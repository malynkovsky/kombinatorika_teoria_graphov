#include "priorityQueueL.h"
#include <iostream> 
using namespace std;
int main() {
    PriorityQueueL test;
    for (int i = 0; i < 10; i+= 1)
    {
        test.push((i*i - 25*(i-2)));
    }
    cout << "Test queue" << endl;
    cout << test << endl;

    cout << "Check isImpty()" << endl;
    cout << test.isEmpty() << endl;

    cout << "Check top()" << endl;
    cout << test.top() << endl;
    test.pop();
    cout << "Check top after pop()" << endl;
    cout << test.top() << endl;

    cout << "Check: let top = 666" << endl;
    test.top() = 666;
    cout << test.top() << endl;

    for (int i = 0; i < 9; i += 1)
        test.pop();

    cout << "Check isImpty() after pop all elements" << endl;
    cout << test.isEmpty() << endl;

    cout << "Let's try pop() with EMPTY queue: " << endl;
    try {
        test.pop();
    }
    catch (const runtime_error& error) {
        cout << "  " << error.what() << endl;
    }

    cout << "Let's try Top() with EMPTY queue: " << endl;
    try {
        test.top();
    }
    catch (const runtime_error& error) {
        cout << "  " << error.what() << endl;
    }

    int k;
    cin >> k;
    return 0;
}