/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/24/2015
* Last Modification Date:	10/25/2015
* Assignment Number:    CST 211 Assignment 4
* Filename:				Driver.cpp
*
* Overview:
*	This file constains functions utilized to test the
*	Stack class, including LinkedList, Node, and iterator
*	classes.
*
* Input:
*	Driver does not take input.
*
* Output:
*	Output is seen by adding breaks for debugging. Stack is
*	output to console for debugging.
************************************************************/

#include "Stack.h"
#include <iostream>

using namespace std;

// Test constructor capability
void instantiateStack();

// Test Push funtion, as well as copy constructor
Stack<int> pushTest(Stack<int>& someStack);

// Test Pop Function
Stack<int> popTest(Stack<int>& someStack);

// Test bool returns of isFull, isEmpty
void emptyFullTest(Stack<int>& intStack, Stack<char>& charStack);

// Test assignment operator functionality
void assignmentTest(Stack<int> intStack);

void main()
{
	
	
	instantiateStack();

	Stack<int> newStack(5);

	pushTest(newStack); // Return by value tests copy constructor

	popTest(newStack);
	
	// Test Peek functionality
	int peeky = newStack.Peek();


	newStack.Push(5);

	Stack<char> newCharStack(10);

	emptyFullTest(newStack, newCharStack);

	assignmentTest(newStack);
									

}

/**************************************************************
*		Purpose:	Constructor operator test
*		
*		Entry:
*	
*		Exit: 
***************************************************************/
void instantiateStack()
{
	Stack<int> newStack(5);
	// Note: Constructor successful.
}

/****************************************************************
*		Purpose:	Push member function tester
*
*		Entry:	Stack to be pushed upon.
*
*		Exit:	Returns stack by value, which also tests copy
*				constructor.
*****************************************************************/
Stack<int> pushTest(Stack<int>& someStack)
{
	try
	{
		someStack.Push(1);

		someStack.Push(2);

		someStack.Push(3);

		someStack.Push(4);

		someStack.Push(5);
		

		//someStack.Push(6);  //Overflow Exception Test
	}

	catch (Exception& except)
	{
		cout << except << endl;
	}

	return someStack;
}

/****************************************************************
*		Purpose:	Pop member function tester
*
*		Entry:	Stack to be popped
*
*		Exit:	Returns stack by value, which also tests copy
*				constructor.
*****************************************************************/
Stack<int> popTest(Stack<int>& someStack)
{
	someStack.Pop();

	return someStack;
}

/****************************************************************
*		Purpose:	Bool return for isEmpty and isFull tester
*
*		Entry:	Stacks to be tested for full and empty
*
*		Exit:	
*****************************************************************/
void emptyFullTest(Stack<int>& intStack, Stack<char>& charStack)
{
	intStack.isEmpty();

	intStack.isFull();

	charStack.isEmpty();

	charStack.isFull();

	if (!intStack.isEmpty())
		cout << "This int stack is not empty." << endl;

	if (intStack.isFull())
		cout << "This int stack is full" << endl;

	if (charStack.isEmpty())
		cout << "This char stack is empty." << endl;

	if (!charStack.isFull())
		cout << "This char stack is not full" << endl;
}

/****************************************************************
*		Purpose:	Assignment operator test
*
*		Entry:	Stack to be assigned to new Stack
*
*		Exit:	
*****************************************************************/
void assignmentTest(Stack<int> intStack)
{
	Stack<int> newIntStack(25);

	newIntStack = intStack;


}