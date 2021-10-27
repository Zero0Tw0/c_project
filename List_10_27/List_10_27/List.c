#include"List.h"

ListNode* ListInit()					//˫�������ʼ��
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	assert(head);
	head->next = head;
	head->prev = head;
}

void ListPrint(ListNode* plist)			//˫�������ӡ
{
	assert(plist);
	ListNode* cur = plist->next;
	while (cur != plist)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(ListNode* plist, ListDataType x)		//˫������β��
{
	assert(plist);
	ListNode* tail = plist->prev;
	ListNode* head = plist;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	assert(newnode);
	newnode->val = x;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = head;
	head->prev = newnode;
}

void ListPopBack(ListNode* plist)			//˫������βɾ
{
	assert(plist);
	ListNode* tail = plist->prev;
	assert(plist != tail);
	ListNode* tailprev = tail->prev;
	ListNode* head = plist;
	tailprev->next = plist;
	head->prev = tailprev;
	free(tail);
	
}

void ListPushFront(ListNode* plist, ListDataType x)			//˫������ͷ��
{
	assert(plist);
	ListNode* head = plist;
	ListNode* headnext = plist->next;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	assert(newnode);
	newnode->val = x;
	head->next = newnode;
	newnode->prev = head;
	newnode->next = headnext;
	headnext->prev = newnode;
}

void ListPopFront(ListNode* plist)				//˫������ͷɾ
{
	assert(plist);
	ListNode* head = plist;
	ListNode* headnext = plist->next;
	assert(plist != headnext);
	ListNode* newnext = headnext->next;
	newnext->prev = head;
	head->next = newnext;
	free(headnext);
	
}

ListNode* ListFind(ListNode* plist, ListDataType x)			//˫���������
{
	assert(plist);
	ListNode* head = plist;
	ListNode* cur = head->next;
	while (cur != head)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, ListDataType x)				//˫������λ��
{
	assert(pos);
	ListNode* posnext = pos->next;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	assert(newnode);
	newnode->val = x;
	pos->next = newnode;
	newnode->prev = pos;
	newnode->next = posnext;
	posnext->prev = newnode;
}

void ListErase(ListNode* pos)				//˫������λɾ
{
	assert(pos);
	ListNode* posprev = pos->prev;
	assert(pos != posprev);
	ListNode* posnext = pos->next;
	posprev->next = posnext;
	posnext->prev = posprev;
	free(pos);

}
void ListDestroy(ListNode* plist)				//˫����������
{
	assert(plist);
	ListNode* head = plist;
	ListNode* cur = head->next;
	while (cur != head)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(head);
}