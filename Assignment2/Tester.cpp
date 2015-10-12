#include "Array2D.h"
#include <iostream>

using namespace std;

template <typename T>
void print(Array2D<T> myArray);
void ctrcopyassignTester();
void setrowsetcolTester();
void subscriptselectTester();

void main()
{
	ctrcopyassignTester();

	setrowsetcolTester();

	subscriptselectTester();

}

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