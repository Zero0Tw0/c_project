#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

int main()
{
	SeqList seqlist;
	SeqListInit(&seqlist);						//初始化顺序表--通过

	SeqListPushFront(&seqlist, 3);		
	SeqListPushFront(&seqlist, 2);
	SeqListPushFront(&seqlist, 1);
	SeqListPushFront(&seqlist, 0);
	SeqListPrint(&seqlist);						//头插测试--通过

	SeqListPushBack(&seqlist, 4);
	SeqListPushBack(&seqlist, 5);
	SeqListPushBack(&seqlist, 6);
	SeqListPushBack(&seqlist, 7);
	SeqListPrint(&seqlist);						//尾插测试--通过

	SeqListPopFront(&seqlist);
	SeqListPopFront(&seqlist);
	SeqListPrint(&seqlist);						//头删测试--通过

	SeqListPopBack(&seqlist);
	SeqListPopBack(&seqlist);
	SeqListPrint(&seqlist);						//尾插测试--通过

	printf("%d ", SeqListFind(&seqlist, 1));
	printf("%d \n", SeqListFind(&seqlist, 4));	
	SeqListPrint(&seqlist);						//查找测试--通过

	SeqListInsert(&seqlist, 3, 0);
	SeqListInsert(&seqlist, 5, 0);					
	SeqListPrint(&seqlist);						//位插测试--通过		

	SeqListErase(&seqlist, 3);
	SeqListErase(&seqlist, 4);
	SeqListPrint(&seqlist);						//位删测试--通过		

	SeqListDestory(&seqlist);					//销毁顺序表--通过
	return 0;
}
