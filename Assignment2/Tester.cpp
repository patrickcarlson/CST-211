#include "Array2D.h"
#include <iostream>

using namespace std;

template <typename T>
void print(Array2D<T> myArray);


void main()
{
	Array2D<int> testObject(5, 5);

	print(testObject);


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