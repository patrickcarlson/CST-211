/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/1/2015
* Last Modification Date:	10/3/2015
* Assignment Number:    CST 211 Assignment 1
* Filename:				Tester.cpp
*
* Overview:
*	This file constains functions utilized to test the
*	Array class and Exception class.
*
* Input:
*	Tester does not take input.
*
* Output:
*	Output is seen by adding breaks for debugging. Output 
*	is a series of ints from -5 to 4, and again but with a 
*	12 replacing the -1. Then two error messages are displayed.
*	Index out of bounds and Length must be Greater than 0, 
*	respectively.
************************************************************/
#include <iostream>
#include "Array.h"
#include "Exception.h"

using namespace std;

// Constructor testing function
void constructortest(int x, int y);

// copy constructor testing function
template <typename T>
void copyconstructortest(Array<T> a);

// assignment operator overload testing function
void assignmenttest();

// subscript operator overload testing function
void subscripttest();

// Exception handling testing
void exceptiontesting();

void main()
{
	Array<int> a(10, 0);
	
	constructortest(10, 0);

	copyconstructortest(a);

	assignmenttest();

	subscripttest();

	exceptiontesting();

};

/*******************************************************************
*	Purpose:		Testing the two argument constructor for the
*					Array class.
*
*	Entry:			Call constructortest function with arguments, 
*					int x and int y.
*
*	Exit:			Does not return any value.
*
********************************************************************/
void constructortest(int x, int y)
{
	Array<int> b(10, 0);
}

/*******************************************************************
*	Purpose:		Testing the copy constructor for the Array 
*					class.
*
*	Entry:			Call copyconstructortest function with argument 
*					Array<T> a.
*
*	Exit:			Does not return any value.
*
********************************************************************/
template <typename T>
void copyconstructortest(Array<T> a)
{
	Array<T> b(a);
	
}

/*******************************************************************
*	Purpose:		Testing the assignment operator overload function
*
*	Entry:			Call assignmenttest with no arguments.
*
*	Exit:			Does not return any value.
*
********************************************************************/
void assignmenttest()
{
	Array<int> a(10, -5);

	Array<int> b(15, 5);

	b = a;
}

/*******************************************************************
*	Purpose:		Testing the subscript operator overload for the 
*					Array class.
*
*	Entry:			Call the subscripttest function.
*
*	Exit:			Does not return any value.
*
********************************************************************/
void subscripttest()
{
	Array<int> a(10, -5);

	for (int i = -5; i < (a.getStartIndex() + a.getLength()); i++)
	{
		a[i] = i;
	}

	for (int i = -5; i < (a.getStartIndex() + a.getLength()); i++)
	{
		cout << a[i] << endl;

	}

	a[-1] = 12;

	for (int i = -5; i < (a.getStartIndex() + a.getLength()); i++)
	{
		cout << a[i] << endl;

	}
}

/*******************************************************************
*	Purpose:		Testing exception handling in Array class, utilizing
*					Exception class.
*
*	Entry:			Call exceptiontesting function with no arguments.
*
*	Exit:			Does not return any value.
*
********************************************************************/
void exceptiontesting()
{
	try{
		Array<int> a(10, 0);

		cout << a[-2];
	}
	
	catch(Exception except)
	{
		cout << except << endl;
	}

	try{
		Array<int> a(0, 0);

		cout << a[-2];
	}

	catch (Exception except)
	{
		cout << except << endl;
	}
}