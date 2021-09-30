#include "SList.h"

void SListTest1()
{
	SListNode* plist = NULL;

	
	SListPopBack(&plist);			//βɾ��һ���������

	SListPushBack(&plist, 0);
	SListPrint(plist);
	SListPopBack(&plist);			//βɾ�ڶ����������

	SListPushFront(&plist, 2);
	SListPushFront(&plist, 1);
	SListPrint(plist);
	SListPopBack(&plist);			//βɾ�������������
	SListPrint(plist);

	SListPushFront(&plist, 0);
	SListPushFront(&plist, -1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);				//ͷɾ����

	return;
}

void SListTest2()					//��ֵ���Ҳ���
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
	SListInsert(&plist, 0, 5);			//����λ�ò���������Ϊ�ղ���
	SListPushFront(&plist, 4);
	SListPrint(plist);

	SListInsert(&plist, 0, 3);			//����λ�ò���������Ϊ�ղ���
	SListPrint(plist);

	SListPushFront(&plist, 2);			
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 0);
	SListInsert(&plist, 3, 9);			//�ڳ���λ�ú�ĩλ�ò������
	SListPrint(plist);

	SListInsert(&plist, 7, 9);			//��ĩλ�ò������
	SListPrint(plist);

	SListInsert(&plist, -1, 9);			//�ڳ��������λ�ò���
	SListInsert(&plist, 10, 9);
	SListPrint(plist);
}

void SListTest4()					//��λɾ������
{
	SListNode* plist = NULL;
	SListErase(&plist, 3);			//����Ϊ�ղ���
	
	SListInsert(&plist, 0, 4);
	SListPrint(plist);
	SListErase(&plist, 0);			//��λ��ɾ������
	SListPrint(plist);

	SListInsert(&plist, 0, 0);
	SListInsert(&plist, 0, 1);
	SListInsert(&plist, 0, 2);
	SListInsert(&plist, 0, 3);
	SListPrint(plist);
	SListErase(&plist, 2);			//�м�λ��ɾ������
	SListPrint(plist);

	SListErase(&plist, 2);			//ĩλ��ɾ������
	SListPrint(plist);

	SListErase(&plist, 3);			//������ɾ����Χ����
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