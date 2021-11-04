#include"heap.h"

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
	test();
	return 0;
}