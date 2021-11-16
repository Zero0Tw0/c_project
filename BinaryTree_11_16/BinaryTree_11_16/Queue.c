#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void QueueInit(Queue* pq)					//��ʼ
{
	pq->head = pq->tail = NULL;				//����ͷβָ��ָ��
}

void QueuePush(Queue* pq, QueueDataType data)//�����
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newnode);

	newnode->data = data;
	newnode->next = NULL;

	if (QueueEmpty(pq))						//����Ϊ��		
	{
		pq->tail = pq->head = newnode;
	}
	else									//���в�Ϊ��
	{
		QueueNode* tail = pq->tail;
		tail->next = newnode;
		pq->tail = tail->next;
	}
}

void QueuePop(Queue* pq)					//������
{
	assert(pq);
	assert(!QueueEmpty(pq));				//�п�
	if (pq->head == pq->tail)				//����ֻ��һ��Ԫ��
	{
		free(pq->head);
		pq->head = NULL;
		pq->tail = NULL;
	}
	else									//���в�ֹһ��Ԫ��
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

QueueDataType QueueFront(Queue* pq)			//��ͷԪ��
{
	assert(pq);
	assert(!QueueEmpty(pq));				//�п�
	return pq->head->data;					//���ض�ͷԪ��
}

QueueDataType QueueBack(Queue* pq)			//��βԪ��
{
	assert(pq);
	assert(!QueueEmpty(pq));				//�п�
	return pq->tail->data;					//���ض�βԪ��
}

int QueueSize(Queue* pq)
{
	assert(pq);
	if (QueueEmpty(pq))						//����Ϊ��
	{
		return 0;
	}

	QueueNode* cur = pq->head;				//���в�Ϊ��			
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

bool QueueEmpty(Queue* pq)					//�����п�
{
	return pq->head == NULL;				//ͷָ��Ϊ�ն���Ϊ�գ�������в�Ϊ��
}

void QueueDestroy(Queue* pq)				//��������
{
	assert(pq);
	while (pq->head)						//���н���ͷ�
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}

	pq->head = pq->tail = NULL;				//����ͷβָ��ָ��
}
