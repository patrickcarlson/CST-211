/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/8/2015
* Last Modification Date:	10/11/2015
* Assignment Number:    CST 211 Assignment 2
* Filename:				Tester.cpp
*
* Overview:
*	This file constains functions utilized to test the
*	Array2D, Row, and Exception classes.
*
* Input:
*	Tester does not take input.
*
* Output:
*	Output is seen by adding breaks for debugging. Member
*	functions of the classes created are tested in corresponding
*	tester functions. Arrays, and messages, are printed to
*	console.
************************************************************/
#include "Array2D.h"
#include <iostream>


using namespace std;

// print function for 2d arrays
template <typename T>
void print(Array2D<T> myArray);

// Constructor, copy constructor, and assignment operator tester for Array2D class.
void ctrcopyassignTester();

// Row and Column mutator testing function.
void setrowsetcolTester();

// Subscript overload and Select function mutator
void subscriptselectTester();

// Exception handling testing
void exceptionTester();

void main()
{
	ctrcopyassignTester();

	setrowsetcolTester();

	subscriptselectTester();

	exceptionTester();

}

/**************************************************************
*	  Purpose:  Constructor, copy constructor, and assignment
*				operator tester for Array2D class.
*
*         Entry:  Call ctrcopyassignTester with no arguments
*
*          Exit:	Does not return any value.
****************************************************************/
void ctrcopyassignTester()
{
	Array2D<int> testArray(5, 5);
	for (int i = 0; i < testArray.getRow(); i++)
	{
		for (int j = 0; j < testArray.getColumn(); j++)
		{
			testArray[i][j] = 0;
		}
	}
	
	print(testArray);

	cout << "Constructor test, all 0's" << endl;

	Array2D<int> testCopy(testArray);

	print(testCopy);

	cout << "Copy Constructor test, all 0's" << endl;

	for (int i = 0; i < testArray.getRow(); i++)
	{
		for (int j = 0; j < testArray.getColumn(); j++)
		{
			testArray[i][j] = i + j;
		}
	}

	print(testArray);

	cout << "Cell = Row + Column" << endl;

	testCopy = testArray;

	print(testCopy);

	cout << "Assignment operator test, Cell = Row + Column" << endl;
}

/**************************************************************
*	  Purpose:  Row and Column mutator testing function.
*
*         Entry:  Call setrowsetcolTester with no arguments
*
*          Exit:	Does not return any value.
****************************************************************/
void setrowsetcolTester()
{
	Array2D<char> testArray(10, 10);

	for (int i = 0; i < testArray.getRow(); i++)
	{
		for (int j = 0; j < testArray.getColumn(); j++)
		{
			testArray[i][j] = 'a' + i;
		}
	}

	print(testArray);
	cout << "10 X 10 array with one letter per row, a-j sequentially" << endl;
	testArray.setRow(5);

	print(testArray);

	cout << "Previous Array with bottom 5 rows removed." << endl;

	testArray.setColumn(3);

	print(testArray);

	cout << "Previous Array with right 2 columns removed." << endl;
}

/**************************************************************
*	  Purpose:  Subscript overload and Select function mutator
*
*         Entry:  Call subscriptselectTester with no arguments
*
*          Exit:	Does not return any value.
****************************************************************/
void subscriptselectTester()
{
	Array2D<double> testArray(4, 9);

	for (int i = 0; i < testArray.getRow(); i++)
	{
		for (int j = 0; j < testArray.getColumn(); j++)
		{
			testArray[i][j] = j * .5;
		}
	}

	print(testArray);
	cout << "Array of doubles, 4 x 9" << endl;

	testArray[2][6] = 205.132;

	print(testArray);
	cout << "Prevous array with cell 2, 6 changed to 205.132" << endl;

	cout << testArray.Select(2, 6) << endl;

	cout << "Value stored in cell 2, 6" << endl;
}

/**************************************************************
*	  Purpose:  Exception handling testing
*
*         Entry:  Call exceptionTester with no arguments
*
*          Exit:	Does not return any value.
****************************************************************/
void exceptionTester()
{
	Array2D<int> testArray(5, 5);

	try
	{
		cout << testArray[6][4] << endl;
	}

	catch (Exception except)
	{
		cout << except << endl;
	}

	try
	{
		cout << testArray[4][8] << endl;
	}

	catch (Exception except)
	{
		cout << except << endl;
	}

	try
	{
		testArray.setRow(-1);
	}

	catch (Exception except)
	{
		cout << except << endl;
	}

	try
	{
		testArray.setColumn(0);
	}

	catch (Exception except)
	{
		cout << except << endl;
	}

	try
	{
		testArray.Select(6, 6);
	}

	catch (Exception except)
	{
		cout << except << endl;
	}

	try
	{
		testArray.Select(4, 6);
	}

	catch (Exception except)
	{
		cout << except << endl;
	}
}

/**************************************************************
*	  Purpose:  print function for 2d arrays
*
*         Entry:  Call print function with one argument containing
*				  and Array2D object.
*
*          Exit:	Does not return any value.
****************************************************************/
template <typename T>
void print(Array2D<T> myArray)
{
	for (int i = 0; i < myArray.getRow(); i++)
	{
		for (int j = 0; j < myArray.getColumn(); j++)
		{
			cout << myArray.Select(i, j) << " ";
		}

		cout << endl;
	}
}