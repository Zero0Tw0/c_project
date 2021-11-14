#include"sort.h"

//排序所需子函数
void StrPrint(int* str, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ",str[i]);
	}
	printf("\n");
}

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void AdjustDown(int* str, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && str[child + 1] > str[child])
		{
			child++;
		}
		if (str[child] > str[parent])
		{
			Swap(&str[child], &str[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void BuildHeap(int* str, int size)
{
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(str, size, i);
	}
}



//插入排序
void InsertSort(int* str, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int end = i;
		int tmp = str[end + 1];
		while (end >= 0)
		{
			if (tmp < str[end])
			{
				str[end + 1] = str[end];
				end--;
			}
			else
			{
				break;
			}
		}
		str[end + 1] = tmp;
	}
	
}



//希尔排序
void ShellSort(int* str, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap/3 + 1;
		for (int i = 0; i < size - gap; i++)
		{
			int end = i;
			int tmp = str[end + gap];
			while (end >= 0)
			{
				if (tmp < str[end])
				{
					str[end + gap] = str[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			str[end + gap] = tmp;
		}
	}
}



//堆排序
void HeapSort(int* str, int size)
{
	//排升序，对数组建大堆
	BuildHeap(str, size);

	int end = size-1;
	while (end >= 0)
	{
		Swap(&str[end--], &str[0]);
		AdjustDown(str, end, 0);
	}
	
}

void SelectSort(int* str, int size)
{
	int left = 0;
	int right = size - 1;

	while(left<right)
	{
		int mini = left;
		int maxi = right;
		for (int i = left; i <= right; i++)
		{
			if (str[i] < str[mini])
			{
				mini = i;
			}
			if (str[i] > str[maxi])
			{
				maxi = i;
			}
		}
		Swap(&str[mini], &str[left]);
		if (maxi == left)
		{
			maxi = mini;
		}
		Swap(&str[maxi], &str[right]);
		left++;
		right--;
	}
}