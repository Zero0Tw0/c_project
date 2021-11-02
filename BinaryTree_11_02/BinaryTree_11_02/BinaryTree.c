#include"BinaryTree.h"

BTNode* CreatTreeNode(BTDataType x)					//创建二叉树结点
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	assert(newnode);
	newnode->val = x;
	newnode->left = NULL;
	newnode->right = NULL;
}

void PrevOrder(BTNode* root)						//前序遍历
{
	if (root == NULL)				//遇到结点为NULL返回
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->val);		//打印根数据
	PrevOrder(root->left);			//令左孩子为根进行前序遍历
	PrevOrder(root->right);			//令右孩子为根进行前序遍历
}

void InOrder(BTNode* root)							//中序遍历
{
	if (root == NULL)				//遇到结点为NULL返回
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);			//打印根数据
	printf("%c ", root->val);		//令左孩子为根进行中序遍历
	InOrder(root->right);			//令右孩子为根进行中序遍历
}

void PostOrder(BTNode* root)						//后序遍历
{
	if (root == NULL)				//遇到结点为NULL返回
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);			//令左孩子为根进行后序遍历	
	PostOrder(root->right);			//令右孩子为根进行后序遍历
	printf("%c ", root->val);		//打印根数据
}

int TreeSize(BTNode* root)							//结点个数
{
	if (root == NULL)
	{
		return 0;
	}

	return TreeSize(root->left) + TreeSize(root->right) + 1;

	//优化
	//return root == NULL ? 0 : TreeSize(root->left)+TreeSize(root->right)+1;

}

int BinaryTreeLeafSize(BTNode* root);				//叶结点个数
int BinaryTreeLevelKSize(BTNode* root, int k);		//第k层结点个数
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);	//二叉树查找