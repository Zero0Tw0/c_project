#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

//顺序表存储内容类型
typedef int SeqListDataType;

//顺序表结构
typedef struct SeqList {
	SeqListDataType* data;
	int size;
	int capacity;
}SeqList;


//接口函数
// 
//顺序表初始化
void SeqListInit(SeqList* ps);

//顺序表打印
void SeqListPrint(SeqList* ps);

//顺序表内存检查
void CheckCapacity(SeqList* ps);

//顺序表头操作
void SeqListPushBack(SeqList* ps, SeqListDataType x);
void SeqListPopBack(SeqList* ps);

//顺序表尾操作
void SeqListPushFront(SeqList* ps, SeqListDataType x);
void SeqListPopFront(SeqList* ps);

//顺序表指定位置操作
void SeqListInsert(SeqList* ps, SeqListDataType x, int pos);
void SeqListErase(SeqList* ps, int pos);
int SeqListFind(SeqList* ps, SeqListDataType x);

//顺序表销毁
void SeqListDestroy(SeqList* ps);


