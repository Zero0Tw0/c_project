#include"Sort.h"

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void StrPrint(int* str, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", str[i]);
	}
	printf("\n");
}

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

void ShellSort(int* str, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
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

void SelectSort(int* str, int size)
{
	int left = 0;
	int right = size - 1;
	
	while (left < right)
	{
		int min = left;
		int max = right;
		for (int i = left; i <= right; i++)
		{
			if (str[i] < str[min])
			{
				min = i;
			}
			if (str[i] > str[max])
			{
				max = i;
			}
		}
		Swap(&str[left], &str[min]);
		if (left == max)
		{
			max = min;
		}
		Swap(&str[right], &str[max]);

		left++;
		right--;
	}
}

void Adjustdown(int* str, int size, int root)
{
	int child = root * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && str[child + 1] > str[child])
		{
			child++;
		}
		if (str[child] > str[root])
		{
			Swap(&str[child], &str[root]);
			root = child;
			child = root * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* str, int size)
{

	//½¨¶Ñ
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		Adjustdown(str, size, i);
	}
	//ÅÅÐò
	while (size > 1)
	{
		Swap(&str[0], &str[size - 1]);
		size--;
		Adjustdown(str, size, 0);
	}
}

void BubbleSort(int* str, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (str[j + 1] < str[j])
			{
				Swap(&str[j + 1], &str[j]);
			}
		}
	}
}

int GetMidIndex(int* str, int left, int right)
{
	int mid = (left + right) / 2;
	int ret = left;
	if (str[ret] < str[mid])
	{
		if (str[ret] > str[right])
			return ret;
		else if (str[mid] < str[right])
			return mid;
		else
			return right;
	}
	else    //str[ret]>str[mid]
	{
		if (str[mid] > str[right])
			return mid;
		else if (str[right] > str[ret])
			return ret;
		else
			return right;
	}
}
int PartSort1(int* str, int left, int right)
{
	int mid = GetMidIndex(str, left, right);
	Swap(&str[left], &str[mid]);
	int key = left;
	while (left < right)
	{
		while (left < right && str[right] >= str[key])
		{
			right--;
		}
		while (left < right && str[left] <= str[key])
		{
			left++;
		}
		Swap(&str[left], &str[right]);
	}
	Swap(&str[key], &str[left]);
	return left;
}
int PartSort2(int* str, int left, int right)
{
	/*int mid = GetMidIndex(str, left, right);
	Swap(&str[left], &str[mid]);*/
	int key = str[left];
	int tmp = str[left];
	while (left < right)
	{
		while (left < right && str[right] >= key)
		{
			right--;
		}
		str[left] = str[right];
		while (left < right && str[left] <= key)
		{
			left++;
		}
		str[right] = str[left];
	}
	str[left] = tmp;

}
void QuickSort(int* str, int left, int right)
{
	if (left >= right)
		return;
	int mid = PartSort2(str, left, right);
	QuickSort(str, left, mid - 1);
	QuickSort(str, mid + 1, right);
}