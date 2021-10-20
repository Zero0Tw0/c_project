#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef int SListDataType;

typedef struct SListNode {
	SListDataType data;
	struct SListNode* next;

}SListNode;

void SListPrint(SListDataType* plist);

void SListPushBack(SListNode** pplist, SListDataType x);
void SListPopBack(SListNode** pplist);

void SListPushFront(SListNode** pplist, SListDataType x);
void SListPopFront(SListNode** pplist);

void SListInsert(SListNode** pplist, SListNode* pos, SListDataType x);
void SListErase(SListNode** pplist, SListNode* pos);

void SListDestroy(SListNode** pplist);
SListNode* SListFind(SListNode* phead, SListDataType x);