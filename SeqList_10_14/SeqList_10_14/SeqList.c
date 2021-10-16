#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->data = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void SeqListDestroy(SeqList* ps)
{
	ps->capacity = 0;
	ps->size = 0;
	free(ps->data);
	ps->data = NULL;
	
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}

void CheckCapacity(SeqList* ps)
{
	assert(ps);

	int new_capacity;
	SeqListDataType* new_data = NULL;

	if (ps->capacity == ps->size)
	{
		(ps->capacity == 0) ? (new_capacity = 4) : (new_capacity = ps->capacity * 2);

		new_data = (SeqListDataType*)realloc(ps->data, new_capacity * sizeof(SeqListDataType));
		
		if (new_data == NULL)
		{
			printf("开辟空间失败\n");
			exit(-1);
		}
		{
			ps->data = new_data;
			ps->capacity = new_capacity;
		}
	}
	
}

void SeqListPushBack(SeqList* ps, SeqListDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->data[ps->size] = x;
	ps->size++;
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	if (ps->size == 0)
	{
		printf("顺序表已空，无法删除\n");
		return;
	}
	else
	{
		ps->size--;
		return;
	}
}

void SeqListPushFront(SeqList* ps, SeqListDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->data[i] = ps->data[i - 1];
		
	}
	ps->data[0] = x;
	ps->size++;
	return;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	if (ps->size == 0)
	{
		printf("顺序表已空，无法删除\n");
		return;
	}

	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->data[i] = ps->data[i+1];
	}
	ps->size--;
	return;
}

void SeqListInsert(SeqList* ps, SeqListDataType x, int pos)
{
	assert(ps);
	if (pos > ps->size || pos < 0)
	{
		printf("非法位置输入\n");
		return;
	}
	CheckCapacity(ps);
	for (int i = ps->size; i > pos; i--)
	{
		ps->data[i] = ps->data[i - 1];
	}
	ps->data[pos] = x;
	ps->size++;
	return;
}

void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	if (pos > ps->size || pos < 0)
	{
		printf("非法位置输入\n");
		return;
	}
	if (ps->size == 0)
	{
		printf("顺序表已空，无法删除\n");
		return;
	}
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->size--;
}

int SeqListFind(SeqList* ps, SeqListDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (x == ps->data[i])
			return i;
	}
	return -1;

}
