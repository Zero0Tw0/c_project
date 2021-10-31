#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include"stdio.h"
#include"stdlib.h"
#include"assert.h"
#include"stdbool.h"

//���

typedef int HeapDataType;

typedef struct Heap {
	HeapDataType* data;
	int size;
	int capacity;
}Heap;

//�Ѳ���
void Swap(HeapDataType* a, HeapDataType* b);
void AdjustUp(HeapDataType* Heap, int parent);
void AdjustDown(Heap* ph);
void BuildHeap(HeapDataType* Heap, int size);


//�ѽӿ�
void HeapInit(Heap* ph, HeapDataType* str, int size);	//�ѳ�ʼ
void HeapPrint(Heap* ph);								//�Ѵ�ӡ
void HeapPush(Heap* ph,HeapDataType x);					//���
void HeapPop(Heap* ph);									//����
HeapDataType HeapTop(Heap* ph);							//�Ѷ�����
int HeapSize(Heap* ph);									//�Ѵ�С
bool HeapEmpty(Heap* ph);								//�п�
void HeapDestroy(Heap* ph);								//������
