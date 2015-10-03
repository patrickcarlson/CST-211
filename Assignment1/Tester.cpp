#include <iostream>
#include "Array.h"

using namespace std;


void constructortest(int x, int y);

template <typename T>
void copyconstructortest(Array<T> a);

void assignmenttest();

void subscripttest();

void exceptiontesting();

void main()
{
	Array<int> a(10, 0);
	
	//2 argument constructor
	constructortest(10, 0);

	copyconstructortest(a);

	assignmenttest();

	subscripttest();

	exceptiontesting();

};

void constructortest(int x, int y)
{
	Array<int> b(10, 0);
}

template <typename T>
void copyconstructortest(Array<T> a)
{
	Array<T> b(a);
	
}


void assignmenttest()
{
	Array<int> a(10, -5);

	Array<int> b(15, 5);

	b = a;
}

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

void exceptiontesting()
{
	Array<int> a(10, 0);

	cout << a[-2];
}