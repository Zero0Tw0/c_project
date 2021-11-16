#define _CRT_SECURE_NO_WARNINGS 1

#pragma once						//��ֹ�ظ�����

#include<stdio.h>					//ͷ�ļ�����
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>

struct BinaryTreeNode;
typedef struct BinaryTreeNode BTNode;

typedef BTNode* QueueDataType;			//������������

typedef struct QueueNode {			//���н��ṹ
	struct QueueNode* next;
	QueueDataType data;
}QueueNode;

typedef struct Queue {				//���нṹ
	QueueNode* head;
	QueueNode* tail;
}Queue;

void QueueInit(Queue* pq);							//��ʼ
void QueuePush(Queue* pq, QueueDataType data);		//�����
void QueuePop(Queue* pq);							//������
QueueDataType QueueFront(Queue* pq);				//��ͷ����
QueueDataType QueueBack(Queue* pq);					//��β����
int QueueSize(Queue* pq);							//���г���
bool QueueEmpty(Queue* pq);							//�����п�
void QueueDestroy(Queue* pq);						//����