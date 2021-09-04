#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define InitSize 10

//SeqList �ṹ������
typedef struct {
	int* data;
	int max_size;
	int length;
}SeqList;

//��ӡ˳���
void print_list(SeqList* L)
{
	int i;
	for (i = 0; i < L->max_size; i++)
	{
		*(L->data + i) = 0;
		printf("%d ", *(L->data + i));
		(L->length)++;
	}
	printf("\n");
}
void print_list2(SeqList* L)
{
	int i;
	for (i = 0; i < L->max_size; i++)
	{
		//*(L->data + i) = 0;
		printf("%d ", *(L->data + i));
	}
	printf("\n");
}


//��ʼ��������˳���
void init_list(SeqList* L)
{
	L->data = (int*)malloc(sizeof(int)*InitSize);
	L->length = 0;
	L->max_size = InitSize;
}

//�ӳ�˳���
void increase_list(SeqList* L,int increase_length)
{
	int i;
	int* p = L->data;
	L -> data = (int*)malloc(sizeof(int) * ((L->max_size)+(increase_length)));
	for (i = 0; i < L->max_size; i++)
	{
		*(L->data + i) = *(p + i);
	}
	L->max_size += increase_length;
	free(p);
}

//��˳����в�������
bool list_insert(SeqList* L, int i, int e)
{
	int j;
	
	if (i<1 || i>L->length)
	{
		printf("�Ƿ�����\n");
		return false;
	}
	else if (i == L->max_size)
	{
		return false;
		printf("�Ѵ���\n");
	}
	
	for (j = L->length; j >= i; j--)
	{
		*(L->data + j) = *(L->data +(j-1));
	}
	*(L->data + i-1) = e;
	L->length++;
	return true;
}

//ɾ������
bool list_delete(SeqList* L,int i, int * e)
{
	int j;
	if (i > L->length || i <1)
	{
		printf("�Ƿ�����\n");
		return false;
	}
	*e = *(L->data + i-1);
	for (j = i; j <= L->length; j++)
	{
		*(L->data + j-1) = *(L->data +j);
	}
	L->length--;


}

int get_elem(SeqList* L, int i)
{
	if (i > L->length)
		printf("�������ҷ�Χ");
	return *(L->data + (i - 1));
}

int locat_elem(SeqList* L, int e)
{
	int i;
	for (i = 0; i < L->length; i++)
	{
		if (*(L->data + i) == e)
			return i+1;
	}
	printf("���޴���");


}


//������
int main()
{
	int i = 0;
	int e = 0;
	int ge = 0;
	int le = 0;
	SeqList L;
	//��ʼ������
	init_list(&L);
	print_list(&L);
	printf("��ǰ˳�����:%d\n", L.length);
	//�ӳ�����
	increase_list(&L,3);
	print_list2(&L);
	printf("��ǰ˳�����:%d\n", L.length);

	//�������
	list_insert(&L, 9, 1);
	print_list2(&L);
	printf("��ǰ˳�����:%d\n", L.length);

	//��λ����
	ge = get_elem(&L, 9);
	printf("�鵽�˸�������Ϊ:% d\n", ge);
	//��ֵ����
	le = locat_elem(&L, 1);
	printf("�鵽�ˣ���ֵλ��:%d\n", le);


	//ɾ������
	list_delete(&L, 9, &e);
	print_list2(&L);
	printf("��ǰ˳�����:%d\n", L.length);
	printf("ɾ������:%d\n", e);


	return 0;
}