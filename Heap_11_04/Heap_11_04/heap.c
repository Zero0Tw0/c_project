#include"heap.h"
//Ð¡¶Ñ

void Swap(HeapDataType* a, HeapDataType* b)
{
	HeapDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

void HeapPrint(Heap* ph)
{
	for (int i = 0; i < ph->size; i++)
	{
		printf("%d ", ph->val[i]);
	}
	printf("\n");
}
void HeapAdjustDown(Heap* ph, int parent)
{
	int child = parent * 2 + 1;
	while (child < ph->size)
	{
		if (child + 1 < ph->size && ph->val[child + 1] < ph->val[child])
		{
			child++;
		}
		if (ph->val[child] < ph->val[parent])
		{
			Swap(&ph->val[child], &ph->val[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}

}

void HeapAdjustUp(Heap* ph, int child)
{
	int parent = (child - 1) / 2;
	while (parent <= child)
	{
		if (ph->val[child] < ph->val[parent])
		{
			Swap(&ph->val[child], &ph->val[parent]);
			child = parent;
			parent = (child - 1) / 2;
			
		}
		else
		{
			break;
		}
	}
}
void HeapBuild(Heap* ph)
{
	for (int i = (ph->size - 1) / 2; i >= 0; i--)
	{
		HeapAdjustDown(ph, i);
	}
}

void HeapInit(Heap* ph, HeapDataType* str, int size)
{
	assert(ph);
	assert(str);
	HeapDataType* newheap = (HeapDataType*)malloc(size * sizeof(HeapDataType));
	assert(newheap);
	memcpy(newheap, str, size * sizeof(HeapDataType));
	ph->val = newheap;
	ph->capacity = ph->size = size;
	//½¨¶Ñ
	HeapBuild(ph);

}
void HeapDestroy(Heap* ph)
{
	assert(ph);
	assert(ph->val);
	free(ph->val);
	ph->val = NULL;
	ph->size = ph->capacity = 0;
}

void HeapPush(Heap* ph, HeapDataType x)
{
	assert(ph);
	if (ph->size == ph->capacity)
	{
		int newcapacity = ph->capacity * 2;
		HeapDataType* newheap = (HeapDataType*)realloc(ph->val, newcapacity * sizeof(HeapDataType));
		assert(newheap);
		ph->val = newheap;
		ph->capacity = newcapacity;
	}
	ph->val[ph->size] = x;
	ph->size++;
	HeapAdjustUp(ph, ph->size-1);

}

void HeapPop(Heap* ph)
{
	assert(ph);
	assert(ph->size >= 0);
	ph->size--;
	Swap(&ph->val[0], &ph->val[ph->size]);
	HeapAdjustDown(ph, 0);
}

HeapDataType HeapTop(Heap* ph)
{
	assert(ph);
	assert(ph->val);
	return ph->val[0];
}
bool HeapEmpty(Heap* ph)
{
	assert(ph);
	return ph->size == 0;
}
