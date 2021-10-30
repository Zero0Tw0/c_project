#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdbool.h>



void swap(int* a, int* b)				//½»»»
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void SmallHeapAdjustDown(int* Heap, int HeapSize, int parent)		//µ÷Ð¡¶Ñ
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

void BigHeapAdjustDown(int* Heap, int HeapSize, int parent)		//µ÷´ó¶Ñ
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

void BigHeapBuild(int* heap, int HeapSize)					//½¨´ó¶Ñ
{
	for (int i = (HeapSize - 1 - 1) / 2; i >= 0; i--)
	{
		BigHeapAdjustDown(heap, HeapSize, i);
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

void BigHeapSort(int* heap, int heapsize)			//ÅÅÉýÐò
{
	int tail = heapsize - 1;
	int tmp;
	while (tail)
	{
		swap(&heap[0], &heap[tail]);
		tail--;
		BigHeapAdjustDown(heap, tail+1, 0);
	}
}

void SmallHeapSort(int* heap, int heapsize)			//ÅÅ½µÐò
{
	int tail = heapsize - 1;
	int tmp;
	while (tail)
	{
		swap(&heap[0], &heap[tail]);
		tail--;
		SmallHeapAdjustDown(heap, tail + 1, 0);
	}
}



void test1()
{
	int heap1[] = { 27,15,19,18,28,34,65,49,25,37 };		//µ÷Ð¡²âÊÔ
	int size1 = sizeof(heap1) / sizeof(heap1[0]);
	SmallHeapAdjustDown(heap1, size1, 0);
	HeapPrint(heap1, size1);


	int heap2[] = { 1,5,3,8,7,6 };							//½¨´ó¶Ñ²âÊÔ
	int size2 = sizeof(heap2) / sizeof(heap2[0]);
	BigHeapBuild(heap2, size2);
	HeapPrint(heap2, size2);

	BigHeapSort(heap2, size2);								//ÅÅÉýÐò²âÊÔ
	HeapPrint(heap2, size2);

	SmallHeapSort(heap1,size1);								//ÅÅ½µÐò²âÊÔ
	HeapPrint(heap1, size1);
}



int main()
{
	test1();
	return 0;
}