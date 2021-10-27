#include"List.h"

void test2()
{
	ListNode* list;
	list = ListInit();				//双向链表初始化

	ListInsert(list, 1);			//双向链表插入
	ListInsert(list, 2);
	ListInsert(list, 3);
	ListInsert(list, 4);
	ListPrint(list);				

	ListNode* pos = ListFind(list, 2);		//双向链表查找和删除
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

	//ListErase(list);			//过量删除测试
	ListDestroy(list);			//双向链表销毁
}

void test1()
{
	ListNode* list;
	list = ListInit();			//双向链表初始化

	ListPushBack(list, 0);		//双向链表尾插
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	ListPrint(list);

	ListPopBack(list);			//双向链表尾删
	ListPrint(list);
	ListPopBack(list);
	ListPrint(list);
	ListPopBack(list);
	ListPrint(list);
	ListPopBack(list);
	ListPrint(list);
	//ListPopBack(list);		//过量删除报错

	ListPushFront(list, 1);		//双向链表头插
	ListPushFront(list, 2);
	ListPushFront(list, 3);
	ListPushFront(list, 4);
	ListPrint(list);

	ListPopFront(list);			//双向链表头删
	ListPrint(list);
	ListPopFront(list);
	ListPrint(list);
	ListPopFront(list);
	ListPrint(list);
	ListPopFront(list);
	ListPrint(list);
	//ListPopFront(list);		//过量删除报错

	ListDestroy(list);			//双向链表销毁
}

int main()
{
	test1();
	test2();
	return 0;
}