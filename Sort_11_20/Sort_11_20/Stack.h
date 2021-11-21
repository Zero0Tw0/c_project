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

void StackInit(Stack* pst);						//ջ��ʼ
void StackDestroy(Stack* pst);					//ջ����
void StackPush(Stack* pst, StackDataType x);	//ѹջ
void StackPop(Stack* pst);						//��ջ
StackDataType StackTop(Stack* pst);				//��ջ��
bool StackEmpty(Stack* pst);					//��ջ��
int StackSize(Stack* pst);						//ջ��С
