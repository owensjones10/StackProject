#include <iostream>
#include "../include/myStack.h"

using namespace std;

int main()
{
    // Create two stacks of integers
    stackType<int> stack1(5);
    stackType<int> stack2(5);

    // Push elements onto stack1
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);

    // Push the same elements onto stack2
    stack2.push(10);
    stack2.push(20);
    stack2.push(30);

    // Compare the stacks
    if (stack1 == stack2)
    {
        cout << "stack1 and stack2 are equal." << endl;
    }
    else
    {
        cout << "stack1 and stack2 are not equal." << endl;
    }

    // Modify stack2
    stack2.pop();
    stack2.push(40);

    // Compare again
    if (stack1 == stack2)
    {
        cout << "stack1 and stack2 are equal." << endl;
    }
    else
    {
        cout << "stack1 and stack2 are not equal." << endl;
    }

    return 0;
}
