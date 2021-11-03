#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef char BinaryTreeDataType;
typedef BinaryTreeDataType BTDataType;

typedef struct BTNode {
	BTDataType val;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;

BTNode* CreatTreeNode(BTDataType x);				//�������������
void PrevOrder(BTNode* root);						//ǰ�����
void InOrder(BTNode* root);							//�������
void PostOrder(BTNode* root);						//�������
int TreeSize(BTNode* root);							//������
int BinaryTreeLeafSize(BTNode* root);				//Ҷ������
int BinaryTreeLevelKSize(BTNode* root, int k);		//��k�������
int MaxDepth(BTNode* root);							//������������
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);	//����������
