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

}