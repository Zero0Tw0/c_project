#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//˳���ָ��λ�ò���
void PosTest()
{
	SeqList seqlist;
	SeqListInit(&seqlist);

	//SeqListInsert����
	printf("SeqListInsert����:\n");
	SeqListInsert(&seqlist, 2, 0);		
	SeqListInsert(&seqlist, 3, 1);
	SeqListInsert(&seqlist, 1, 0);
	SeqListInsert(&seqlist, 4, 3);
	SeqListInsert(&seqlist, 0, 0);
	SeqListPrint(&seqlist);
	
	//�߽���������
	printf("�߽���������:\n");
	SeqListInsert(&seqlist, -1, 0);			//ͷ�߽�������
	SeqListInsert(&seqlist, -1, 6);			//β�߽�������
	SeqListInsert(&seqlist, -1, 2);			//�м�������
	SeqListPrint(&seqlist);

	//SeqListFind����
	printf("SeqListFind����:\n");
	int pos = SeqListFind(&seqlist, 1);
	printf("pos(1):%d\n", pos);
	pos = SeqListFind(&seqlist, 9);
	printf("pos(9):%d\n", pos);
	pos = SeqListFind(&seqlist, 4);
	printf("pos(4):%d\n", pos);

	//SeqListInsert����
	printf("SeqListErase����:\n");
	SeqListErase(&seqlist, 0);				//ͷ�߽�ɾ������
	SeqListErase(&seqlist, 1);				//ͷ�߽�ɾ������
	SeqListErase(&seqlist, 5);				//�м�ɾ������
	SeqListPrint(&seqlist);

	//����Pop��������
	printf("����Pop��������:\n");			
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

	//���Pop�����ܷ��ٴ�д��
	printf("���Pop�����ܷ��ٴ�д��:\n");			
	SeqListInsert(&seqlist, 0, 0);
	SeqListInsert(&seqlist, 0, 0);			
	SeqListPrint(&seqlist);					

	SeqListDestroy(&seqlist);
}

//˳����ͷ����
void FrontTest()
{
	SeqList seqlist;
	SeqListInit(&seqlist);

	//SeqListPushFront����
	printf("SeqListPushFront����:\n");
	SeqListPushFront(&seqlist, 0);
	SeqListPushFront(&seqlist, 1);
	SeqListPushFront(&seqlist, 2);
	SeqListPushFront(&seqlist, 3);
	SeqListPrint(&seqlist);

	//CheckCapacity����
	printf("CheckCapacity����:\n");		
	SeqListPushFront(&seqlist, 4);			
	SeqListPrint(&seqlist);

	//SeqListPopFront����
	printf("SeqListPopFront����:\n");	
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

	//����Pop��������
	printf("����Pop��������:\n");			
	SeqListPopFront(&seqlist);
	SeqListPrint(&seqlist);

	//���Pop�����ܷ��ٴ�д��
	printf("���Pop�����ܷ��ٴ�д��:\n");			
	SeqListPushFront(&seqlist, 5);
	SeqListPushFront(&seqlist, 6);			
	SeqListPrint(&seqlist);


	SeqListDestroy(&seqlist);
}


//˳���β����
void BackTest()	
{
	SeqList seqlist;
	
	SeqListInit(&seqlist);
	
	//SeqListPushBack����
	printf("SeqListPushBack����:\n");
	SeqListPushBack(&seqlist, 0);
	SeqListPushBack(&seqlist, 1);
	SeqListPushBack(&seqlist, 2);
	SeqListPushBack(&seqlist, 3);
	SeqListPrint(&seqlist);

	//CheckCapacity����
	printf("CheckCapacity����:\n");	
	SeqListPushBack(&seqlist, 4);			
	SeqListPrint(&seqlist);

	//SeqListPopBack����
	printf("SeqListPopBack����:\n");
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

	//����Pop��������
	printf("����Pop��������:\n");			
	SeqListPopBack(&seqlist);				
	SeqListPrint(&seqlist);					
	SeqListPopBack(&seqlist);				
	SeqListPrint(&seqlist);

	//���Pop�����ܷ��ٴ�д��	
	printf("���Pop�����ܷ��ٴ�д��:\n");	
	SeqListPushBack(&seqlist, 5);
	SeqListPushBack(&seqlist, 6);			
	SeqListPrint(&seqlist);


	SeqListDestroy(&seqlist);
	

}

int main()
{
	//FrontTest();		//˳����ͷ����
	//BackTest();			//˳����β����
	PosTest();			//˳���ָ��λ�ò���
	return 0;
}