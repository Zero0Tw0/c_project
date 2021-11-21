#include"Sort.h"
#include"Stack.h"

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

	//建堆
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		Adjustdown(str, size, i);
	}
	//排序
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
int PartSort1(int* str, int left, int right)		//快排Hoare
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
int PartSort2(int* str, int left, int right)		//快排：挖坑
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
	return left;

}
int PartSort3(int* str, int left, int right)		//快排：前后指针
{
	int key = left;
	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (str[cur] < str[key]&& prev++ != cur)
		{
			Swap(&str[cur], &str[prev]);
		}
		cur++;
	}
	Swap(&str[prev], &str[key]);
	return prev;
}
void QuickSort(int* str, int left, int right)
{
	if (left >= right)
		return;
	int mid = PartSort2(str, left, right);
	QuickSort(str, left, mid - 1);
	QuickSort(str, mid + 1, right);
}

void QuickSortNonR(int* str, int left, int right)
{
	Stack stack;
	StackInit(&stack);
	StackPush(&stack, left);
	StackPush(&stack, right);
	while (!StackEmpty(&stack))
	{
		right = StackTop(&stack);
		StackPop(&stack);
		left = StackTop(&stack);
		StackPop(&stack);

		int mid = PartSort1(str, left, right);
		if (left < mid-1)
		{
			StackPush(&stack, left);
			StackPush(&stack, mid - 1);
		}
		if (right > mid + 1)
		{
			StackPush(&stack, mid + 1);
			StackPush(&stack, right);
		}
	}
	StackDestroy(&stack);
}

void _MergeSort(int* str, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	int mid = (left + right)/2;
	_MergeSort(str, left, mid, tmp);
	_MergeSort(str, mid + 1, right, tmp);
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	//printf("[%d %d]", begin1, end1);
	//printf("[%d %d]", begin2, end2);

	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (str[begin1] < str[begin2])
		{
			tmp[i++] = str[begin1++];
		}
		else
		{
			tmp[i++] = str[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = str[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = str[begin2++];
	}
	for (int j = left; j <= right; j++)
	{
		str[j] = tmp[j];
	}

}
void MergeSort(int* str, int size)
{
	int* tmp = (int*)malloc(size * sizeof(int));
	_MergeSort(str, 0, size - 1, tmp);
	free(tmp);

}

void _MergeSortNonR(int* str, int size, int* tmp)
{
	int gap = 1;
	while (gap < size)
	{
		for (int i = 0; i < size; i = i + 2 * gap)
		{
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;
			int j = i;
			if (end1 >= size)
			{
				break;
			}
			else if (end2 >= size)
			{
				end2 = size - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (str[begin1] < str[begin2])
				{
					tmp[j++] = str[begin1++];
				}
				else
				{
					tmp[j++] = str[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = str[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = str[begin2++];
			}
		}
		for (int k = 0; k < size; k++)
		{
			str[k] = tmp[k];
		}
		gap *= 2;
	}
}
void MergeSortNonR(int* str, int size)
{
	int* tmp = (int*)malloc(size * sizeof(int));
	_MergeSortNonR(str, size, tmp);
	free(tmp);
}

void CountSort(int* str, int size)
{
	int min = str[0];
	int max = str[0];
	for (int i = 0; i < size; i++)
	{
		if (str[i] < min)
			min = str[i];
		if (str[i] > max)
			max = str[i];
	}
	int* count = (int*)calloc(max-min+1,sizeof(int));
	for (int i = 0; i < size; i++)
	{
		count[str[i] - min]++;
	}
	int i = 0;
	for (int j = 0; j < max - min + 1; j++)
	{
		while(count[j]--)
		{
			str[i++] = j + min;
		}
	}
	free(count);
}