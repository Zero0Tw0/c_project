#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//顺序表指定位置操作
void PosTest()
{
	SeqList seqlist;
	SeqListInit(&seqlist);

	//SeqListInsert测试
	printf("SeqListInsert测试:\n");
	SeqListInsert(&seqlist, 2, 0);		
	SeqListInsert(&seqlist, 3, 1);
	SeqListInsert(&seqlist, 1, 0);
	SeqListInsert(&seqlist, 4, 3);
	SeqListInsert(&seqlist, 0, 0);
	SeqListPrint(&seqlist);
	
	//边界条件测试
	printf("边界条件测试:\n");
	SeqListInsert(&seqlist, -1, 0);			//头边界插入测试
	SeqListInsert(&seqlist, -1, 6);			//尾边界插入测试
	SeqListInsert(&seqlist, -1, 2);			//中间插入测试
	SeqListPrint(&seqlist);

	//SeqListFind测试
	printf("SeqListFind测试:\n");
	int pos = SeqListFind(&seqlist, 1);
	printf("pos(1):%d\n", pos);
	pos = SeqListFind(&seqlist, 9);
	printf("pos(9):%d\n", pos);
	pos = SeqListFind(&seqlist, 4);
	printf("pos(4):%d\n", pos);

	//SeqListInsert测试
	printf("SeqListErase测试:\n");
	SeqListErase(&seqlist, 0);				//头边界删除测试
	SeqListErase(&seqlist, 1);				//头边界删除测试
	SeqListErase(&seqlist, 5);				//中间删除测试
	SeqListPrint(&seqlist);

	//测试Pop过量内容
	printf("测试Pop过量内容:\n");			
	SeqListErase(&seqlist, 0);
	SeqListPrint(&seqlist);
	SeqListErase(&seqlist, 0);
	SeqListPrint(&seqlist);
	SeqListErase(&seqlist, 0);
	SeqListPrint(&seqlist);
	SeqListErase(&seqlist, 0);
	SeqListPrint(&seqlist);
	SeqListErase(&seqlist, 0);
	SeqListPrint(&seqlist);
	SeqListErase(&seqlist, 0);				

	//检查Pop过量能否再次写入
	printf("检查Pop过量能否再次写入:\n");			
	SeqListInsert(&seqlist, 0, 0);
	SeqListInsert(&seqlist, 0, 0);			
	SeqListPrint(&seqlist);					

	SeqListDestroy(&seqlist);
}

//顺序表表头操作
void FrontTest()
{
	SeqList seqlist;
	SeqListInit(&seqlist);

	//SeqListPushFront测试
	printf("SeqListPushFront测试:\n");
	SeqListPushFront(&seqlist, 0);
	SeqListPushFront(&seqlist, 1);
	SeqListPushFront(&seqlist, 2);
	SeqListPushFront(&seqlist, 3);
	SeqListPrint(&seqlist);

	//CheckCapacity测试
	printf("CheckCapacity测试:\n");		
	SeqListPushFront(&seqlist, 4);			
	SeqListPrint(&seqlist);

	//SeqListPopFront测试
	printf("SeqListPopFront测试:\n");	
	SeqListPopFront(&seqlist);
	SeqListPrint(&seqlist);
	SeqListPopFront(&seqlist);
	SeqListPrint(&seqlist);
	SeqListPopFront(&seqlist);
	SeqListPrint(&seqlist);
	SeqListPopFront(&seqlist);
	SeqListPrint(&seqlist);
	SeqListPopFront(&seqlist);
	SeqListPrint(&seqlist);

	//测试Pop过量内容
	printf("测试Pop过量内容:\n");			
	SeqListPopFront(&seqlist);
	SeqListPrint(&seqlist);

	//检查Pop过量能否再次写入
	printf("检查Pop过量能否再次写入:\n");			
	SeqListPushFront(&seqlist, 5);
	SeqListPushFront(&seqlist, 6);			
	SeqListPrint(&seqlist);


	SeqListDestroy(&seqlist);
}


//顺序表尾操作
void BackTest()	
{
	SeqList seqlist;
	
	SeqListInit(&seqlist);
	
	//SeqListPushBack测试
	printf("SeqListPushBack测试:\n");
	SeqListPushBack(&seqlist, 0);
	SeqListPushBack(&seqlist, 1);
	SeqListPushBack(&seqlist, 2);
	SeqListPushBack(&seqlist, 3);
	SeqListPrint(&seqlist);

	//CheckCapacity测试
	printf("CheckCapacity测试:\n");	
	SeqListPushBack(&seqlist, 4);			
	SeqListPrint(&seqlist);

	//SeqListPopBack测试
	printf("SeqListPopBack测试:\n");
	SeqListPopBack(&seqlist);			
	SeqListPrint(&seqlist);
	SeqListPopBack(&seqlist);
	SeqListPrint(&seqlist);
	SeqListPopBack(&seqlist);
	SeqListPrint(&seqlist);
	SeqListPopBack(&seqlist);
	SeqListPrint(&seqlist);
	SeqListPopBack(&seqlist);
	SeqListPrint(&seqlist);

	//测试Pop过量内容
	printf("测试Pop过量内容:\n");			
	SeqListPopBack(&seqlist);				
	SeqListPrint(&seqlist);					
	SeqListPopBack(&seqlist);				
	SeqListPrint(&seqlist);

	//检查Pop过量能否再次写入	
	printf("检查Pop过量能否再次写入:\n");	
	SeqListPushBack(&seqlist, 5);
	SeqListPushBack(&seqlist, 6);			
	SeqListPrint(&seqlist);


	SeqListDestroy(&seqlist);
	

}

int main()
{
	//FrontTest();		//顺序表表头操作
	//BackTest();			//顺序表表尾操作
	PosTest();			//顺序表指定位置操作
	return 0;
}