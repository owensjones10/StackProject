//Header file: myStack.h
#ifndef H_StackType 
#define H_StackType 
 
#include <iostream>
#include <cassert>
#include "stackADT.h"

using namespace std;
  
template <class Type>
class stackType: public stackADT<Type>
{
public:
    const stackType<Type>& operator=(const stackType<Type>&); 
      //Overload the assignment operator.

    void initializeStack();
      //Function to initialize the stack to an empty state.
      //Postcondition: stackTop = 0

    bool isEmptyStack() const;
      //Function to determine whether the stack is empty.
      //Postcondition: Returns true if the stack is empty,
      //               otherwise returns false.

    bool isFullStack() const;
      //Function to determine whether the stack is full.
      //Postcondition: Returns true if the stack is full,
      //               otherwise returns false.

    void push(const Type& newItem);
      //Function to add newItem to the stack.
      //Precondition: The stack exists and is not full.
      //Postcondition: The stack is changed and newItem 
      //               is added to the top of the stack.

    Type top() const;
      //Function to return the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: If the stack is empty, the program 
      //               terminates; otherwise, the top element
      //               of the stack is returned.

    void pop();
      //Function to remove the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: The stack is changed and the top 
      //               element is removed from the stack.

    stackType(int stackSize = 100); 
      //Constructor
      //Postcondition: The variable list contains the base
      //               address of the array, stackTop = 0, and  
      //               maxStackSize = stackSize.

    stackType(const stackType<Type>& otherStack); 
      //Copy constructor

    ~stackType(); 
      //Destructor
      //Postcondition: The array (list) holding the stack 
      //               elements is deleted.
      
    bool operator==(const stackType<Type>& otherStack) const;
      //Overload the equality operator.

private:
    int maxStackSize; //Variable to store the maximum stack size
    int stackTop;     //Variable to point to the top of the stack
    Type *list;       //Pointer to the array that holds the stack elements

    void copyStack(const stackType<Type>& otherStack); 
      //Function to make a copy of otherStack.
      //Postcondition: A copy of otherStack is created and
      //               assigned to this stack.
};


template <class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
}

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    return(stackTop == 0);
}

template <class Type>
bool stackType<Type>::isFullStack() const
{
    return(stackTop == maxStackSize);
}

template <class Type>
void stackType<Type>::push(const Type& newItem)
{
    if (!isFullStack())
    {
        list[stackTop] = newItem;   //Add newItem to the top of the stack
        stackTop++;                //Increment stackTop
    }
    else
        cout << "Cannot add to a full stack." << endl;
}

template <class Type>
Type stackType<Type>::top() const
{
    assert(stackTop != 0);          //If stack is empty, terminate the program
    return list[stackTop - 1];      //Return the element of the stack
}

template <class Type>
void stackType<Type>::pop()
{
    if (!isEmptyStack())
        stackTop--;                 //Decrement stackTop 
    else
        cout << "Cannot remove from an empty stack." << endl;
}

template <class Type>
stackType<Type>::stackType(int stackSize) 
{
    if (stackSize <= 0)
    {
        cout << "Size of the array to hold the stack must "
             << "be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        maxStackSize = 100;
    }
    else
        maxStackSize = stackSize;   //Set the stack size to the value specified

    stackTop = 0;                   //Set stackTop to 0
    list = new Type[maxStackSize];  //Create the array to hold the stack elements
}

template <class Type>
stackType<Type>::~stackType() //Destructor
{
    delete [] list; //Deallocate the memory occupied by the array
}

template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{ 
    delete [] list; //Release current resources if any				   
    maxStackSize = otherStack.maxStackSize;		   
    stackTop = otherStack.stackTop;			   
	  
    list = new Type[maxStackSize]; //Allocate new memory		   			   

    for (int j = 0; j < stackTop; j++)  
        list[j] = otherStack.list[j]; //Copy otherStack into this stack
}

template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
    list = nullptr;

    copyStack(otherStack);
}

template <class Type>
const stackType<Type>& stackType<Type>::operator=
   					(const stackType<Type>& otherStack)
{ 
    if (this != &otherStack) //Avoid self-copy
        copyStack(otherStack);

    return *this; 
} 

template <class Type>
bool stackType<Type>::operator==(const stackType<Type>& otherStack) const {
    if (stackTop != otherStack.stackTop)
        return false; //Different number of elements

    for (int i = 0; i < stackTop; i++) {
        if (list[i] != otherStack.list[i])
            return false; //Mismatched elements
    }

    return true; //Stacks are equal
}

#endif