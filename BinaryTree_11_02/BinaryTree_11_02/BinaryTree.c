#include"BinaryTree.h"

BTNode* CreatTreeNode(BTDataType x)					//�������������
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	assert(newnode);
	newnode->val = x;
	newnode->left = NULL;
	newnode->right = NULL;
}

void PrevOrder(BTNode* root)						//ǰ�����
{
	if (root == NULL)				//�������ΪNULL����
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->val);		//��ӡ������
	PrevOrder(root->left);			//������Ϊ������ǰ�����
	PrevOrder(root->right);			//���Һ���Ϊ������ǰ�����
}

void InOrder(BTNode* root)							//�������
{
	if (root == NULL)				//�������ΪNULL����
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);			//��ӡ������
	printf("%c ", root->val);		//������Ϊ�������������
	InOrder(root->right);			//���Һ���Ϊ�������������
}

void PostOrder(BTNode* root)						//�������
{
	if (root == NULL)				//�������ΪNULL����
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);			//������Ϊ�����к������	
	PostOrder(root->right);			//���Һ���Ϊ�����к������
	printf("%c ", root->val);		//��ӡ������
}

int TreeSize(BTNode* root)							//������
{
	if (root == NULL)
	{
		return 0;
	}

	return TreeSize(root->left) + TreeSize(root->right) + 1;

	//�Ż�
	//return root == NULL ? 0 : TreeSize(root->left)+TreeSize(root->right)+1;

}

int MaxDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftdepth = MaxDepth(root->left);
	int rightdepth = MaxDepth(root->right);

	return leftdepth > rightdepth ? leftdepth+1 : rightdepth+1;

}

int BinaryTreeLeafSize(BTNode* root)				//Ҷ������
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
int BinaryTreeLevelKSize(BTNode* root, int k)		//��k�������
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)	//����������
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->val == x)
	{
		return root;
	}
	BTNode* left = BinaryTreeFind(root->left, x);
	if (left)
	{
		return left;
	}

	BTNode* right = BinaryTreeFind(root->right, x);
	if (right)
	{
		return right;
	}

	return NULL;

}