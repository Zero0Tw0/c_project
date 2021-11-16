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

BTNode* BinaryTreeCreat(BTDataType* a, int size, int* pi);	//二叉树建立
void BinaryTreeDestroy(BTNode* root);						//二叉树销毁
int BinaryTreeSize(BTNode* root);							//二叉树结点个数
int BinaryTreeLeafSize(BTNode* root);						//二叉树叶子结点个数
int BinaryTreeLevelKSize(BTNode* root, int k);				//二叉树第k层结点个数
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);			//二叉树查找
void BinaryTreePrevOrder(BTNode* root);						//前序遍历
void BinaryTreeInOrder(BTNode* root);						//中序遍历
void BinaryTreePostOrder(BTNode* root);						//后序遍历
void BinaryTreeLevelOrder(BTNode* root);					//层序遍历
bool BinaryTreeComplete(BTNode* root);						//完全二叉树检查