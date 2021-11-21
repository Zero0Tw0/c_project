#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<assert.h>

typedef int StackDataType;

typedef struct Stack
{
	StackDataType* data;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* pst);						//’ª≥ı º
void StackDestroy(Stack* pst);					//’ªœ˙ªŸ
void StackPush(Stack* pst, StackDataType x);	//—π’ª
void StackPop(Stack* pst);						//≥ˆ’ª
StackDataType StackTop(Stack* pst);				//’“’ª∂•
bool StackEmpty(Stack* pst);					//≈–’ªø’
int StackSize(Stack* pst);						//’ª¥Û–°
