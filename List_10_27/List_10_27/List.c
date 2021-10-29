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
	while (cur != plist)				//������ӡ
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
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));	//�����½��
	assert(newnode);
	newnode->val = x;
	tail->next = newnode;					//β����nextָ���½��
	newnode->prev = tail;					//�½ڵ��prevָ��β���
	newnode->next = head;					//�½ڵ��nextָ������ͷ
	head->prev = newnode;					//��ͷ��prevָ���½��
}

void ListPopBack(ListNode* plist)			//˫������βɾ
{
	assert(plist);
	ListNode* tail = plist->prev;
	assert(plist != tail);
	ListNode* tailprev = tail->prev;
	ListNode* head = plist;
	tailprev->next = plist;					//β��ǰһ����nextָ������ͷ
	head->prev = tailprev;					//��ͷ��prevָ��β��ǰһ���
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
	head->next = newnode;					//����ͷ��nextָ���½ڵ�
	newnode->prev = head;					//�½ڵ��prevָ������ͷ
	newnode->next = headnext;				//�½ڵ��nextָ��ԭ������ͷ��next
	headnext->prev = newnode;				//ԭ������ͷ��prevָ���½ڵ�
}

void ListPopFront(ListNode* plist)			//˫������ͷɾ
{
	assert(plist);
	ListNode* head = plist;
	ListNode* headnext = plist->next;
	assert(plist != headnext);
	ListNode* newnext = headnext->next;
	newnext->prev = head;					//����ͷ�����½���prevָ������ͷ
	head->next = newnext;					//����ͷ��nextָ������ͷ�����½��
	free(headnext);
}

ListNode* ListFind(ListNode* plist, ListDataType x)			//˫���������
{
	assert(plist);
	ListNode* head = plist;
	ListNode* cur = head->next;
	while (cur != head)						//�����������val
	{
		if (cur->val == x)
		{
			return cur;						//�ҵ���������λ�õ�ָ��
		}
		cur = cur->next;
	}
	return NULL;							//�Ҳ�������NULL
}

void ListInsert(ListNode* pos, ListDataType x)				//˫������λ��
{
	assert(pos);
	ListNode* posnext = pos->next;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	assert(newnode);
	newnode->val = x;			
	pos->next = newnode;					//����λ�õ�nextָ���½��
	newnode->prev = pos;					//�½���prevָ�����λ��
	newnode->next = posnext;				//�½���nextָ�����λ�ý�����һ���
	posnext->prev = newnode;				//����λ�ý�����һ����prevָ���½��
}

void ListErase(ListNode* pos)				//˫������λɾ
{
	assert(pos);
	ListNode* posprev = pos->prev;
	assert(pos != posprev);
	ListNode* posnext = pos->next;
	posprev->next = posnext;				//ɾ��λ�õ�ǰһ����nextָ��ɾ��λ�õĺ�һ���
	posnext->prev = posprev;				//ɾ��λ�õĺ�һ����prevָ��ɾ��λ�õ�ǰһ���
	free(pos);
}

void ListDestroy(ListNode* plist)				//˫����������
{
	assert(plist);
	ListNode* head = plist;
	ListNode* cur = head->next;
	while (cur != head)							//��������ÿ���洢���
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}	
	free(head);									//�����ڱ�λ���		
}