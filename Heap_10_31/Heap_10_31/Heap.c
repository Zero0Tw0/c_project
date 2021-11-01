//大堆

#include"Heap.h"

//堆操作
//
void Swap(HeapDataType* a, HeapDataType* b)			//交换函数
{
	assert(a);
	assert(b);
	HeapDataType* tmp = *a;						
	*a = *b;
	*b = tmp;
	return;
}

void AdjustDown(Heap* ph, int parent)				//向下调整算法
{
	assert(ph);
	int	child = parent * 2 + 1;
	while (child < ph->size)
	{
		if (child + 1 < ph->size && ph->data[child + 1] > ph->data[child])	
		{
			child++;		//找出左右孩子中大的那个
		}

		if (ph->data[child] > ph->data[parent])			//孩子大于父亲就交换
		{
			Swap(&ph->data[child], &ph->data[parent]);
			parent = child;								//孩子成为父亲
			child = parent * 2 + 1;						//继续找孩子
		}
		else
		{
			break;										//孩子不大于父亲结束调整
		}
	}
}

void AdjustUp(Heap* ph, int child)					//向上调整算法
{
	assert(ph);
	assert(child < ph->size);
	int parent = (child - 1) / 2;					//找出父亲
	while (child > parent)
	{
		if (ph->data[child] > ph->data[parent])		//孩子大于父亲交换
		{
			Swap(&ph->data[child], &ph->data[parent]);
			child = parent;							//父亲成为孩子
			parent = (child - 1) / 2;				//继续找父亲
		}
		else
		{
			break;									//孩子不大于父亲结束调整
		}
	}

}

void BuildHeap(Heap* ph)							//建堆
{
	assert(ph);
	for (int i = (ph->size - 1 - 1) / 2; i >= 0; i--)	
	{
		AdjustDown(ph, i);							//从最后一个父亲想前调整
	}
}


//堆接口
//
void HeapInit(Heap* ph, HeapDataType* str, int size)	//堆初始
{
	assert(ph);
	assert(str);
	//给定数组建成堆，并初始
	HeapDataType* DataSpace;
	DataSpace = (HeapDataType*)malloc(sizeof(HeapDataType) * size);	//开辟给定数组相等空间
	assert(DataSpace);
	memcpy(DataSpace, str, size*sizeof(HeapDataType));				//将数组内容拷贝进堆
	ph->data = DataSpace;											
	ph->size = size;												//堆初始大小等于数组大小
	ph->capacity = size;

	//建堆
	BuildHeap(ph);												
}

void HeapPrint(Heap* ph)								//堆打印
{
	assert(ph);
	for (int i = 0; i < ph->size; i++)
	{
		printf("%d ", ph->data[i]);
	}
	printf("\n");
}
void HeapPush(Heap* ph, HeapDataType x)					//入堆
{
	assert(ph);
	if (ph->capacity == ph->size)				//判段堆是否已满
	{
		HeapDataType* newspace;
		newspace = (HeapDataType*)realloc(ph->data, sizeof(HeapDataType) * (ph->size)*2);
		assert(newspace);
		ph->data = newspace;
		ph->capacity = ph->capacity * 2;
	}
	ph->data[ph->size] = x;
	ph->size++;

	AdjustUp(ph,ph->size - 1);					//将入堆数据放到堆最后，进行向上调整
}

void HeapPop(Heap* ph)									//出堆
{
	//出堆头数据
	assert(ph);
	Swap(&ph->data[0], &ph->data[ph->size - 1]);		//将头尾数据交换
	ph->size--;											//堆大小减1
	AdjustDown(ph, 0);									//堆剩余内容向下调整
}

HeapDataType HeapTop(Heap* ph)							//堆顶数据
{
	assert(ph);
	assert(ph->data);
	return ph->data[0];
}
int HeapSize(Heap* ph)									//堆大小
{
	assert(ph);
	return ph->size;
}
bool HeapEmpty(Heap* ph)								//判空
{
	assert(ph);
	return ph->size == 0;					 
}
void HeapDestroy(Heap* ph)								//堆销毁
{
	assert(ph);
	free(ph->data);							//释放堆空间
	ph->data = NULL;						//堆空间指针指空
	ph->size = ph->capacity = 0;			//堆大小堆容量置零
}