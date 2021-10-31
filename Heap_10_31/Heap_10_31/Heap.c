//���

#include"Heap.h"

void Swap(HeapDataType* a, HeapDataType* b)
{
	HeapDataType* tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

void AdjustDown(Heap* ph, int parent)
{
	int	child = parent * 2 + 1;
	while (child < ph->size)
	{
		if (child + 1 < ph->size && ph->data[child + 1] > ph->data[child])
		{
			child++;
		}

		if (ph->data[child] > ph->data[parent])
		{
			Swap(&ph->data[child], &ph->data[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void AdjustUp(Heap* ph, int child)
{
	int parent = (child - 1) / 2;
	while (child > parent)
	{
		if (ph->data[child] > ph->data[parent])
		{
			Swap(&ph->data[child], &ph->data[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}

}

void BuildHeap(Heap* ph)
{
	assert(ph);
	for (int i = (ph->size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(ph, i);
	}
}


void HeapInit(Heap* ph, HeapDataType* str, int size)	//�ѳ�ʼ
{
	HeapDataType* DataSpace;
	DataSpace = (HeapDataType*)malloc(sizeof(HeapDataType) * size);
	assert(DataSpace);
	memcpy(DataSpace, str, size*sizeof(HeapDataType));
	ph->data = DataSpace;
	ph->size = size;
	ph->capacity = size;

	//����
	BuildHeap(ph);
}

void HeapPrint(Heap* ph)								//�Ѵ�ӡ
{
	for (int i = 0; i < ph->size; i++)
	{
		printf("%d ", ph->data[i]);
	}
	printf("\n");
}
void HeapPush(Heap* ph, HeapDataType x)					//���
{
	assert(ph);
	if (ph->capacity == ph->size)
	{
		HeapDataType* newspace;
		newspace = (HeapDataType*)realloc(ph->data, sizeof(HeapDataType) * (ph->size)*2);
		assert(newspace);
		ph->data = newspace;
		ph->capacity = ph->capacity * 2;
	}
	ph->data[ph->size] = x;
	ph->size++;

	AdjustUp(ph,ph->size - 1);
}

void HeapPop(Heap* ph);									//����
HeapDataType HeapTop(Heap* ph);							//�Ѷ�����
int HeapSize(Heap* ph);									//�Ѵ�С
bool HeapEmpty(Heap* ph);								//�п�
void HeapDestroy(Heap* ph)								//������
{
	assert(ph);
	free(ph->data);
	ph->data = NULL;
	ph->size = ph->capacity = 0;
}