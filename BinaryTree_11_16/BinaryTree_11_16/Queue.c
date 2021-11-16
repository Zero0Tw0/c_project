#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void QueueInit(Queue* pq)					//初始
{
	pq->head = pq->tail = NULL;				//队列头尾指针指空
}

void QueuePush(Queue* pq, QueueDataType data)//入队列
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newnode);

	newnode->data = data;
	newnode->next = NULL;

	if (QueueEmpty(pq))						//队列为空		
	{
		pq->tail = pq->head = newnode;
	}
	else									//队列不为空
	{
		QueueNode* tail = pq->tail;
		tail->next = newnode;
		pq->tail = tail->next;
	}
}

void QueuePop(Queue* pq)					//出队列
{
	assert(pq);
	assert(!QueueEmpty(pq));				//判空
	if (pq->head == pq->tail)				//队列只有一个元素
	{
		free(pq->head);
		pq->head = NULL;
		pq->tail = NULL;
	}
	else									//队列不止一个元素
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

QueueDataType QueueFront(Queue* pq)			//队头元素
{
	assert(pq);
	assert(!QueueEmpty(pq));				//判空
	return pq->head->data;					//返回队头元素
}

QueueDataType QueueBack(Queue* pq)			//队尾元素
{
	assert(pq);
	assert(!QueueEmpty(pq));				//判空
	return pq->tail->data;					//返回队尾元素
}

int QueueSize(Queue* pq)
{
	assert(pq);
	if (QueueEmpty(pq))						//队列为空
	{
		return 0;
	}

	QueueNode* cur = pq->head;				//队列不为空			
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

bool QueueEmpty(Queue* pq)					//队列判空
{
	return pq->head == NULL;				//头指针为空队列为空，否则队列不为空
}

void QueueDestroy(Queue* pq)				//队列销毁
{
	assert(pq);
	while (pq->head)						//队列结点释放
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}

	pq->head = pq->tail = NULL;				//队列头尾指针指空
}
