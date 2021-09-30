#include "SList.h"

void SListTest1()
{
	SListNode* plist = NULL;

	
	SListPopBack(&plist);			//尾删第一种情况测试

	SListPushBack(&plist, 0);
	SListPrint(plist);
	SListPopBack(&plist);			//尾删第二种情况测试

	SListPushFront(&plist, 2);
	SListPushFront(&plist, 1);
	SListPrint(plist);
	SListPopBack(&plist);			//尾删第三种情况测试
	SListPrint(plist);

	SListPushFront(&plist, 0);
	SListPushFront(&plist, -1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);				//头删测试

	return;
}

void SListTest2()					//按值查找测试
{
	SListNode* plist = NULL;
	int pos;
	SListPushBack(&plist, 0);
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPrint(plist);
	pos = SListFind(plist, 1);
	printf("%d ", pos);
	pos = SListFind(plist, 9);
	printf("%d ", pos);
}

void SListTest3()
{
	SListNode* plist = NULL;
	SListInsert(&plist, 0, 5);			//在首位置插入且链表为空测试
	SListPushFront(&plist, 4);
	SListPrint(plist);

	SListInsert(&plist, 0, 3);			//在首位置插入且链表不为空测试
	SListPrint(plist);

	SListPushFront(&plist, 2);			
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 0);
	SListInsert(&plist, 3, 9);			//在除首位置和末位置插入测试
	SListPrint(plist);

	SListInsert(&plist, 7, 9);			//在末位置插入测试
	SListPrint(plist);

	SListInsert(&plist, -1, 9);			//在超出链表的位置插入
	SListInsert(&plist, 10, 9);
	SListPrint(plist);
}

void SListTest4()					//按位删除测试
{
	SListNode* plist = NULL;
	SListErase(&plist, 3);			//链表为空测试
	
	SListInsert(&plist, 0, 4);
	SListPrint(plist);
	SListErase(&plist, 0);			//首位置删除测试
	SListPrint(plist);

	SListInsert(&plist, 0, 0);
	SListInsert(&plist, 0, 1);
	SListInsert(&plist, 0, 2);
	SListInsert(&plist, 0, 3);
	SListPrint(plist);
	SListErase(&plist, 2);			//中间位置删除测试
	SListPrint(plist);

	SListErase(&plist, 2);			//末位置删除测试
	SListPrint(plist);

	SListErase(&plist, 3);			//超出可删除范围测试
	SListPrint(plist);


}


int main()
{
	//SListTest1();
	//SListTest2();
	//SListTest3();
	SListTest4();
	return 0;
}