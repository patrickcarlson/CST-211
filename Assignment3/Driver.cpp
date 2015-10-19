/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/18/2015
* Last Modification Date:	10/18/2015
* Assignment Number:    CST 211 Assignment 3
* Filename:				Driver.cpp
*
* Overview:
*	This file constains functions utilized to test the
*	Linked List class, including Node and iterator classes
*
* Input:
*	Tester does not take input.
*
* Output:
*	Output is seen by adding breaks for debugging. Lists
*	are output to console for testing purposes
************************************************************/

#include "LinkedList.h"
#include <iostream>

using namespace std;

void main()
{
	LinkedList<int> newList;

	int newInt = 5;

	newList.Append(&newInt);

	newInt = 8;

	newList.Append(&newInt);

	newInt = 10;

	newList.Prepend(&newInt);

	for (Iterator<int> i = newList.Begin(); i != newList.End(); ++i)
	{
		cout << *i << " ";
	}

	LinkedList<int> otherList;
	otherList = newList;

	for (Iterator<int> i = otherList.Begin(); i != otherList.End(); ++i)
	{
		cout << *i << " ";
	}

	newList.Extract(8);

	for (Iterator<int> i = newList.Begin(); i != newList.End(); ++i)
	{
		cout << *i << " ";
	}

	newList.Purge();

	for (Iterator<int> i = newList.Begin(); i != newList.End(); ++i)
	{
		cout << *i << " ";
	}

	LinkedList<int> anotherList(otherList);

	for (Iterator<int> i = otherList.Begin(); i != otherList.End(); ++i)
	{
		cout << *i << " ";
	}

}
