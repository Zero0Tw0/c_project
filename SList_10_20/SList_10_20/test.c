#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void test3()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

}

void test2()
{
	SListNode* pos;
	SListNode* plist = NULL;
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 1);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);

	SListDestroy(&plist);

}

void test1()
{
	SListNode* pos;
	SListNode* plist = NULL;

	SListInsert(&plist, plist, 4);
	SListInsert(&plist, plist, 3);
	SListInsert(&plist, plist, 2);
	SListInsert(&plist, plist, 1);

	pos = SListFind(plist, 3);
	SListInsert(&plist, pos, 0);
	SListPrint(plist);

	pos = SListFind(plist, 0);
	SListErase(&plist, pos);
	SListPrint(plist);

	pos = SListFind(plist, 4);
	SListErase(&plist, pos);
	SListPrint(plist);

	SListErase(&plist, plist);
	SListErase(&plist, plist);
	SListErase(&plist, plist);
	
	SListPrint(plist);
	
	SListDestroy(&plist);

}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}
