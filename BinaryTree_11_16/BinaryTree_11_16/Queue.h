#define _CRT_SECURE_NO_WARNINGS 1

#pragma once						//防止重复包含

#include<stdio.h>					//头文件包含
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>

struct BinaryTreeNode;
typedef struct BinaryTreeNode BTNode;

typedef BTNode* QueueDataType;			//队列数据类型

typedef struct QueueNode {			//队列结点结构
	struct QueueNode* next;
	QueueDataType data;
}QueueNode;

typedef struct Queue {				//队列结构
	QueueNode* head;
	QueueNode* tail;
}Queue;

void QueueInit(Queue* pq);							//初始
void QueuePush(Queue* pq, QueueDataType data);		//入队列
void QueuePop(Queue* pq);							//出队列
QueueDataType QueueFront(Queue* pq);				//队头数据
QueueDataType QueueBack(Queue* pq);					//队尾数据
int QueueSize(Queue* pq);							//队列长度
bool QueueEmpty(Queue* pq);							//队列判空
void QueueDestroy(Queue* pq);						//销毁