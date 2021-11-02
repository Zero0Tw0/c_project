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

int BinaryTreeLeafSize(BTNode* root);				//Ҷ������
int BinaryTreeLevelKSize(BTNode* root, int k);		//��k�������
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);	//����������