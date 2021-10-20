#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

SListNode* BuySListNode(SListDataType x)		//�����½��
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListPrint(SListNode* plist)				//�����ӡ
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

SListNode* SListFind(SListNode* plist, SListDataType find)			//��ֵ����
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

void SListInsert(SListNode** pplist, SListNode* pos, SListDataType x)		//��λ����
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
	printf("�Ҳ�������λ��");
}

void SListErase(SListNode** pplist, SListNode* pos)		//��λɾ��
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
	printf("�Ҳ���ɾ��λ��\n");
	return;
}

void SListPushBack(SListNode** pplist, SListDataType x)			//β��
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

void SListPopBack(SListNode** pplist)			//βɾ
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

void SListPushFront(SListNode** pplist, SListDataType x)		//ͷ��
{
	SListInsert(pplist, *pplist, x);

}

void SListPopFront(SListNode** pplist)			//ͷɾ
{
	SListErase(pplist, *pplist);
}

void SListDestroy(SListNode** pplist)			//����
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
