#define _CRT_SECURE_NO_WARNINGS 1

#pragma once											//防止重定义

#include<stdio.h>										//头文件
#include<malloc.h>
#include<assert.h>

typedef int ListDataType;								//双向链表存储数据类型

typedef struct ListNode {								//双向不带头循环链表结构
	ListDataType val;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

ListNode* ListInit();									//初始
void ListPrint(ListNode* plist);						//打印
void ListPushBack(ListNode* plist, ListDataType x);		//尾插
void ListPopBack(ListNode* plist);						//尾删
void ListPushFront(ListNode* plist, ListDataType x);	//头插
void ListPopFront(ListNode* plist);						//头删
ListNode* ListFind(ListNode* plist, ListDataType x);	//查找
void ListInsert(ListNode* pos, ListDataType x);			//位插
void ListErase(ListNode* pos);							//位删
void ListDestroy(ListNode* plist);						//销毁



