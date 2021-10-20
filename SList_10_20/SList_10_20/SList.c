#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

SListNode* BuySListNode(SListDataType x)		//创建新结点
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListPrint(SListNode* plist)				//链表打印
{
	assert(plist);
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

SListNode* SListFind(SListNode* plist, SListDataType find)			//按值查找
{
	assert(plist);
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == find)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsert(SListNode** pplist, SListNode* pos, SListDataType x)		//按位插入
{
	SListNode* PosPrev = *pplist;
	SListNode* NewNode = NULL;

	if (*pplist == pos)
	{
		NewNode = BuySListNode(x);
		assert(NewNode);
		*pplist = NewNode;
		NewNode->next = pos;
		return;
	}

	while (PosPrev->next)
	{
		if (PosPrev->next != pos)
		{
			PosPrev = PosPrev->next;
		}
		else
		{
			NewNode = BuySListNode(x);
			assert(NewNode);
			PosPrev->next = NewNode;
			NewNode->next = pos;
			return;
		}
	}
	printf("找不到插入位置");
}

void SListErase(SListNode** pplist, SListNode* pos)		//按位删除
{
	assert(*pplist);
	assert(pos);
	SListNode* PosPrev = *pplist;
	if (*pplist == pos)
	{
		*pplist = (*pplist)->next;
		free(pos);
		pos = NULL;
		return;
	}
	while (PosPrev)
	{
		if (PosPrev->next != pos)
		{
			PosPrev = PosPrev->next;
		}
		else
		{
			PosPrev->next = pos->next;
			free(pos);
			pos = NULL;
			return;
		}
	}
	printf("找不到删除位置\n");
	return;
}

void SListPushBack(SListNode** pplist, SListDataType x)			//尾插
{
	SListNode* cur = *pplist;
	if (cur == NULL)
	{
		SListNode* NewNode = BuySListNode(x);
		assert(NewNode);
		*pplist = NewNode;
		return;
	}
	while (cur->next)
	{
		cur = cur->next;
	}
	SListNode* NewNode = BuySListNode(x);
	assert(NewNode);
	cur->next = NewNode;
}

void SListPopBack(SListNode** pplist)			//尾删
{
	assert(*pplist);
	SListNode* cur = *pplist;
	SListNode* pos = NULL;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	pos = cur;
	SListErase(pplist, pos);
}

void SListPushFront(SListNode** pplist, SListDataType x)		//头插
{
	SListInsert(pplist, *pplist, x);

}

void SListPopFront(SListNode** pplist)			//头删
{
	SListErase(pplist, *pplist);
}

void SListDestroy(SListNode** pplist)			//销毁
{
	assert(*pplist);
	SListNode* cur = *pplist;
	SListNode* next = NULL;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
}
