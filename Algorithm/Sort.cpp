void MySwap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void BubbleSort(int* data, int n)
{
	if (n < 2) return;
	for (int limit = n - 1; limit > 0; limit--)
	{
		for (int i = 0; i < limit; i++)
		{
			if (data[i] > data[i + 1])
			{
				MySwap(data[i], data[i + 1]);
			}
		}
	}
}

void InsertionSort(int* data, int n)
{
	if (n < 2) return;
	for (int i = 1; i < n; i++) /// From 0 to i is in order
	{
		/*
		int target = data[i];
		int insertAfter = -1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (target >= data[j])
			{
				insertAfter = j;
				break;
			}
		}
		// Move objects
		for (int j = i-1 ; j > insertAfter ; j--)
		{
			data[j + 1] = data[j];
		}
		data[insertAfter + 1] = target;
		*/

		int target = data[i];
		int j;

		// If data[j-1] > target, 
		// then move data[j-1] to data[j] (move bigger objects to back)
		for (j = i ; j >= 0 && data[j-1] > target ; j--)
		{
			data[j] = data[j - 1];
		}
		data[j] = target;
	}
}

void SelectionSort(int* data, int n)
{
	for (int i = 0; i < n; i++)
	{
		int minValue = data[i];
		int minIndex = i;
		for (int j = i+1; j < n; j++)
		{
			if (minValue > data[j])
			{
				minValue = data[j];
				minIndex = j;
			}
		}
		// Swap objects
		MySwap(data[i], data[minIndex]);
	}
}

void ShellSort(int* data, int n) // ??????
{
	/// Change step as you wish
	for (int step = n / 2; step >= 1; step = step / 2) 
	{
		for (int i = step; i < n; i ++)
		{
			for (int j = i; j >= step && data[j] < data[j - step]; j -= step)
			{
				MySwap(data[j], data[j - step]);
			}
		}
	}
}

// First node at data[0]
void BuildMaxHeapInArray(int* data, int n)
{
	for (int i = n / 2; i >= 1; i--)
	{
		int temp = data[i];
		int son = i * 2;
		while (son <= n)
		{
			if (son < n&&data[son] < data[son + 1])
			{
				son++;
			}
			if (temp >= data[son])
			{
				break;
			}
			else
			{
				data[son / 2] = data[son];
				son *= 2;
			}
		}
		data[son / 2] = temp;
	}
}

void HeapSort(int* data, int n)
{
	/// MaxHeap, build it as a tree, build tree in array.

	BuildMaxHeapInArray(data, n);
}

/// From top to buttom 
void _MergeSort(int* data, int* ex, int left, int right)
{
	if (right <= left) return;
	int mid = (left + right) / 2;
	_MergeSort(data, ex, left, mid);
	_MergeSort(data, ex, mid + 1, right);

	for (int i = left; i <= right; i++)
	{
		ex[i] = data[i];
	}

	int leftPartIdx = left;
	int rightPartIdx = mid + 1;

	for (int i = left; i <= right; i++)
	{
		if (leftPartIdx > mid) // left part is empty
		{
			data[i] = ex[rightPartIdx];
			rightPartIdx++;
		}
		else if (rightPartIdx > right) // right part is empty
		{
			data[i] = ex[leftPartIdx];
			leftPartIdx++;
		}
		else if (ex[leftPartIdx] < ex[rightPartIdx]) // left object is less than right object
		{
			data[i] = ex[leftPartIdx];
			leftPartIdx++;
		}
		else
		{
			data[i] = ex[rightPartIdx];
			rightPartIdx++;
		}
	}
}

void MergeSort(int* data, int n)
{
	int* ex = new int[n];
	_MergeSort(data, ex, 0, n - 1);
	delete[] ex;
}

void _QuickSort(int* data, int left, int right)
{
	if (right <= left)
	{
		return;
	}
	int key = data[left];
	int leftIdx = left;
	int rightIdx = right;
	while (leftIdx < rightIdx )
	{
		while (leftIdx < rightIdx && data[rightIdx - 1] >= key)
		{
			rightIdx--;
		}
		MySwap(data[leftIdx], data[rightIdx]);
		while (leftIdx < rightIdx && data[leftIdx + 1] <= key)
		{
			leftIdx++;
		}
		MySwap(data[leftIdx], data[rightIdx]);
	}
	_QuickSort(data,left, leftIdx-1);
	_QuickSort(data, leftIdx + 1, right);
}

void QuickSort(int* data, int n)
{
	_QuickSort(data, 0, n - 1);
}
