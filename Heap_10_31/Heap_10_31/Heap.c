//���

#include"Heap.h"

//�Ѳ���
//
void Swap(HeapDataType* a, HeapDataType* b)			//��������
{
	assert(a);
	assert(b);
	HeapDataType* tmp = *a;						
	*a = *b;
	*b = tmp;
	return;
}

void AdjustDown(Heap* ph, int parent)				//���µ����㷨
{
	assert(ph);
	int	child = parent * 2 + 1;
	while (child < ph->size)
	{
		if (child + 1 < ph->size && ph->data[child + 1] > ph->data[child])	
		{
			child++;		//�ҳ����Һ����д���Ǹ�
		}

		if (ph->data[child] > ph->data[parent])			//���Ӵ��ڸ��׾ͽ���
		{
			Swap(&ph->data[child], &ph->data[parent]);
			parent = child;								//���ӳ�Ϊ����
			child = parent * 2 + 1;						//�����Һ���
		}
		else
		{
			break;										//���Ӳ����ڸ��׽�������
		}
	}
}

void AdjustUp(Heap* ph, int child)					//���ϵ����㷨
{
	assert(ph);
	assert(child < ph->size);
	int parent = (child - 1) / 2;					//�ҳ�����
	while (child > parent)
	{
		if (ph->data[child] > ph->data[parent])		//���Ӵ��ڸ��׽���
		{
			Swap(&ph->data[child], &ph->data[parent]);
			child = parent;							//���׳�Ϊ����
			parent = (child - 1) / 2;				//�����Ҹ���
		}
		else
		{
			break;									//���Ӳ����ڸ��׽�������
		}
	}

}

void BuildHeap(Heap* ph)							//����
{
	assert(ph);
	for (int i = (ph->size - 1 - 1) / 2; i >= 0; i--)	
	{
		AdjustDown(ph, i);							//�����һ��������ǰ����
	}
}


//�ѽӿ�
//
void HeapInit(Heap* ph, HeapDataType* str, int size)	//�ѳ�ʼ
{
	assert(ph);
	assert(str);
	//�������齨�ɶѣ�����ʼ
	HeapDataType* DataSpace;
	DataSpace = (HeapDataType*)malloc(sizeof(HeapDataType) * size);	//���ٸ���������ȿռ�
	assert(DataSpace);
	memcpy(DataSpace, str, size*sizeof(HeapDataType));				//���������ݿ�������
	ph->data = DataSpace;											
	ph->size = size;												//�ѳ�ʼ��С���������С
	ph->capacity = size;

	//����
	BuildHeap(ph);												
}

void HeapPrint(Heap* ph)								//�Ѵ�ӡ
{
	assert(ph);
	for (int i = 0; i < ph->size; i++)
	{
		printf("%d ", ph->data[i]);
	}
	printf("\n");
}
void HeapPush(Heap* ph, HeapDataType x)					//���
{
	assert(ph);
	if (ph->capacity == ph->size)				//�жζ��Ƿ�����
	{
		HeapDataType* newspace;
		newspace = (HeapDataType*)realloc(ph->data, sizeof(HeapDataType) * (ph->size)*2);
		assert(newspace);
		ph->data = newspace;
		ph->capacity = ph->capacity * 2;
	}
	ph->data[ph->size] = x;
	ph->size++;

	AdjustUp(ph,ph->size - 1);					//��������ݷŵ�����󣬽������ϵ���
}

void HeapPop(Heap* ph)									//����
{
	//����ͷ����
	assert(ph);
	Swap(&ph->data[0], &ph->data[ph->size - 1]);		//��ͷβ���ݽ���
	ph->size--;											//�Ѵ�С��1
	AdjustDown(ph, 0);									//��ʣ���������µ���
}

HeapDataType HeapTop(Heap* ph)							//�Ѷ�����
{
	assert(ph);
	assert(ph->data);
	return ph->data[0];
}
int HeapSize(Heap* ph)									//�Ѵ�С
{
	assert(ph);
	return ph->size;
}
bool HeapEmpty(Heap* ph)								//�п�
{
	assert(ph);
	return ph->size == 0;					 
}
void HeapDestroy(Heap* ph)								//������
{
	assert(ph);
	free(ph->data);							//�ͷŶѿռ�
	ph->data = NULL;						//�ѿռ�ָ��ָ��
	ph->size = ph->capacity = 0;			//�Ѵ�С����������
}