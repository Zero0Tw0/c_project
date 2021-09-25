#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

int main()
{
	SeqList seqlist;
	SeqListInit(&seqlist);						//��ʼ��˳���--ͨ��

	SeqListPushFront(&seqlist, 3);		
	SeqListPushFront(&seqlist, 2);
	SeqListPushFront(&seqlist, 1);
	SeqListPushFront(&seqlist, 0);
	SeqListPrint(&seqlist);						//ͷ�����--ͨ��

	SeqListPushBack(&seqlist, 4);
	SeqListPushBack(&seqlist, 5);
	SeqListPushBack(&seqlist, 6);
	SeqListPushBack(&seqlist, 7);
	SeqListPrint(&seqlist);						//β�����--ͨ��

	SeqListPopFront(&seqlist);
	SeqListPopFront(&seqlist);
	SeqListPrint(&seqlist);						//ͷɾ����--ͨ��

	SeqListPopBack(&seqlist);
	SeqListPopBack(&seqlist);
	SeqListPrint(&seqlist);						//β�����--ͨ��

	printf("%d ", SeqListFind(&seqlist, 1));
	printf("%d \n", SeqListFind(&seqlist, 4));	
	SeqListPrint(&seqlist);						//���Ҳ���--ͨ��

	SeqListInsert(&seqlist, 3, 0);
	SeqListInsert(&seqlist, 5, 0);					
	SeqListPrint(&seqlist);						//λ�����--ͨ��		

	SeqListErase(&seqlist, 3);
	SeqListErase(&seqlist, 4);
	SeqListPrint(&seqlist);						//λɾ����--ͨ��		

	SeqListDestory(&seqlist);					//����˳���--ͨ��
	return 0;
}
