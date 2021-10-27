#define _CRT_SECURE_NO_WARNINGS 1

#pragma once											//��ֹ�ض���

#include<stdio.h>										//ͷ�ļ�
#include<malloc.h>
#include<assert.h>

typedef int ListDataType;								//˫������洢��������

typedef struct ListNode {								//˫�򲻴�ͷѭ������ṹ
	ListDataType val;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

ListNode* ListInit();									//��ʼ
void ListPrint(ListNode* plist);						//��ӡ
void ListPushBack(ListNode* plist, ListDataType x);		//β��
void ListPopBack(ListNode* plist);						//βɾ
void ListPushFront(ListNode* plist, ListDataType x);	//ͷ��
void ListPopFront(ListNode* plist);						//ͷɾ
ListNode* ListFind(ListNode* plist, ListDataType x);	//����
void ListInsert(ListNode* pos, ListDataType x);			//λ��
void ListErase(ListNode* pos);							//λɾ
void ListDestroy(ListNode* plist);						//����



