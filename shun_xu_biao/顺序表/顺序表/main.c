#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define InitSize 10

//SeqList 结构体声明
typedef struct {
	int* data;
	int max_size;
	int length;
}SeqList;

//打印顺序表
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


//初始化，创建顺序表
void init_list(SeqList* L)
{
	L->data = (int*)malloc(sizeof(int)*InitSize);
	L->length = 0;
	L->max_size = InitSize;
}

//加长顺序表
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

//在顺序表中插入数据
bool list_insert(SeqList* L, int i, int e)
{
	int j;
	
	if (i<1 || i>L->length)
	{
		printf("非法输入\n");
		return false;
	}
	else if (i == L->max_size)
	{
		return false;
		printf("已存满\n");
	}
	
	for (j = L->length; j >= i; j--)
	{
		*(L->data + j) = *(L->data +(j-1));
	}
	*(L->data + i-1) = e;
	L->length++;
	return true;
}

//删除数据
bool list_delete(SeqList* L,int i, int * e)
{
	int j;
	if (i > L->length || i <1)
	{
		printf("非法输入\n");
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
		printf("超过查找范围");
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
	printf("查无此项");


}


//主函数
int main()
{
	int i = 0;
	int e = 0;
	int ge = 0;
	int le = 0;
	SeqList L;
	//初始化测试
	init_list(&L);
	print_list(&L);
	printf("当前顺序表长度:%d\n", L.length);
	//加长测试
	increase_list(&L,3);
	print_list2(&L);
	printf("当前顺序表长度:%d\n", L.length);

	//插入测试
	list_insert(&L, 9, 1);
	print_list2(&L);
	printf("当前顺序表长度:%d\n", L.length);

	//按位查找
	ge = get_elem(&L, 9);
	printf("查到了该项内容为:% d\n", ge);
	//按值查找
	le = locat_elem(&L, 1);
	printf("查到了，该值位于:%d\n", le);


	//删除测试
	list_delete(&L, 9, &e);
	print_list2(&L);
	printf("当前顺序表长度:%d\n", L.length);
	printf("删除内容:%d\n", e);


	return 0;
}