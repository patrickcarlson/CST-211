
template <typename T>
void Bubblesort(T data[]);

void main()
{
	int thisArray[5];
	thisArray[0] = 11;
	thisArray[1] = 7;
	thisArray[2] = 3;
	thisArray[3] = 2;
	thisArray[4] = 25;

	Bubblesort(thisArray);
}

template <typename T> 
void BubbleSort(T data[])
{
	int n = data.length();

	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; --j)
			if (data[j] < data[j - 1])
				swap(data[j], data[j - 1]);
}