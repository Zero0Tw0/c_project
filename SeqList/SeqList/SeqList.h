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

void SeqListInit(SeqList* ps);							//˳����ʼ	-- ʵ��
void SeqListDestory(SeqList* ps);						//˳�������	-- ʵ��	
void SeqListPrint(SeqList* ps);							//˳����ӡ	-- ʵ��
void SeqListPushFront(SeqList* ps, SLDataType x);		//˳���ͷ��	-- ʵ��
void SeqListPushBack(SeqList* ps, SLDataType x);		//˳���β��	-- ʵ��
void SeqListPopFront(SeqList* ps);						//˳���ͷɾ	-- ʵ��
void SeqListPopBack(SeqList* ps);						//˳���ͷɾ	-- ʵ��
void SeqListInsert(SeqList* ps, int pos, SLDataType x); //˳���λ��	-- ʵ��
void SeqListErase(SeqList* ps, int pos);				//˳���λɾ	-- ʵ��
void CheckSeqList(SeqList* ps);							//��������	-- ʵ��
int SeqListFind(const SeqList* ps, SLDataType x);		//˳������	-- ʵ��

