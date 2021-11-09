#include"heap.h"

void HeapSort(int* a, int n)
{
	Heap heap;
	int size = n;
	HeapInit(&heap, a, size);
	//HeapPrint(&heap);

	int heapsize = heap.size;
	heap.size--;
	while(heap.size>=0)
	{
		Swap(&heap.val[0], &heap.val[heap.size]);
		heap.size--;
		HeapAdjustDown(&heap, 0);
	}
	memcpy(a, heap.val, sizeof(int) * heapsize);
}

void test1()
{
	int a[] = { 34,65,49,25,37,27,15,19,18,28 };
	int size = sizeof(a) / sizeof(a[0]);
	HeapSort(a, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
}


void test()
{
	int a[] = { 34,65,49,25,37,27,15,19,18,28 };
	Heap heap;
	int size = sizeof(a) / sizeof(a[0]);
	HeapInit(&heap, a, size);
	HeapPrint(&heap);

	int top = HeapTop(&heap);
	printf("top:%d\n", top);

	HeapPush(&heap, 1);
	HeapPrint(&heap);

	while (!HeapEmpty(&heap))
	{
		
		HeapPop(&heap);
		HeapPrint(&heap);
	}

	HeapPush(&heap, 3);
	HeapPrint(&heap);

	HeapDestroy(&heap);
}

int main()
{
	//test();
	test1();
	return 0;
}