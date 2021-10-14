#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

//˳���洢��������
typedef int SeqListDataType;

//˳���ṹ
typedef struct SeqList {
	SeqListDataType* data;
	int size;
	int capacity;
}SeqList;


//�ӿں���
// 
//˳����ʼ��
void SeqListInit(SeqList* ps);

//˳����ӡ
void SeqListPrint(SeqList* ps);

//˳����ڴ���
void CheckCapacity(SeqList* ps);

//˳���ͷ����
void SeqListPushBack(SeqList* ps, SeqListDataType x);
void SeqListPopBack(SeqList* ps);

//˳���β����
void SeqListPushFront(SeqList* ps, SeqListDataType x);
void SeqListPopFront(SeqList* ps);

//˳���ָ��λ�ò���
void SeqListInsert(SeqList* ps, SeqListDataType x, int pos);
void SeqListErase(SeqList* ps, int pos);
int SeqListFind(SeqList* ps, SeqListDataType x);

//˳�������
void SeqListDestroy(SeqList* ps);


