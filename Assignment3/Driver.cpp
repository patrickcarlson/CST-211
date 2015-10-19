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
