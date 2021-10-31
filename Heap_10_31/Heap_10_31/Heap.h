#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include"stdio.h"
#include"stdlib.h"
#include"assert.h"
#include"stdbool.h"

//大堆

typedef int HeapDataType;

typedef struct Heap {
	HeapDataType* data;
	int size;
	int capacity;
}Heap;

//堆操作
void Swap(HeapDataType* a, HeapDataType* b);
void AdjustUp(HeapDataType* Heap, int parent);
void AdjustDown(Heap* ph);
void BuildHeap(HeapDataType* Heap, int size);


//堆接口
void HeapInit(Heap* ph, HeapDataType* str, int size);	//堆初始
void HeapPrint(Heap* ph);								//堆打印
void HeapPush(Heap* ph,HeapDataType x);					//入堆
void HeapPop(Heap* ph);									//出堆
HeapDataType HeapTop(Heap* ph);							//堆顶数据
int HeapSize(Heap* ph);									//堆大小
bool HeapEmpty(Heap* ph);								//判空
void HeapDestroy(Heap* ph);								//堆销毁
