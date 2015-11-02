#include <iostream>

using namespace std;

template <typename T>
void myBubbleSort(T theArray[], int n);

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



int main()
{
	int thisArray[5] = { 11, 7, 3, 2, 25 };
	int toSortArray[5];

	memcpy(toSortArray, thisArray, 5*sizeof(int));

	myBubbleSort(toSortArray, 5);

	memcpy(toSortArray, thisArray, 5 * sizeof(int));

	myInsertionSort(toSortArray, 5);

	memcpy(toSortArray, thisArray, 5 * sizeof(int));

	mySelectionSort(toSortArray, 5);

	memcpy(toSortArray, thisArray, 5 * sizeof(int));

	myMergeSort(toSortArray, 0, 4);

	memcpy(toSortArray, thisArray, 5 * sizeof(int));

	myQuickSort(toSortArray, 5);

	memcpy(toSortArray, thisArray, 5 * sizeof(int));

	myHeapSort(toSortArray, 5);


}


template <typename T> 
void myBubbleSort(T theArray[], int n)
{

	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; --j)
			if (theArray[j] < theArray[j - 1])
				swap(theArray[j], theArray[j - 1]);

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
		if(temp != i)
		swap(theArray[i], theArray[temp]);
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

	swap(theArray[n - 1], theArray[top]);
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
	swap(theArray[first], theArray[(first + last) / 2]);

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
			swap(theArray[low], theArray[high]);
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
	swap(theArray[high], theArray[first]);

	//
	//Divide array into to seperate arrays to be quicksorted.
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
		swap(theArray[0], theArray[i]);
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
			swap(theArray[first], theArray[high]);
			first = high;
			high = 2 * first + 1;
		}
		else high = last + 1;
	
	}

}

template <typename T>
void myShellsort(T theArray[], int n)
{
	while (incSize < n)
	{
		incSize = 3 * incSize + 1;
		incValue++;
	}
	
	int* increment = new int[n*3]
}