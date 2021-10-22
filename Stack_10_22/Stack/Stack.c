#include"Stack.h"

void StackInit(Stack* pst)						//Õ»³õÊ¼
{
	StackDataType* tmp = (StackDataType*)malloc(sizeof(StackDataType) * 4);
	assert(tmp);
	pst->data = tmp;
	pst->top = 0;
	pst->capacity = 4;							//Õ»³õÊ¼¿Õ¼äÎª4
}

void StackDestroy(Stack* pst)					//Õ»Ïú»Ù
{
	assert(pst);
	free(pst->data);
	pst->data = NULL;
	pst->top = 0;
	pst->capacity = 0;
}

void StackPush(Stack* pst, StackDataType x)		//Ñ¹Õ»
{
	assert(pst);

	if (pst->capacity == pst->top)				//ÅÐ¶ÏÕ»ÊÇ·ñÒÑÂú
	{
		int new_capacity = pst->capacity * 2;
		StackDataType* new_data;
		new_data = (StackDataType*)realloc(pst->data, new_capacity * sizeof(StackDataType));
		assert(new_data);
		pst->data = new_data;
		pst->capacity = new_capacity;
	}

	pst->data[pst->top] = x;
	pst->top++;
}
void StackPop(Stack* pst)						//³öÕ»
{
	assert(pst);
	assert(pst->data);
	if (pst->top == 0)
		exit(-1);
	pst->top--;
}

StackDataType StackTop(Stack* pst)				//ÕÒÕ»¶¥
{
	assert(pst);
	assert(pst->data);
	return pst->data[pst->top - 1];
}

bool StackEmpty(Stack* pst)						//ÅÐÕ»¿Õ
{
	assert(pst);
	if (pst->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int StackSize(Stack* pst)						//Õ»´óÐ¡
{
	assert(pst);
	assert(pst->data);
	return pst->top;
}