#include"BinaryTree.h"
#include"Queue.h"

BTNode* BinaryTreeCreat(BTDataType* src, int size, int* pi)//����������
{
	assert(src);
	assert(size > 0);
	if (src[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	assert(root);
	root->val = src[(*pi)++];
	root->left = BinaryTreeCreat(src,size, pi);
	root->right = BinaryTreeCreat(src,size, pi);
	return root;
}

void BinaryTreeDestroy(BTNode* root)						//����������
{
	if (root == NULL)
		return;
	BinaryTreeDestroy(root->left);
	BinaryTreeDestroy(root->right);
	free(root);
}

int BinaryTreeSize(BTNode* root)							//������������
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)						//������Ҷ�ӽ�����
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)				//��������k�������
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)						//����������
{
	if (root == NULL)
		return NULL;
	if (root->val == x)
		return root;
	BTNode* left = BinaryTreeFind(root->left, x);
	if (left)
		return left;
	BTNode* right = BinaryTreeFind(root->right, x);
	if (right)
		return right;
	return NULL;
}

void BinaryTreePrevOrder(BTNode* root)						//ǰ�����
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->val);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

void BinaryTreeInOrder(BTNode* root)						//�������
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreePrevOrder(root->left);
	printf("%c ", root->val);
	BinaryTreePrevOrder(root->right);
}

void BinaryTreePostOrder(BTNode* root)						//�������
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
	printf("%c ", root->val);
}
void BinaryTreeLevelOrder(BTNode* root)						//�������
{
	
	if (root == NULL)
		return;
	Queue queue;
	QueueInit(&queue);
	QueuePush(&queue, root);

	while(!QueueEmpty(&queue))
	{
		BTNode* top = QueueFront(&queue);
		QueuePop(&queue);
		if(top->left != NULL)
			QueuePush(&queue, top->left);
		if (top->right != NULL)
			QueuePush(&queue, top->right);
		printf("%c ", top->val);
	}
	printf("\n");
	QueueDestroy(&queue);
}

bool BinaryTreeComplete(BTNode* root)						//��ȫ���������
{
	if (root == NULL)
		return true;
	Queue queue;
	QueueInit(&queue);

	QueuePush(&queue, root);
	while (!QueueEmpty(&queue))
	{
		BTNode* top = QueueFront(&queue);
		QueuePop(&queue);

		if (top == NULL)
			break;

		QueuePush(&queue, top->left);
		QueuePush(&queue, top->right);
	}

	while (!QueueEmpty(&queue))
	{
		BTNode* top = QueueFront(&queue);
		QueuePop(&queue);

		if (top != NULL)
		{
			QueueDestroy(&queue);
			return false;

		}
	}
	QueueDestroy(&queue);
	return true;
}