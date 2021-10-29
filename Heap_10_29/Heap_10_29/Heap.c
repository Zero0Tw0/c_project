#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

void swap(int* a, int* b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void HeapAdjustDownSmall(int* Heap, int HeapSize, int parent)		//调小堆
{
	int child = parent * 2 + 1;
	while (child < HeapSize)
	{
		if (child + 1 < HeapSize && Heap[child + 1] < Heap[child] )
		{
			child++;
		}
		if (Heap[child] < Heap[parent])
		{
			swap(&Heap[child], &Heap[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapAdjustDownBig(int* Heap, int HeapSize, int parent)		//调小堆
{
	int child = parent * 2 + 1;
	while (child < HeapSize)
	{
		if (child + 1 < HeapSize && Heap[child + 1] > Heap[child])
		{
			child++;
		}
		if (Heap[child] > Heap[parent])
		{
			swap(&Heap[child], &Heap[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void BuildHeap(int* heap, int HeapSize)					//建大堆
{
	for (int i = (HeapSize - 1 - 1) / 2; i >= 0; i--)
	{
		HeapAdjustDownBig(heap, HeapSize, i);
	}
}


void HeapPrint(int* heap, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", heap[i]);
	}
	printf("\n");
}

void test1()
{
	int heap1[] = { 27,15,19,18,28,34,65,49,25,37 };		//堆调测试
	int size1 = sizeof(heap1) / sizeof(heap1[0]);
	HeapAdjustDownSmall(heap1, size1, 0);
	HeapPrint(heap1, size1);


	int heap2[] = { 1,5,3,8,7,6 };							//建大堆测试
	int size2 = sizeof(heap2) / sizeof(heap2[0]);
	BuildHeap(heap2, size2);
	HeapPrint(heap2, size2);

}

int main()
{
	test1();
}