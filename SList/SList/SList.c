#include"SList.h"



void SListPrint(SListNode* plist)			//�����ӡ(�Լ�ʵ��)
{
	while (plist != NULL)
	{
		printf("%d ", plist->data);
		plist = plist->next;
	}
	printf("\n");
}
//void SListPrint(SListNode* plist)			//�����ӡ(��׼ʵ��)
//{											//�ɶ��Ը�ǿ
//	SListNode* cur = plist;
//	while (cur != NULL)
//	{
//		printf("%d ", cur->data);
//		cur = cur->next;
//	}
//	printf("\n");
//}



SListNode* BuySListNode(SListDataType x)	//�����½��
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)					
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}



//�������
void SListPushBack(SListNode** pplist, SListDataType x)		//β��
{
	SListNode* newnode = BuySListNode(x);

	if (*pplist == NULL)						//������Ϊ��
	{
		*pplist = BuySListNode(x);				//ֱ�Ӵ����½ڵ㣬plistָ���½��
	}
	else
	{
		SListNode* backnode = *pplist;	
		while (backnode->next != NULL)
		{
			backnode = backnode->next;			//����Ϊ����β���
		}
		backnode->next = newnode;				//��β�������½��
	}
}

void SListPushFront(SListNode** pplist, SListDataType x)	//ͷ��
{
	SListNode* newnode = BuySListNode(x);	//�����½��
	newnode->next = *pplist;				//�½ڵ�ָ��ͷָ��
	*pplist = newnode;						//ͷָ��ָ���½ڵ�
}

void SListInsert(SListNode** pplist, int pos, SListDataType x)	//��λ����
{
	SListNode* cur = *pplist;
	SListNode* pre = NULL;
	SListNode* newnode;
	int i = 0;

	//�������1������λ�ò���(����Ϊ��)
	//�������2������λ�ò���(����Ϊ��)

	if (pos == 0)
	{
		newnode = BuySListNode(x);
		*pplist = newnode;
		newnode->next = cur;
		//printf("����λ�ò���\n");					//������
		return;
	}
	
	while (cur != NULL)
	{
		//�������3���ڳ���λ�ü�ĩλ�ò���
		if (pos == i)
		{
			newnode = BuySListNode(x);
			pre->next = newnode;
			newnode->next = cur;
			//printf("�ڳ���λ�ü�ĩλ�ò���\n");	//������
			return;
		}
		pre = cur;
		cur = cur->next;
		i++;
	}
	//�������4����ĩλ�ò���
	if (pos == i)
	{
		newnode = BuySListNode(x);
		pre->next = newnode;
		newnode->next = cur;
		//printf("��ĩλ�ò���\n");					//������
	}
	//�������5�������ɲ��뷶Χ
	else
	{
		printf("�����ɲ��뷶Χ\n");					//������ʾ
		return;
	}
}



//����ɾ��
void SListPopBack(SListNode** pplist)		//βɾ
{
	SListNode* pre = NULL;
	SListNode* backnode = *pplist;

	//�������1��������Ϊ��
	if (backnode == NULL)
	{	
		//printf("����Ϊ��\n");				//������
		return;
	}

	//�������2��������ֻ��һ��Ԫ��
	else if (backnode->next == NULL)
	{
		//printf("����ֻ��һ�����\n");		//������
		free(*pplist);
		*pplist = NULL;
	}

	//�������
	else
	{
		while (backnode->next != NULL)		//��β
		{
			pre = backnode;
			backnode = backnode->next;
		}

		free(backnode);						//�ͷŽ��
		backnode = NULL;

		pre->next = NULL;					//��һ����nextָ��NULL
	}
}

void SListPopFront(SListNode** pplist)		//ͷɾ
{
	SListNode* frontnode = *pplist;
	*pplist = frontnode->next;
	free(frontnode);
	frontnode = NULL;
}

void SListErase(SListNode** pplist, int pos)					//λɾ
{
	SListNode* cur = *pplist;
	SListNode* pre = NULL;
	int i = 0;

	//�������1:������Ϊ��
	if (cur == NULL)
	{
		printf("����Ϊ��\n");
		return;
	}

	//�������2������λ��ɾ��
	else if (pos == 0)
	{
		*pplist = cur->next;
		free(cur);
		cur = NULL;
		printf("��λ��ɾ��\n");
		return;
	}

	//�������3���м���ĩλ��ɾ��
	while (cur != NULL)
	{	
		if (pos == i)
		{
			pre->next = cur->next;
			free(cur);
			cur = NULL;
			printf("������Ϊ��ɾ��\n");
			return;
		}
		pre = cur;
		cur = cur->next;
		i++;
	}

	//�������4��������ɾ����Χ
	printf("������ɾ��λ��\n");
	return;
}



//�������
int SListFind(SListNode* plist, SListDataType x)	//��ֵ����
{
	int pos = 0;
	while (plist != NULL)
	{
		if (plist->data == x)							
			return pos;								//�ҵ�����ֵ����λ��
		else
		{
			pos++;
			plist = plist->next;					//û�ҵ�ֵ��������һλ��
		}
	}
	return - 1;										//û�ҵ���ֵ����-1
}







