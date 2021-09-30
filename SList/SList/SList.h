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


void SListPrint(SListNode* plist);								//��ӡ		
void SListPushBack(SListNode** pplist, SListDataType x);		//β��
void SListPushFront(SListNode** pplist, SListDataType x);		//ͷ��
void SListInsert(SListNode** pplist, int pos, SListDataType x);	//��λ����
void SListPopBack(SListNode** pplist);							//βɾ
void SListPopFront(SListNode** pplist);							//ͷɾ
void SListErase(SListNode** plist, int pos);					//λɾ
int SListFind(SListNode* plist, SListDataType x);				//��ֵ����

