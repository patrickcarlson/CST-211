#include <iostream>
#include <vector>

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
	int n;

	int* thisArray;
	int* toSortArray;

	if (argc > 1) {
		n = atoi(argv[1]);
	}
	
	thisArray = new int[n];
	vector<int> thisVector;
	for (int i = 0; i < n; i++)
	{
		int value = rand() % 1000 + 1;
		thisArray[i] = value;

		thisVector.push_back(value);
	}

	toSortArray = new int[n];

	memcpy(toSortArray, thisArray, n*sizeof(int));

	myBubbleSort(toSortArray, n);

	myBubbleSort(&thisVector[0], n);

	memcpy(toSortArray, thisArray, n * sizeof(int));

	myInsertionSort(toSortArray, n);

	memcpy(toSortArray, thisArray, n * sizeof(int));

	mySelectionSort(toSortArray, n);

	memcpy(toSortArray, thisArray, n * sizeof(int));

	myMergeSort(toSortArray, 0, n-1);

	memcpy(toSortArray, thisArray, n * sizeof(int));

	myQuickSort(toSortArray, n);

	memcpy(toSortArray, thisArray, n * sizeof(int));

	myHeapSort(toSortArray, n);

	memcpy(toSortArray, thisArray, n * sizeof(int));

	myShellsort(toSortArray, n);

	delete[] thisArray;
	delete[] toSortArray;
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