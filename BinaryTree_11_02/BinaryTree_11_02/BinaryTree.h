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

BTNode* CreatTreeNode(BTDataType x);				//创建二叉树结点
void PrevOrder(BTNode* root);						//前序遍历
void InOrder(BTNode* root);							//中序遍历
void PostOrder(BTNode* root);						//后序遍历
int TreeSize(BTNode* root);							//结点个数
int BinaryTreeLeafSize(BTNode* root);				//叶结点个数
int BinaryTreeLevelKSize(BTNode* root, int k);		//第k层结点个数
int MaxDepth(BTNode* root);							//二叉树最大深度
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);	//二叉树查找
