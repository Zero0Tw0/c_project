#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

typedef int SLDataType;

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct SeqList
{
	SLDataType *a;
	int size;
	int capacity;
}SeqList;

void SeqListInit(SeqList* ps);							//顺序表初始	-- 实现
void SeqListDestory(SeqList* ps);						//顺序表销毁	-- 实现	
void SeqListPrint(SeqList* ps);							//顺序表打印	-- 实现
void SeqListPushFront(SeqList* ps, SLDataType x);		//顺序表头插	-- 实现
void SeqListPushBack(SeqList* ps, SLDataType x);		//顺序表尾插	-- 实现
void SeqListPopFront(SeqList* ps);						//顺序表头删	-- 实现
void SeqListPopBack(SeqList* ps);						//顺序表头删	-- 实现
void SeqListInsert(SeqList* ps, int pos, SLDataType x); //顺序表位插	-- 实现
void SeqListErase(SeqList* ps, int pos);				//顺序表位删	-- 实现
void CheckSeqList(SeqList* ps);							//检查表容量	-- 实现
int SeqListFind(const SeqList* ps, SLDataType x);		//顺序表查找	-- 实现

