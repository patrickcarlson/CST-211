/***********************************************************
* Author:				Patrick Carlson
* Date Created:			11/1/2015
* Last Modification Date:	11/3/2015
* Assignment Number:    CST 211 Lab 2
* Filename:				Sorts.cpp
*
* Overview:
*	cpp file contains seperate sort functions for bubble, 
*	insertion, selection, merge, heap, quick, and shell
*	sorts. Main runs and times each sort.
*
* Input:
*	Requires command line argument which is number of 
*	elements in the arrays to be sorted.
*
* Output:
*	Output to file, and console, the time of each sort.
************************************************************/

#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include "Array.h"
#include "Exception.h"

using namespace std;

template <typename T>
void myBubbleSort(T* theArray, int n);

template <typename T>
void myInsertionSort(T theArray[], int n);

template <typename T>
void mySelectionSort(T theArray[], int n);

template <typename T>
void myMergeSort(T theArray[], int first, int last);

template <typename T>
void merge(T theArray[], int first, int last, int middle);

template <typename T>
void myQuickSort(T theArray[], int n);

template <typename T>
void myQuickSort(T theArray[], int first, int last);

template <typename T>
void myHeapSort(T theArray[], int n);

template <typename T>
void heap(T theArray[], int first, int last);

template <typename T>
void myShellsort(T theArray[], int n);



int main(int argc, const char* argv[])
{
	ofstream timeOut;
	timeOut.open("Timesheet.txt");
	int n;

	clock_t t1, t2;

	int* thisArray;
	int* toSortArray;
	Array<int>* myArray;

	if (argc > 1) {
		n = atoi(argv[1]);
	}
	
	myArray = new Array<int>(n);

	Array<int> toSortmyArray(*myArray);

	thisArray = new int[n];
	vector<int> thisVector;

	//
	// Assign values to Arrays
	//
	for (int i = 0; i < n; i++)
	{
		int value = rand() % 1000 + 1;
		thisArray[i] = value;

		thisVector.push_back(value);
		toSortmyArray[i] = value;
	}

	toSortArray = new int[n];

	*myArray = toSortmyArray;

	vector<int> toSortVector = thisVector;

	memcpy(toSortArray, thisArray, n*sizeof(int));

	//
	// Bubble Sort
	//
	t1 = clock();
	myBubbleSort(toSortArray, n);
	t2 = clock();
	float diff = ((float)t2 - (float)t1);
	float time = diff / (CLOCKS_PER_SEC / 1000);

	cout << "Bubble sort takes " << time << " milliseconds to execute on C Array." << endl;
	timeOut << "Bubble sort takes " << time << " milliseconds to execute on C Array." << endl;


	t1 = clock();
	myBubbleSort(&toSortVector[0], n);
	t2 = clock();
	diff = ((float)t2 - (float)t1);
	time = diff / (CLOCKS_PER_SEC / 1000);

	cout << "Bubble sort takes " << time << " milliseconds to execute on Vector." << endl;
	timeOut << "Bubble sort takes " << time << " milliseconds to execute on Vector." << endl;
	t1 = clock();
	myBubbleSort(&toSortmyArray[0], n);
	t2 = clock();
	diff = ((float)t2 - (float)t1);
	time = diff / (CLOCKS_PER_SEC / 1000);

	cout << "Bubble sort takes " << time << " milliseconds to execute on custom Array(Assignment 1)" << endl;
	timeOut << "Bubble sort takes " << time << " milliseconds to execute on Vector." << endl;

	toSortVector = thisVector;

	toSortmyArray = *myArray;

	memcpy(toSortArray, thisArray, n * sizeof(int));



	t1 = clock();
	myInsertionSort(toSortArray, n);
	t2 = clock();
	diff = ((float)t2 - (float)t1);
	time = diff / (CLOCKS_PER_SEC / 1000);

	cout << "Insertion sort takes " << time << " milliseconds to execute on C Array." << endl;
	timeOut << "Insertion sort takes " << time << " milliseconds to execute on C Array." << endl;

	t1 = clock();
	myInsertionSort(&toSortVector[0], n);
	t2 = clock();
	diff = ((float)t2 - (float)t1);
	time = diff / (CLOCKS_PER_SEC / 1000);

	cout << "Insertion sort takes " << time << " milliseconds to execute on Vector." << endl;
	timeOut << "Insertion sort takes " << time << " milliseconds to execute on Vector." << endl;

	t1 = clock();
	myInsertionSort(&toSortmyArray[0], n);
	t2 = clock();
	diff = ((float)t2 - (float)t1);
	time = diff / (CLOCKS_PER_SEC / 1000);

	cout << "Insertion sort takes " << time << " milliseconds to execute on custom Array(Assignment 1)" << endl;
	timeOut << "Insertion sort takes " << time << " milliseconds to execute on custom Array(Assignment 1)" << endl;


	toSortVector = thisVector;

	toSortmyArray = *myArray;

	memcpy(toSortArray, thisArray, n * sizeof(int));


	//
	// Selection Sort
	//
	t1 = clock();
	mySelectionSort(toSortArray, n);
	t2 = clock();
	diff = ((float)t2 - (float)t1);
	time = diff / (CLOCKS_PER_SEC / 1000);

	cout << "Selection sort takes " << time << " milliseconds to execute on C Array." << endl;
	timeOut << "Selection sort takes " << time << " milliseconds to execute on C Array." << endl;


	t1 = clock();
	mySelectionSort(&toSortVector[0], n);
	t2 = clock();
	diff = ((float)t2 - (float)t1);
	time = diff / (CLOCKS_PER_SEC / 1000);

	cout << "Selection sort takes " << time << " milliseconds to execute on Vector." << endl;
	timeOut << "Selection sort takes " << time << " milliseconds to execute on Vector." << endl;

	t1 = clock();
	mySelectionSort(&toSortmyArray[0], n);
	t2 = clock();
	diff = ((float)t2 - (float)t1);
	time = diff * 10 / (CLOCKS_PER_SEC / 1000);

	cout << "Selection sort takes " << time << " milliseconds to execute on custom Array(Assignment 1)." << endl;
	timeOut << "Selection sort takes " << time << " milliseconds to execute on custom Array(Assignment 1)." << endl;

	//
	// Selection Sort
	//

	toSortVector = thisVector;

	toSortmyArray = *myArray;

	memcpy(toSortArray, thisArray, n * sizeof(int));

	//
	// Merge Sort
	//
	t1 = clock();
	myMergeSort(toSortArray, 0, n - 1);
	t2 = clock();
	diff = ((float)t2 - (float)t1);
	time = diff / (CLOCKS_PER_SEC / 1000);

	cout << "Merge sort takes " << time << " milliseconds to execute on C Array." << endl;
	timeOut << "Merge sort takes " << time << " milliseconds to execute on C Array." << endl;

	t1 = clock();
	myMergeSort(&toSortVector[0], 0, n - 1);
	t2 = clock();
	diff = ((float)t2 - (float)t1);
	time = diff / (CLOCKS_PER_SEC / 1000);

	cout << "Merge sort takes " << time << " milliseconds to execute on Vector." << endl;
	timeOut << "Merge sort takes " << time << " milliseconds to execute on Vector." << endl;

	t1 = clock();
	myMergeSort(&toSortmyArray[0], 0, n - 1);
	t2 = clock();
	diff = ((float)t2 - (float)t1);
	time = diff / (CLOCKS_PER_SEC / 1000);

	cout << "Merge sort takes " << time << " milliseconds to execute on custom Array(Assignment 1)." << endl;
	timeOut << "Merge sort takes " << time << " milliseconds to execute on custom Array(Assignment 1)." << endl;


	toSortVector = thisVector;

	toSortmyArray = *myArray;

	memcpy(toSortArray, thisArray, n * sizeof(int));

	//
	// Quick Sort
	//
	t1 = clock();
	myQuickSort(toSortArray, n);
	t2 = clock();
	diff = ((float)t2 - (float)t1);
	time = diff / (CLOCKS_PER_SEC / 1000);

	cout << "Quick sort takes " << time << " milliseconds to execute on C Array." << endl;
	timeOut << "Quick sort takes " << time << " milliseconds to execute on C Array." << endl;

	t1 = clock();
	myQuickSort(&toSortVector[0], n);
	t2 = clock();
	diff = ((float)t2 - (float)t1);
	time = diff / (CLOCKS_PER_SEC / 1000);

	cout << "Quick sort takes " << time << " milliseconds to execute on Vector." << endl;
	timeOut << "Quick sort takes " << time << " milliseconds to execute on Vector." << endl;

	//myQuickSort(&toSortmyArray[0], n);
	//
	// Quick Sort
	//

	toSortVector = thisVector;

	toSortmyArray = *myArray;

	memcpy(toSortArray, thisArray, n * sizeof(int));

	//
	// Heap Sort
	//
	t1 = clock();
	myHeapSort(toSortArray, n);
	t2 = clock();
	diff = ((float)t2 - (float)t1);
	time = diff / (CLOCKS_PER_SEC / 1000);

	cout << "Heap sort takes " << time << " milliseconds to execute on C Array." << endl;
	timeOut << "Heap sort takes " << time << " milliseconds to execute on C Array." << endl;

	t1 = clock();
	myHeapSort(&toSortVector[0], n);
	t2 = clock();
	diff = ((float)t2 - (float)t1);
	time = diff / (CLOCKS_PER_SEC / 1000);

	cout << "Heap sort takes " << time << " milliseconds to execute on Vector." << endl;
	timeOut << "Heap sort takes " << time << " milliseconds to execute on Vector." << endl;


	t1 = clock();
	myHeapSort(&toSortmyArray[0], n);
	t2 = clock();
	diff = ((float)t2 - (float)t1);
	time = diff / (CLOCKS_PER_SEC / 1000);

	cout << "Heap sort takes " << time << " milliseconds to execute on custom Array(Assignment 1)." << endl;
	timeOut << "Heap sort takes " << time << " milliseconds to execute on custom Array(Assignment 1)." << endl;

	//
	// Heap Sort
	//

	toSortVector = thisVector;

	toSortmyArray = *myArray;

	memcpy(toSortArray, thisArray, n * sizeof(int));

	/////////////////////////////
	// Shell Sort
	////////////////////////////
	t1 = clock();
	myShellsort(toSortArray, n);
	t2 = clock();
	diff = ((float)t2 - (float)t1);
	time = diff / (CLOCKS_PER_SEC / 1000);

	cout << "Shell sort takes " << time << " milliseconds to execute on C Array." << endl;
	timeOut << "Shell sort takes " << time << " milliseconds to execute on C Array." << endl;

	t1 = clock();
	myShellsort(&toSortVector[0], n);
	t2 = clock();
	diff = ((float)t2 - (float)t1);
	time = diff / (CLOCKS_PER_SEC / 1000);

	cout << "Shell sort takes " << time << " milliseconds to execute on Vector." << endl;
	timeOut << "Shell sort takes " << time << " milliseconds to execute on Vector." << endl;

	t1 = clock();
	myShellsort(&toSortmyArray[0], n);
	t2 = clock();
	diff = ((float)t2 - (float)t1);
	time = diff / (CLOCKS_PER_SEC / 1000);

	cout << "Shell sort takes " << time << " milliseconds to execute on custom Array(Assignment 1)." << endl;
	timeOut << "Shell sort takes " << time << " milliseconds to execute on custom Array(Assignment 1)." << endl;

	//////////////////////////////
	// End of Shell Sort
	//////////////////////////////

	delete[] thisArray;
	delete[] toSortArray;
	delete myArray;
}


template <typename T> 
void myBubbleSort(T theArray[], int n)
{

	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; --j)
			if (theArray[j] < theArray[j - 1])
			{
				T temp = theArray[j];
				theArray[j] = theArray[j - 1];
				theArray[j - 1] = temp;
			}


}

template <typename T>
void myInsertionSort(T theArray[], int n)
{
	T temp;
	for (int i = 1, j; i < n; i++)
	{
		temp = theArray[i];
		for (j = i; j > 0 && temp < theArray[j - 1]; j--)
		{
			theArray[j] = theArray[j - 1];
		}

		theArray[j] = temp;
	}
		

}

template <typename T>
void mySelectionSort(T theArray[], int n)
{
	for (int i = 0, j, temp; i < n - 2; i++)
	{
		temp = i;

		for (j = i + 1; j < n - 1; j++)
		{
			if(theArray[j] < theArray[temp])
			{
				temp = j;
			}
		}
		if (temp != i) 
		{
			T tempVal = theArray[i];
			theArray[i] = theArray[temp];
			theArray[temp] = tempVal;
		}
		
	}
}

template <typename T>
void myMergeSort(T theArray[], int first, int last)
{
	int middle;
	if (first < last)
	{
		middle = (first + last) / 2;

		myMergeSort(theArray, first, middle);
		myMergeSort(theArray, middle + 1, last);
		
		merge(theArray, first, last, middle);

	}
}

template <typename T>
void merge(T theArray[], int first, int last, int middle)
{
	int i = first;
	int j = middle + 1;
	int k = first;
	T* tempArray = new T[last + 1];

	while (i <= middle && j <= last)
	{
		if (theArray[i] < theArray[j])
		{
			tempArray[k] = theArray[i];

			k++;
			i++;
		}

		else
		{
			tempArray[k] = theArray[j];
			k++;
			j++;
		}
	}

	while (i <= middle)
	{
		tempArray[k] = theArray[i];
		k++;
		i++;
	}

	while (j <= last)
	{
		tempArray[k] = theArray[j];
		
		k++;
		j++;

	}

	for (i = first; i < k; i++)
	{
		theArray[i] = tempArray[i];
	}

	delete[] tempArray;
}

template <typename T>
void myQuickSort(T theArray[], int n)
{
	int i;
	int top;

	if (n < 2)
		return;
	for (i = 1, top = 0; i < n; i++)
	{
		if (theArray[top] < theArray[i])
			top = i;
	}

	T tempVal = theArray[n - 1];
	theArray[n - 1] = theArray[top];
	theArray[top] = tempVal;

	myQuickSort(theArray, 0, n - 2);
}

template <typename T>
void myQuickSort(T theArray[], int first, int last)
{
	int low;
	int high;

	low = first + 1;

	high = last;

	//
	//Set pivot to value in middle index.
	//
	T tempVal = theArray[first];
	theArray[first] = theArray[(first + last) / 2 ];
	theArray[(first + last) / 2] = tempVal;

	T pivot = theArray[first];

	while (low <= high)
	{
		//
		// Move low flag up until reaches a value greater than pivot.
		//
		while (theArray[low] < pivot)
		{
			low++;
		}

		//
		// Move high flag down until reaches a value less than pivot
		//
		while (pivot < theArray[high])
		{
			high--;
		}

		//
		// Check that flags have not crossed then perform swap.
		//

		if (low < high)
		{
			tempVal = theArray[low];
			theArray[low] = theArray[high];
			theArray[high] = tempVal;
			low++;
			high++;
		}

		//
		// Increment low flag if low has reached high flag.
		//
		else
			low++;
	}

	//
	// Pass our pivot back to the array where it will lay between values lower and values higher
	//

	tempVal = theArray[high];
	theArray[high] = theArray[first];
	theArray[first] = tempVal;

	//
	//Divide array into two seperate arrays to be quicksorted.
	//
	if (first < high - 1)
		myQuickSort(theArray, first, high - 1);
	if (high + 1 < last)
		myQuickSort(theArray, high + 1, last);

}

template <typename T>
void myHeapSort(T theArray[], int n)
{
	for (int i = n / 2 - 1; i >= 0; --i)
	{
		heap(theArray, i, n - 1);
	}

	for (int i = n - 1; i >= 1; --i)
	{
		T tempVal = theArray[0];
		theArray[0] = theArray[i];
		theArray[i] = tempVal;

		heap(theArray, 0, i - 1);
	}
}

template <typename T>
void heap(T theArray[], int first, int last)
{
	int high;

	high = 2 * first + 1;

	while (high <= last)
	{
		if (high < last && theArray[high] < theArray[high + 1])
			high++;

		if (theArray[first] < theArray[high])
		{
			T tempVal = theArray[first];
			theArray[first] = theArray[high];
			theArray[high] = tempVal;

			first = high;
			high = 2 * first + 1;
		}
		else high = last + 1;
	
	}

}

template <typename T>
void myShellsort(T theArray[], int n)
{
	int incSize;
	int incLocation;
	int sortIndex;
	int tempIndex;


	//
	// Vector to contain increment array. Each cell should contain
	// 3 * (previous cell) + 1
	//
	vector<int> increment;

	for (int i = 0, incSize = 1; incSize < n; i++)
	{
		increment.push_back(incSize);
		incSize = 3 * n + 1;
	}

	for (int j = (increment.size() - 1); j >= 0; j--)
	{
		incSize = increment[j];

		

		for (incLocation = incSize; incLocation < 2 * incSize; incLocation++)
		{

			//
			// Sort values in cells seperated by incSize with insertion sort
			//

			for (sortIndex = incLocation; sortIndex < n;)
			{
				T temp = theArray[sortIndex];
				
				tempIndex = sortIndex;

				while (tempIndex - incSize >= 0 && temp < theArray[tempIndex - incSize])
				{
					theArray[tempIndex] = theArray[tempIndex - incSize];

					tempIndex -= incSize;


				}

				theArray[tempIndex] = temp;

				sortIndex += incSize;
			}
		}
	}
}