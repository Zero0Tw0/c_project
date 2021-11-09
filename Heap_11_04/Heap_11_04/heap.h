#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HeapDataType;

typedef struct Heap {
	int* val;
	int capacity;
	int size;
}Heap;

void Swap(HeapDataType* a, HeapDataType* b);
void HeapPrint(Heap* ph);
void HeapAdjustDown(Heap* ph, int parent);
void HeapAdjustUp(Heap* ph, int child);
void HeapBuild(Heap* ph);

void HeapInit(Heap* ph, HeapDataType* str, int size);
void HeapDestroy(Heap* ph);
void HeapPush(Heap* ph, HeapDataType x);
void HeapPop(Heap* ph);
void HeapSort(int* a, int n);
HeapDataType HeapTop(Heap* ph);
bool HeapEmpty(Heap* ph);
