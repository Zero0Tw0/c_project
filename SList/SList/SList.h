#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SListDataType;


typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;


void SListPrint(SListNode* plist);								//打印		
void SListPushBack(SListNode** pplist, SListDataType x);		//尾插
void SListPushFront(SListNode** pplist, SListDataType x);		//头插
void SListInsert(SListNode** pplist, int pos, SListDataType x);	//按位插入
void SListPopBack(SListNode** pplist);							//尾删
void SListPopFront(SListNode** pplist);							//头删
void SListErase(SListNode** plist, int pos);					//位删
int SListFind(SListNode* plist, SListDataType x);				//按值查找

