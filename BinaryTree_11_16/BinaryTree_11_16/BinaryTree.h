#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef char BTDataType;

typedef struct BinaryTreeNode {
	BTDataType val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BinaryTreeCreat(BTDataType* a, int size, int* pi);	//����������
void BinaryTreeDestroy(BTNode* root);						//����������
int BinaryTreeSize(BTNode* root);							//������������
int BinaryTreeLeafSize(BTNode* root);						//������Ҷ�ӽ�����
int BinaryTreeLevelKSize(BTNode* root, int k);				//��������k�������
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);			//����������
void BinaryTreePrevOrder(BTNode* root);						//ǰ�����
void BinaryTreeInOrder(BTNode* root);						//�������
void BinaryTreePostOrder(BTNode* root);						//�������
void BinaryTreeLevelOrder(BTNode* root);					//�������
bool BinaryTreeComplete(BTNode* root);						//��ȫ���������