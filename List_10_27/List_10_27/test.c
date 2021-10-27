#include"List.h"

void test2()
{
	ListNode* list;
	list = ListInit();				//˫�������ʼ��

	ListInsert(list, 1);			//˫���������
	ListInsert(list, 2);
	ListInsert(list, 3);
	ListInsert(list, 4);
	ListPrint(list);				

	ListNode* pos = ListFind(list, 2);		//˫��������Һ�ɾ��
	ListErase(pos);
	ListPrint(list);

	pos = ListFind(list, 1);
	ListErase(pos);
	ListPrint(list);
	
	pos = ListFind(list, 4);
	ListErase(pos);
	ListPrint(list);

	pos = ListFind(list, 3);
	ListErase(pos);
	ListPrint(list);

	//ListErase(list);			//����ɾ������
	ListDestroy(list);			//˫����������
}

void test1()
{
	ListNode* list;
	list = ListInit();			//˫�������ʼ��

	ListPushBack(list, 0);		//˫������β��
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	ListPrint(list);

	ListPopBack(list);			//˫������βɾ
	ListPrint(list);
	ListPopBack(list);
	ListPrint(list);
	ListPopBack(list);
	ListPrint(list);
	ListPopBack(list);
	ListPrint(list);
	//ListPopBack(list);		//����ɾ������

	ListPushFront(list, 1);		//˫������ͷ��
	ListPushFront(list, 2);
	ListPushFront(list, 3);
	ListPushFront(list, 4);
	ListPrint(list);

	ListPopFront(list);			//˫������ͷɾ
	ListPrint(list);
	ListPopFront(list);
	ListPrint(list);
	ListPopFront(list);
	ListPrint(list);
	ListPopFront(list);
	ListPrint(list);
	//ListPopFront(list);		//����ɾ������

	ListDestroy(list);			//˫����������
}

int main()
{
	test1();
	test2();
	return 0;
}