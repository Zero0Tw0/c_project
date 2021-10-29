#include"List.h"

ListNode* ListInit()					//双向链表初始化
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	assert(head);
	head->next = head;
	head->prev = head;
}

void ListPrint(ListNode* plist)			//双向链表打印
{
	assert(plist);
	ListNode* cur = plist->next;
	while (cur != plist)				//遍历打印
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(ListNode* plist, ListDataType x)		//双向链表尾插
{
	assert(plist);
	ListNode* tail = plist->prev;
	ListNode* head = plist;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));	//开辟新结点
	assert(newnode);
	newnode->val = x;
	tail->next = newnode;					//尾结点的next指向新结点
	newnode->prev = tail;					//新节点的prev指向尾结点
	newnode->next = head;					//新节点的next指向链表头
	head->prev = newnode;					//表头的prev指向新结点
}

void ListPopBack(ListNode* plist)			//双向链表尾删
{
	assert(plist);
	ListNode* tail = plist->prev;
	assert(plist != tail);
	ListNode* tailprev = tail->prev;
	ListNode* head = plist;
	tailprev->next = plist;					//尾部前一结点的next指向链表头
	head->prev = tailprev;					//表头的prev指向尾部前一结点
	free(tail);
}

void ListPushFront(ListNode* plist, ListDataType x)			//双向链表头插
{
	assert(plist);
	ListNode* head = plist;
	ListNode* headnext = plist->next;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	assert(newnode);
	newnode->val = x;
	head->next = newnode;					//链表头的next指向新节点
	newnode->prev = head;					//新节点的prev指向链表头
	newnode->next = headnext;				//新节点的next指向原来链表头的next
	headnext->prev = newnode;				//原来链表头的prev指向新节点
}

void ListPopFront(ListNode* plist)			//双向链表头删
{
	assert(plist);
	ListNode* head = plist;
	ListNode* headnext = plist->next;
	assert(plist != headnext);
	ListNode* newnext = headnext->next;
	newnext->prev = head;					//链表头的下下结点的prev指向链表头
	head->next = newnext;					//链表头的next指向链表头的下下结点
	free(headnext);
}

ListNode* ListFind(ListNode* plist, ListDataType x)			//双向链表查找
{
	assert(plist);
	ListNode* head = plist;
	ListNode* cur = head->next;
	while (cur != head)						//遍历链表查找val
	{
		if (cur->val == x)
		{
			return cur;						//找到返回所在位置的指针
		}
		cur = cur->next;
	}
	return NULL;							//找不到返回NULL
}

void ListInsert(ListNode* pos, ListDataType x)				//双向链表位插
{
	assert(pos);
	ListNode* posnext = pos->next;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	assert(newnode);
	newnode->val = x;			
	pos->next = newnode;					//插入位置的next指向新结点
	newnode->prev = pos;					//新结点的prev指向插入位置
	newnode->next = posnext;				//新结点的next指向插入位置结点的下一结点
	posnext->prev = newnode;				//插入位置结点的下一结点的prev指向新结点
}

void ListErase(ListNode* pos)				//双向链表位删
{
	assert(pos);
	ListNode* posprev = pos->prev;
	assert(pos != posprev);
	ListNode* posnext = pos->next;
	posprev->next = posnext;				//删除位置的前一结点的next指向删除位置的后一结点
	posnext->prev = posprev;				//删除位置的后一结点的prev指向删除位置的前一结点
	free(pos);
}

void ListDestroy(ListNode* plist)				//双向链表销毁
{
	assert(plist);
	ListNode* head = plist;
	ListNode* cur = head->next;
	while (cur != head)							//遍历销毁每个存储结点
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}	
	free(head);									//销毁哨兵位结点		
}